x = [0, 1, 2.2, 3.2, 4.2, 5.4, 6.5, 7.7, 8.9] * 1e-4; % Multiplicar por 1e-4 para convertir a unidades correctas
y = [248.75, 497.51, 746.25, 995, 1243.75, 1492.5, 1741.25, 1990, 2238.75];

coef = polyfit(x, y, 1); % Calcula los coeficientes de un polinomio de grado 1
P1 = polyval(coef, x); % Evalúa el polinomio con los coeficientes hallados
plot(x, y, 'o', x, P1, 'g'); % Grafica los datos originales y la línea ajustada en verde
xlabel('X');
ylabel('Y');
title('Ajuste lineal');
legend('Datos originales', 'Ajuste lineal');

