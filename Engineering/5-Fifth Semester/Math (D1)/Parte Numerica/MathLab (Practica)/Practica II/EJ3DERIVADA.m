
% Definir la función y su derivada exacta
f = @(x) sin(x);
f_prime_exact = @(x) cos(x);

% Punto de evaluación
x = 0.1;

% Inicializar el valor de h
h = 1;


% Arreglos para almacenar resultados
h_values = zeros(1, 25);
derivative_approximations = zeros(1, 25);
errors = zeros(1, 25);

% Iterar para reducir h y calcular la derivada y el error
for i = 1:25
    % Calcular la derivada aproximada usando diferencia centrada
    derivative_approx = (f(x + h) - f(x - h)) / (2 * h);

    % Calcular el error
    error = abs(derivative_approx - f_prime_exact(x));

    % Almacenar los resultados
    h_values(i) = h;
    derivative_approximations(i) = derivative_approx;
    errors(i) = error;

    % Reducir h a la décima parte
    h = h / 10;
end

% Imprimir los resultados
fprintf('h \t\t Aproximación \t\t Error\n');
for i = 1:num_iterations
    fprintf('%.10f \t %.10f \t %.10f\n', h_values(i), derivative_approximations(i), errors(i));
end

