clear
x = [1.00 1.25 1.50 1.75 2.00 2.25 2.50];
y = [-4.50 2.48 1.79 -4.47 -6.00 -0.22 14.70];

% (a) Graficar los puntos
plot(x, y, 'o') % Grafica solamente los puntos
grid on % Grafica una grilla
hold on % Mantiene los gráficos anteriores

% (b) Polinomio de interpolación de orden 3
x_values = [1:0.1:2.50]; % Define el vector x entre 1 y 2.50 con intervalos de 0.1

% Coeficientes del polinomio de tercer orden
a3 = ((y(4)-y(3))/(x(4)-x(3)) - (y(3)-y(2))/(x(3)-x(2))) / (x(4)-x(2));
a2 = ((y(3)-y(2))/(x(3)-x(2)) - (y(2)-y(1))/(x(2)-x(1))) / (x(3)-x(1));
a1 = (y(2)-y(1))/(x(2)-x(1)) - a2*(x(1)+x(2)) - a3*x(1)^2;
a0 = y(1) - a1*x(1) - a2*x(1)^2 - a3*x(1)^3;

P3 = a0*x_values.^3 + a1*x_values.^2 + a2*x_values + a3; % Polinomio de tercer orden
plot(x_values, P3, 'r') % Grafica el polinomio en línea roja

% (c) Coeficientes del polinomio utilizando polyfit
coef = polyfit(x, y, 3); % Calcula los coeficientes del polinomio de interpolación de orden 3

% (d) Evaluar el polinomio hallado y graficarlo
P3_polyfit = polyval(coef, x_values); % Evalúa el polinomio con los coeficientes hallados
plot(x_values, P3_polyfit, 'g') % Grafica el polinomio en línea verde
legend('Puntos', 'Interpolación manual', 'Interpolación con polyfit') % Añade leyenda
xlabel('x') % Etiqueta del eje x
ylabel('y') % Etiqueta del eje y
title('Interpolación de polinomios') % Título del gráfico

