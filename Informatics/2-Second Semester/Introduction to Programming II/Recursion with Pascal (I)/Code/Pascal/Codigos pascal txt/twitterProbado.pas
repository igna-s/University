Program twitterProbado;
Uses
     sysutils;
Type
     tweet = record
	      codigoUsuario: integer;
	      nombreUsuario: string;
	      mensaje: string;
	      esRetweet: boolean;
     end;

     listaTweets = ^nodoLista;
     nodoLista = record
               dato: tweet;
               sig: listaTweets;
     end;

     {Completar agregando aquí las estructuras de datos necesarias en el ejercicio}

     usuario = record
       nombre: string;
       codigo: integer;
     end;

     tweetN = record
       mensaje: string;
       esRetweet: boolean;
     end;

     ListaN = ^nodoN;  //Sublista de tweets
     nodoN = record
       dato: tweetN;
       sig: ListaN;
     end;

     ListaP = ^nodoP; //Nueva Lista Principal, Lista de listas
     nodoP = record
       dato: usuario;
       tweets: ListaN;
       sig: ListaP;
     end;

{agregarAdelante - Agrega nro adelante de l}
Procedure agregarAdelante(var l: listaTweets; t: tweet);
var
   aux: listaTweets;
begin
     new(aux);
     aux^.dato := t;
     aux^.sig := l;
     l:= aux;
end;



{crearLista - Genera una lista con tweets aleatorios}
procedure crearLista(var l: listaTweets);
var
   t: tweet;
   texto: string;
   v : array [1..10] of string;
begin
     v[1]:= 'juan';
     v[2]:= 'pedro';
     v[3]:= 'carlos';
     v[4]:= 'julia';
     v[5]:= 'mariana';
     v[6]:= 'gonzalo';
     v[7]:='alejandro';
     v[8]:= 'silvana';
     v[9]:= 'federico';
     v[10]:= 'ruth';

     t.codigoUsuario := random(11);
     while (t.codigoUsuario <> 0) do Begin
          texto:= Concat(v[t.codigoUsuario], '-mensaje-', IntToStr(random (200)));
          t.nombreUsuario := v[t.codigoUsuario];
          t.mensaje := texto;
          t.esRetweet := (random(2)=0);
          agregarAdelante(l, t);
          t.codigoUsuario := random(11);
     end;
end;


{imprimir - Muestra en pantalla el tweet}
procedure imprimir(t: tweet);
begin
     with (t) do begin
          write('Tweet del usuario @', nombreUsuario, ' con codigo ',codigoUsuario, ': ', mensaje, ' RT:');
          if(esRetweet)then
               writeln(' Si')
          else
               writeln('No ');
     end;
end;


{imprimirLista - Muestra en pantalla la lista l}
procedure imprimirLista(l: listaTweets);
begin
     while (l <> nil) do begin
          imprimir(l^.dato);
          l:= l^.sig;
     end;
end;


{agregarElemento - Resuelve la inserción de la estructura ordenada}
procedure agregarOrdenado(var pri:listaTweets; t:tweet);
var
   nuevo, anterior, actual: listaTweets;
begin
     new (nuevo);
     nuevo^.dato:= t;
     nuevo^.sig := nil;
     if (pri = nil) then
          pri := nuevo
     else
     begin
          actual := pri;
          anterior := pri;
          while (actual<>nil) and (actual^.dato.nombreUsuario < nuevo^.dato .nombreUsuario) do begin
               anterior := actual;
               actual:= actual^.sig;
          end;
          if (anterior = actual) then
               pri := nuevo
          else
               anterior^.sig := nuevo;
          nuevo^.sig := actual;
     end;
end;


{generarNuevaEstructura - Resuelve la generación estructura ordenada}
procedure generarNuevaEstructura (lT: listaTweets; VAR listaOrdenada: listaTweets);
begin
     listaOrdenada := nil;
     while(lT <> nil) do begin
          agregarOrdenado(listaOrdenada, lT^.dato);
          lT := lT^.sig;
     end;
end;


procedure InsertarAdelanteTweet(var l: ListaN; t: tweetN);
var
  nue: ListaN;
begin
  new(nue);
  nue^.dato:= t;
  nue^.sig:= l;
  l:= nue;
end;

procedure InsertarAlFinal(var LP: ListaP; LN: ListaN; u: usuario);
var
  nue, ant, act: ListaP;
begin
  new(nue);
  nue^.dato:= u;
  nue^.tweets:= LN;
  nue^.sig:= nil;
  if (LP = nil) then begin
    LP:= nue;
  end
  else begin
    ant:= LP; act:= LP;
    while (act <> nil) do begin
      ant:= act;
      act:= act^.sig;
    end;
    ant^.sig:= nue;
  end;
end;

procedure crearListadeListas (l: listaTweets; var LP: ListaP);
var
  actualUsuario: string;
  u: usuario;
  t: tweetN;
  LN: ListaN;
begin
  while (l <> nil) do begin
    actualUsuario:= l^.dato.nombreUsuario;
    u.nombre:= actualUsuario;
    u.codigo:= l^.dato.codigoUsuario;
    LN:= nil;
    while (l <> nil) and (actualUsuario = l^.dato.nombreUsuario) do begin
      t.mensaje:= l^.dato.mensaje;
      t.esRetweet:= l^.dato.esRetweet;
      InsertarAdelanteTweet(LN,t);
      l:= l^.sig;
    end;
    InsertarAlFinal(LP,LN,u);
  end;
end;


var
   l, l_ordenada: listaTweets;
   LP: ListaP; //Lista de dos punteros
begin
     Randomize;

     l:= nil;
     crearLista(l);
     writeln ('Lista generada: ');
     imprimirLista(l);

     {Se crea la estructura ordenada}
     l_ordenada:= nil;
     generarNuevaEstructura(l,l_ordenada);
     writeln ('Lista ordenada: ');
     imprimirLista(l_ordenada);

     {Completar el programa}
     LP:= nil;
     crearListadeListas(l_ordenada,LP);
     writeln('---------Lista de listas creada----------');
     writeln('Fin del programa');
     readln;
end.
