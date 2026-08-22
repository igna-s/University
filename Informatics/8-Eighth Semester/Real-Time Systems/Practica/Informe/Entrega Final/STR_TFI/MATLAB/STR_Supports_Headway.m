% STR_Supports_Headway.m  (MATLAB Online friendly)
% CSV esperado:
% run_id,timestamp,trip_id,bus_id,distance_km,event,aux_km,headway_sec
% scenario opcional (si no está, se agrega por label)

clear; clc;

%% 0) Archivos / labels
files  = ["sim_linea51_mc_supports_OneBase.csv"];
labels = ["S1_bases"];

baseTripSec = 6780.96;

%% 1) Cargar y unificar
Tall = table();

for i = 1:numel(files)
    Ti = readtable(files(i), "TextType","string");

    vars = Ti.Properties.VariableNames;

    if ~ismember("run_id", vars),      Ti.run_id = ones(height(Ti),1); end
    if ~ismember("aux_km", vars),      Ti.aux_km = nan(height(Ti),1);  end
    if ~ismember("headway_sec", vars), Ti.headway_sec = nan(height(Ti),1); end
    if ~ismember("scenario", vars)
        Ti.scenario = repmat(labels(i), height(Ti), 1);
    end

    % Normalizar tipos (clave para joins/findgroups)
    Ti.scenario = strtrim(string(Ti.scenario));
    Ti.bus_id   = strtrim(string(Ti.bus_id));
    Ti.event    = strtrim(string(Ti.event));

    % run_id a número si vino como string
    if ~isnumeric(Ti.run_id)
        Ti.run_id = str2double(string(Ti.run_id));
    end

    Tall = [Tall; Ti]; %#ok<AGROW>
end

T = Tall;

%% 2) timestamp -> tsec/hour
ts = T.timestamp;

if isdatetime(ts)
    hh = hour(ts); mm = minute(ts); ss = second(ts);
else
    ts = strtrim(string(ts));
    parts = split(ts, ":");

    if size(parts,2) < 3
        tmp = strings(numel(ts),3);
        for k = 1:numel(ts)
            p = split(ts(k),":");
            p(end+1:3) = "0";
            tmp(k,:) = p(1:3);
        end
        parts = tmp;
    end

    hh = str2double(parts(:,1));
    mm = str2double(parts(:,2));
    ss = str2double(parts(:,3));
end

T.tsec = hh*3600 + mm*60 + ss;
T.hour = T.tsec / 3600;

%% 3) Marey (opcional)
runToPlot = 1;
scenarioToPlot = labels(1);

S = T(T.run_id == runToPlot & T.scenario == scenarioToPlot, :);
S = sortrows(S, ["bus_id","tsec"]);

figure; hold on;
buses = unique(S.bus_id);
for i = 1:numel(buses)
    Bi = S(S.bus_id == buses(i), :);
    plot(Bi.hour, Bi.distance_km, "-");
end
grid on;
xlabel("Hora decimal"); ylabel("Distancia (km)");
title("Marey | run=" + runToPlot + " | " + scenarioToPlot);
hold off;

%% 4) Resumen por (scenario, run_id, bus_id)
[G, scenKey, runKey, busKey] = findgroups(T.scenario, T.run_id, T.bus_id);

depSec = splitapply(@(t,e) minOrNaN(t(e=="DEPARTURE")), T.tsec, T.event, G);
arrSec = splitapply(@(t,e) minOrNaN(t(e=="ARRIVAL")),   T.tsec, T.event, G);

bdTime = splitapply(@(t,e) minOrNaN(t(e=="BREAKDOWN")),  T.tsec, T.event, G);
bdKm   = splitapply(@(d,t,e) firstBreakKm(d,t,e),        T.distance_km, T.tsec, T.event, G);
bdAux  = splitapply(@(a,t,e) firstBreakAuxKm(a,t,e),     T.aux_km,      T.tsec, T.event, G);

nBD    = splitapply(@(e) sum(e=="BREAKDOWN"), T.event, G);

tripSec = arrSec - depSec;
tripSec(tripSec < 0) = tripSec(tripSec < 0) + 86400;

delaySec = tripSec - baseTripSec;
delayPct = 100 * delaySec / baseTripSec;

dispatchKm = abs(bdKm - bdAux);

% --- FIX CRÍTICO: FORZAR TODO A COLUMNA ---
scenKey    = scenKey(:);
runKey     = runKey(:);
busKey     = busKey(:);
depSec     = depSec(:);
arrSec     = arrSec(:);
tripSec    = tripSec(:);
delaySec   = delaySec(:);
delayPct   = delayPct(:);
bdTime     = bdTime(:);
bdKm       = bdKm(:);
bdAux      = bdAux(:);
dispatchKm = dispatchKm(:);
nBD        = nBD(:);

R = table(scenKey, runKey, busKey, depSec, arrSec, tripSec, delaySec, delayPct, ...
          bdTime, bdKm, bdAux, dispatchKm, nBD, ...
    'VariableNames', {'scenario','run_id','bus_id','depSec','arrSec','tripSec', ...
                      'delaySec','delayPct','breakTimeSec','breakdownKm','auxKm','dispatchKm','nBreakdowns'});

%% 5) Headway desde el CSV (CHECKPOINT y ARRIVAL)
Hcp  = T(T.event=="CHECKPOINT", {'scenario','run_id','bus_id','headway_sec','distance_km','tsec'});
Hcp.Properties.VariableNames = {'scenario','run_id','bus_id','headway_cp_sec','cp_km','cp_tsec'};

Harr = T(T.event=="ARRIVAL", {'scenario','run_id','bus_id','headway_sec','tsec'});
Harr.Properties.VariableNames = {'scenario','run_id','bus_id','headway_arr_sec','arr_tsec'};

R = outerjoin(R, Hcp,  'Keys',{'scenario','run_id','bus_id'}, 'MergeKeys',true);
R = outerjoin(R, Harr, 'Keys',{'scenario','run_id','bus_id'}, 'MergeKeys',true);

%% 6) Plots Monte Carlo
valid = ~isnan(R.breakdownKm) & ~isnan(R.delayPct);

figure;
scatter(R.breakdownKm(valid), R.delayPct(valid), 18, R.dispatchKm(valid), "filled");
grid on;
xlabel("Km al primer BREAKDOWN");
ylabel("Demora (%) vs base");
title("Breakdown vs demora (color = |breakdownKm-auxKm|)");
cb = colorbar; cb.Label.String = "Dispatch distance (km)";

figure;
scatter(R.dispatchKm(valid), R.delayPct(valid), 18, R.nBreakdowns(valid), "filled");
grid on;
xlabel("Distancia de despacho |breakdownKm-auxKm| (km)");
ylabel("Demora (%) vs base");
title("Demora vs distancia de despacho (color = # breakdowns)");
cb = colorbar; cb.Label.String = "# breakdowns";

%% 7) Headway histogramas
hcp = R.headway_cp_sec;
har = R.headway_arr_sec;

hcp = hcp(~isnan(hcp) & hcp > 0);
har = har(~isnan(har) & har > 0);

figure;
histogram(hcp/60);
grid on;
xlabel("Headway en CHECKPOINT (min)");
ylabel("Frecuencia");
title("Distribución headway en checkpoint");

figure;
histogram(har/60);
grid on;
xlabel("Headway en ARRIVAL (min)");
ylabel("Frecuencia");
title("Distribución headway a la llegada");

%% 8) Resumen simple por escenario
[GS, scenK] = findgroups(R.scenario);

meanDelay = splitapply(@(x) mean(x,'omitnan'), R.delayPct, GS);
p95Delay  = splitapply(@(x) prctile(x(~isnan(x)),95), R.delayPct, GS);

meanHcp   = splitapply(@(x) mean(x(x>0),'omitnan'), R.headway_cp_sec, GS);
p95Hcp    = splitapply(@(x) prctile(x(x>0 & ~isnan(x)),95), R.headway_cp_sec, GS);

meanHar   = splitapply(@(x) mean(x(x>0),'omitnan'), R.headway_arr_sec, GS);
p95Har    = splitapply(@(x) prctile(x(x>0 & ~isnan(x)),95), R.headway_arr_sec, GS);

fracBroken = splitapply(@(x) mean(~isnan(x)), R.breakdownKm, GS);

Summary = table(scenK, meanDelay, p95Delay, meanHcp, p95Hcp, meanHar, p95Har, fracBroken, ...
    'VariableNames', {'scenario','meanDelayPct','p95DelayPct','meanHeadwayCP','p95HeadwayCP', ...
                      'meanHeadwayARR','p95HeadwayARR','fracWithBreakdown'});

disp("=== RESUMEN POR ESCENARIO ===");
disp(Summary);

% writetable(R, "bus_summary.csv");
% writetable(Summary, "scenario_summary.csv");

%% ===== Helpers =====
function out = minOrNaN(x)
    if isempty(x), out = NaN; else, out = min(x); end
end

function out = firstBreakKm(d, t, e)
    idx = (e=="BREAKDOWN");
    if ~any(idx), out = NaN; return; end
    tt = t(idx); dd = d(idx);
    [~,j] = min(tt);
    out = dd(j);
end

function out = firstBreakAuxKm(a, t, e)
    idx = (e=="BREAKDOWN");
    if ~any(idx), out = NaN; return; end
    tt = t(idx); aa = a(idx);
    [~,j] = min(tt);
    out = aa(j);
end
