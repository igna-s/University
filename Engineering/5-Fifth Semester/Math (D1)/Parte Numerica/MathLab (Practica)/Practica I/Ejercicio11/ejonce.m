% Definir las funciones en los intervalos dados
x1 = linspace(1, 1.2, 100); % Para el primer intervalo [1—x—1,2]
P1 = 3.34 * x1 - 0.66;

x2 = linspace(1.2, 1.4, 100); % Para el segundo intervalo [1,2—x—1,4]
P2 = 3.34 * x2 - 0.73;

x3 = linspace(1.4, 1.6, 100); % Para el tercer intervalo [1,4—x—1,6]
P3 = 0.7 * x3.^2 + 1.37 * x3 + 0.88;

% Graficar las funciones
plot(x1, P1, 'b', 'LineWidth', 2); % Grafica la primera función en azul
hold on; % Mantener la gráfica actual y añadir las siguientes
plot(x2, P2, 'r', 'LineWidth', 2); % Grafica la segunda función en rojo
plot(x3, P3, 'g', 'LineWidth', 2); % Grafica la tercera función en verde

% Añadir etiquetas y título
xlabel('x');
ylabel('P(x)');
title('Gráfica de las funciones por intervalos');
legend('P(x) = 3.34x - 0.66', 'P(x) = 3.34x + 0.73', 'P(x) = 0.7x^2 + 1.37x + 0.88', 'Location', 'northwest');
grid on; % Añade una cuadrícula al gráfico

