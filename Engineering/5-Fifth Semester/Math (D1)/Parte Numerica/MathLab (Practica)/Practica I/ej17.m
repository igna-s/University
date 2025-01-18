% Datos
X = [1, 1.8, 2.3, 4.1];
Y = [0.5, 0.9, 1.1, 1.4];

% Transformación de datos
X_log = log(X);
Y_log = log(Y);

% Ajuste de polinomio
degree = 2; % Grado del polinomio
coefficients = polyfit(X_log, Y_log, degree);

% Parámetros del ajuste
a = exp(coefficients(1));
b = exp(coefficients(2));

disp(['Parámetros ajustados: a = ', num2str(a), ', b = ', num2str(b)]);

% Evaluación del polinomio ajustado
x_vals = linspace(min(X_log), max(X_log), 100);
y_vals_log = polyval(coefficients, x_vals);
y_vals = exp(y_vals_log);

% Gráfico de los datos y la curva ajustada
figure;
plot(X, Y, 'o', exp(x_vals), y_vals);
xlabel('X');
ylabel('Y');
title('Ajuste de datos a curva Y = a*x / (b + x)');
legend('Datos', 'Curva ajustada');

