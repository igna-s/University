% Definir la función original f(x)
f = @(x) 2 ./ (1 + x.^2);

% Datos de interpolación
x1 = [-5, 0, 5];
y1 = f(x1);
x2 = [-5, -2.5, 0, 2.5, 5];
y2 = f(x2);
x3 = [-5, -2.5, 0, 2.5, 5];
y3 = f(x3);

% Interpolación en x=4 mediante spline cúbico
valor1 = interp1(x1, y1, 4, 'spline');
valor2 = interp1(x2, y2, 4, 'spline');
valor3 = interp1(x3, y3, 4, 'spline');

% Calcular polinomios de interpolación con spline cúbico
coef1 = spline(x1, [0, y1, 0]);
coef2 = spline(x2, [0, y2, 0]);
coef3 = spline(x3, [0, y3, 0]);
P1 = ppval(coef1, x1); % Evaluar el polinomio en los puntos x1
P2 = ppval(coef2, x2); % Evaluar el polinomio en los puntos x2
P3 = ppval(coef3, x3); % Evaluar el polinomio en los puntos x3

% Graficar los polinomios de interpolación con spline cúbico y la función original
x_values = linspace(-5, 5, 1000);
y_values = f(x_values);

figure;
plot(x_values, y_values, 'k-', 'LineWidth', 2); % Función original
hold on
plot(x1, y1, 'bo', x_values, ppval(coef1, x_values), 'g-'); % Puntos y polinomio 1
plot(x2, y2, 'ro', x_values, ppval(coef2, x_values), 'r-'); % Puntos y polinomio 2
plot(x3, y3, 'mo', x_values, ppval(coef3, x_values), 'b-'); % Puntos y polinomio 3

legend('f(x)', 'Puntos y Polinomio 1', 'Puntos y Polinomio 2', 'Puntos y Polinomio 3');
xlabel('x');
ylabel('f(x)');
title('Polinomios de Interpolación con Spline Cúbico y Función Original');
grid on;

