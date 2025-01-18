% Datos
R = [10.5 5.25 3.5 2.63 2.1 1.75 1.5 1.31 1.17 1.05];
I = [500 1900 3250 4300 5450 6600 8100 9000 9350 9500];

% Graficar los puntos
figure;
plot(R, I, 'o');
xlabel('Recurrencia (R) [años]');
ylabel('Intensidad de lluvia (I) [mm/h]');
title('Intensidad de lluvia en función de la recurrencia');

% Ajuste de curva
% Aquí puedes seleccionar un ajuste adecuado para tus datos, por ejemplo, una curva exponencial:
% Transformación para ajuste exponencial: ln(I) = ln(a) + b * R
ln_I = log(I);
A = [R' ones(length(R), 1)];
coef_exponencial = A\ln_I';
a_exp = exp(coef_exponencial(2));
b_exp = coef_exponencial(1);
fprintf('Coeficientes del ajuste exponencial: a = %f, b = %f\n', a_exp, b_exp);

% Graficar la curva ajustada en coordenadas semi-logarítmicas
x_vals = linspace(min(R), max(R), 100);
y_vals = a_exp * exp(b_exp * x_vals);
figure;
semilogy(R, I, 'o', x_vals, y_vals);
xlabel('Recurrencia (R) [años]');
ylabel('Intensidad de lluvia (I) [mm/h]');
title('Intensidad de lluvia en función de la recurrencia (escala semi-logarítmica)');

% Predicción de la intensidad para una recurrencia de 3 años
recurrencia_deseada = 3;
intensidad_pred = a_exp * exp(b_exp * recurrencia_deseada);
fprintf('La intensidad esperada de la lluvia para una recurrencia de 3 años es: %f mm/h\n', intensidad_pred);

