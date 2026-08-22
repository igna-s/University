program suma_y_maximo_en_vector_arreglar;

const
    dimF = 8;  {Dimensión física del vector}

type

    vector = array [1..dimF] of LongInt;

    dim = 0..dimF;


{-----------------------------------------------------------------------------
CARGARVECTOR - Carga nros aleatorios entre 0 y 100 en el vector hasta que
llegue el nro 99 o hasta que se complete el vector}
Procedure cargarVector ( var vec: vector; var dimL: dim);
var
   d: integer;
begin
     Randomize;  { Inicializa la secuencia de random a partir de una semilla}
     dimL := 0;
     d:= random(100);
     while (d <> 99)  and ( dimL < dimF ) do begin
           dimL := dimL + 1;
           vec[dimL] := d;
           d:= random(100);
     end;
End;



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
function maximo(v:vector; ini:integer; fin:integer;max:integer):integer;
begin
     if ini>fin then max:=-1
     else begin
       max:=v[ini];
       maximo:=maximo(v,ini+1,fin,max)
    end;
    if max>maximo then maximo:=max
end;
function sumatotal(v:vector; ini:integer; fin:integer):integer;
begin
   if ini=fin then sumatotal:=0
   else
     sumatotal:=sumatotal(v,ini+1,fin);
   sumatotal:=sumatotal + v[ini];
end;

{PROGRAMA PRINCIPAL}
var
   v: vector;
   dimL : dim;

begin

     cargarVector(v,dimL);

     writeln('Nros almacenados: ');
     imprimirVector(v, dimL);
     writeln('el numero maximo del vector es: ',maximo(v,1,diml,-1));
     readln;
     writeln(' Y la suma de todos los numeros del vector es igual a = ',sumatotal(v,1,diml));
     readln;
end.
