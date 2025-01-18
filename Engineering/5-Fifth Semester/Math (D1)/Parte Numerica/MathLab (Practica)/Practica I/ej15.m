% Datos
delta_L = [0 3 6 9 12 15 20 20 25 30 35 40 45] * 1e-2; % Convertir a metros
P = [500 1900 3250 4300 5450 6600 8100 9000 9350 9500 9700 9850 10000];

% Graficar los puntos
figure;
plot(delta_L, P, 'o');
xlabel('Alargamiento (\DeltaL) [m]');
ylabel('Carga (P) [kg]');
title('Relación carga-alargamiento');

% Ajuste de curva
% Aquí puedes seleccionar un ajuste adecuado para tus datos, por ejemplo, una curva cuadrática:
% Ajuste polinómico de 2do grado
A = [delta_L'.^2 delta_L' ones(length(delta_L), 1)];
coef_polinomial = A\P';
fprintf('Coeficientes del ajuste polinomial de 2do grado: a = %f, b = %f, c = %f\n', coef_polinomial(1), coef_polinomial(2), coef_polinomial(3));

% Graficar la curva ajustada
x_vals = linspace(min(delta_L), max(delta_L), 100);
y_vals = coef_polinomial(1) * x_vals.^2 + coef_polinomial(2) * x_vals + coef_polinomial(3);
hold on;
plot(x_vals, y_vals, 'r');
legend('Datos', 'Curva ajustada');
hold off;

% Predicción del alargamiento para una carga de 7 toneladas
carga_deseada = 7 * 1000; % Convertir toneladas a kg
deltaL_pred = polyval(coef_polinomial, carga_deseada);
fprintf('El alargamiento correspondiente a una carga de 7 toneladas es: %f m\n', deltaL_pred);

