Program imprimir_recursivo_y_minimo_de_lista;
Type
  Lista= ^Nodo;
  Nodo= Record
           Datos: integer;
           Sig: Lista;
        End;


function valorminimo (l:lista;min:integer):integer;

begin
 if not (l=nil) then begin
   min:=l^.datos;
   valorminimo:=valorminimo(l^.sig,min);

 end
 else valorminimo:= 9999;
 if min<valorminimo then valorminimo:=min;
end;
function imprimirrecursivo(l:lista):integer;
begin
     if l<>nil then begin
        write(l^.datos,' ');
        imprimirrecursivo(l^.sig)
     end;
     readln;
end;


Var
 L: Lista;
 n: integer;

Procedure AgregarAdelante (var L:lista; num:integer);
Var nue:Lista;
  Begin
    New(nue);
    nue^.datos:=num;
    nue^.sig:=L;
    L:=nue;
  End;

Procedure Imprimir (pri:lista);
Begin
   while (pri <> NIL) do begin
     write (pri^.datos, ' ');
     pri:= pri^.sig
  end;
  writeln;
end;

begin
 L:=nil;
 randomize;
 n := random (100);
 While (n<>0) do Begin
   AgregarAdelante (L, n);
   n := random (100);
 End;
 writeln ('Lista generada: ');
 imprimir (L);
 writeln('el valor minimo encontrado en la lista es el numero = ',valorminimo(l,1));
 readln;
 imprimirrecursivo(l)
end.
