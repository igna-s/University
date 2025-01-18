% Datos
X = [0.1 0.2 0.3 0.4 0.5];
Y = [2 2.9 5 6.7 12];



% Ajuste lineal
A = [X' ones(length(X), 1)];
coef_lineal = A\Y';
fprintf('Coeficientes del ajuste lineal: a = %f, b = %f\n', coef_lineal(1), coef_lineal(2));

% Gráfico del ajuste lineal
x_vals = linspace(min(X), max(X), 100);
y_vals = coef_lineal(1) * x_vals + coef_lineal(2);
figure;
subplot(2, 2, 1);
plot(X, Y, 'o', x_vals, y_vals);
xlabel('X');
ylabel('Y');
title('Ajuste lineal');








% Ajuste polinómico de 2do grado
A = [X'.^2 X' ones(length(X), 1)];
coef_polinomial = A\Y';
fprintf('Coeficientes del ajuste polinomial de 2do grado: a = %f, b = %f, c = %f\n', coef_polinomial(1), coef_polinomial(2), coef_polinomial(3));

% Gráfico del ajuste polinomial de 2do grado
y_vals = coef_polinomial(1) * x_vals.^2 + coef_polinomial(2) * x_vals + coef_polinomial(3);
subplot(2, 2, 2);
plot(X, Y, 'o', x_vals, y_vals);
xlabel('X');
ylabel('Y');
title('Ajuste polinomial de 2do grado');







% Transformación para ajuste potencial: ln(Y) = ln(a) + b * ln(X)
ln_X = log(X);
ln_Y = log(Y);

% Ajuste lineal de ln(Y) vs ln(X)
A = [ln_X' ones(length(ln_X), 1)];
coef_potencial = A\ln_Y';
a = exp(coef_potencial(2));
b = coef_potencial(1);
fprintf('Coeficientes del ajuste potencial: a = %f, b = %f\n', a, b);

% Gráfico del ajuste potencial
y_vals = a * x_vals.^b;
subplot(2, 2, 3);
plot(X, Y, 'o', x_vals, exp(y_vals));
xlabel('X');
ylabel('Y');
title('Ajuste potencial');






% Transformación para ajuste exponencial: ln(Y) = ln(a) + b * X
% Ajuste lineal de ln(Y) vs X
A = [X' ones(length(X), 1)];
coef_exponencial = A\ln_Y';
a_exp = exp(coef_exponencial(2));
b_exp = coef_exponencial(1);
fprintf('Coeficientes del ajuste exponencial: a = %f, b = %f\n', a_exp, b_exp);

% Gráfico del ajuste exponencial
y_vals = a_exp * exp(b_exp * x_vals);
subplot(2, 2, 4);
plot(X, Y, 'o', x_vals, y_vals);
xlabel('X');
ylabel('Y');
title('Ajuste exponencial');


