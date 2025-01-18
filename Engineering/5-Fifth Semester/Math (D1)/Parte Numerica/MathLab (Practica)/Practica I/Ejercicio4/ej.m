clearvars

% Datos dados
X = [0.5000, 1.0000, 1.3000, 1.5000, 1.9000];
Y = [3.5636 1.3424 -0.4972 -1.8872 -4.9594];
x_interp = 1.75;

% Calcular el polinomio de Lagrange
n = length(X);
L = ones(1, n);
for i = 1:n
    for j = 1:n
        if j ~= i
            L(i) = L(i) * (x_interp - X(j)) / (X(i) - X(j));
        end
    end
end

% Calcular el valor interpolado
y_interp = sum(Y .* L);

% Calcular el error absoluto
f = @(x) 4*x - exp(x);
actual_value = f(x_interp);
error = abs(actual_value - y_interp);

disp(['El valor interpolado en x = ', num2str(x_interp), ' es ', num2str(y_interp)]);
disp(['El error absoluto de la interpolación es ', num2str(error)]);

% Grafica los puntos y el polinomio interpolante
fplot(f, [0.4, 2], 'DisplayName', 'f(x) = 4x - e^x');
hold on;
scatter(X, Y, 'r', 'filled', 'DisplayName', 'Datos dados');

% Evaluar el polinomio interpolante en un rango de valores de x para graficarlo
x_range = linspace(min(X), max(X), 100);
L_values = zeros(size(x_range));
for i = 1:length(x_range)
    L_i = ones(1, n);
    for j = 1:n
        for k = 1:n
            if k ~= j
                L_i(j) = L_i(j) * (x_range(i) - X(k)) / (X(j) - X(k));
            end
        end
    end
    L_values(i) = sum(Y .* L_i);
end
plot(x_range, L_values, 'g', 'DisplayName', 'Polinomio interpolante');

legend;
xlabel('x');
ylabel('y');
title('Interpolación de puntos dados y comparación con f(x)');
grid on;
hold off;


