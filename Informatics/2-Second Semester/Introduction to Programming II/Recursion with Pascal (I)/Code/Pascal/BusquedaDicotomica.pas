program BusquedaDicotomica;

const
    dimF = 8;  {Dimensión física del vector}

type

    vector = array [1..dimF] of integer;

    dim = 0..dimF;

{-----------------------------------------------------------------------------
CARGARVECTORORDENADO - Carga ordenadamente nros aleatorios entre 0 y 100 en el
vector hasta que llegue el nro 99 o hasta que se complete el vector}

Procedure cargarVectorOrdenado ( var vec: vector; var dimL: dim);
var
   d, pos, j: integer;
begin
    Randomize;  { Inicializa la secuencia de random a partir de una semilla}
    dimL := 0;
    d:= random(100);
    while (d <> 99)  and ( dimL < dimF ) do begin
       pos:= 1;
       while (pos <= dimL) and (vec[pos]< d) do //Acá no ingresa cuando diml es 0!?
          pos:= pos + 1;
       for  j:= dimL downto pos do // de 0 a 1
          vec[j+1]:= vec[j] ;
       vec[pos]:= d;
       dimL := dimL + 1;
       d:= random(100)
     end;
end;

{-----------------------------------------------------------------------------
IMPRIMIRVECTOR - Imprime todos los nros del vector }

Procedure imprimirVector ( var vec: vector; var dimL: dim );
var
   i: dim;
begin
     for i:= 1 to dimL do
         write ('-----');
     writeln;
     write (' ');
     for i:= 1 to dimL do begin
        if(vec[i] < 9)then
            write ('0');
        write(vec[i], ' | ');
     end;
     writeln;
     for i:= 1 to dimL do
         write ('-----');
     writeln;
     writeln;
End;

function busquedadicotomica (v: vector; ini, fin, dato: integer): integer;  //Devuelve la posicion
var
   central: integer;
begin
    if (ini = fin) then begin
        if (dato = v[fin]) then
            busquedadicotomica:= fin
        else
          busquedadicotomica:= 0;
    end
    else begin
      central:= (ini + fin) div 2;
      if (dato = v[central]) then
          busquedadicotomica:= central
      else
        if (dato < v[central]) then
            busquedadicotomica:= busquedadicotomica(v,ini,central-1,dato)
        else
          if (dato > v[central]) then
            busquedadicotomica:= busquedadicotomica(v,central+1,fin,dato);
    end;
end;

{PROGRAMA PRINCIPAL}
var
   v: vector;
   dimL : dim;
   num: integer;
begin

     cargarVectorOrdenado(v,dimL);

     writeln('Nros almacenados: ');
     imprimirVector(v, dimL);
     writeln('Ingrese un numero para buscarlo en el vector: ');
     read(num);
     if (busquedadicotomica(v,1,dimL,num) = 0) then
         writeln('El numero no se encuentra en el vector')
     else
         writeln('EL numero se encuentra en la posicion: ',busquedadicotomica(v,1,dimL,num));
     readln;
     readln;
end.

