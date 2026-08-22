program ProgramaVectores;

const
    dimF = 8;  {Dimensi�n f�sica del vector}

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

function suma(v:vector;d:dim;i:dim):LongInt;
begin
 if (i<=d) then
   suma:=v[i]+suma(v,d,i+1)
 else suma:=0;
end;


function mayor(v:vector;d,i:dim;m:LongInt):LongInt;
begin
  if (i<=d) then begin
    if(v[i]>m)then
        m:=mayor(v,d,i+1,v[i])  
    else m:=mayor(v,d,i+1,m); 
    mayor:=m;
  end
  else mayor:=m;
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

{PROGRAMA PRINCIPAL}
var
   v: vector;
   dimL : dim;

begin

     cargarVector(v,dimL);

     writeln('Nros almacenados: ');
     imprimirVector(v, dimL);

     writeln('suma: ',suma(v,dimL,1));
     writeln('mayor: ',mayor(v,dimL,1,0));

     readln;
end.
