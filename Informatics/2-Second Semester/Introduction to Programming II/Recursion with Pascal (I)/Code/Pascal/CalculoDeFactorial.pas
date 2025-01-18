program CalculoDeFactorial;

Function factorial(x: integer): real;
begin
  if (x <= 1) then
    factorial:= 1
  else
    factorial := x * factorial(x-1)
end;


{PROGRAMA PRINCIPAL}
var
  num: integer;
Begin

  writeln( 'Ingrese un entero no negativo:');
  readln (num);
  writeln ( num, '! = ', (factorial(num)):2:2);
  readln();
End.

