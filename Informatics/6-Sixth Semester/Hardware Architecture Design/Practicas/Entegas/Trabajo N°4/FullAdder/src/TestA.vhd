--Parte A
---- testbench ------ Simule y haga las modificaciones que correspondan en el testbench, para 
---  que la sentencia assert despliegue un reporte de error.

---------------Testbench---------------
entity test_sumador is
end;

architecture driver of test_sumador is
component fulladder
 port (X, Y, Cin: in Bit; Cout, Sum: out Bit);
end component;
signal X, Y, Cin, Cout, Sum: Bit;
begin
 uut: fulladder port map (X, Y, Cin, Cout, Sum);
 estimulo: process
	type Entry is record	 --Record con valores entrada y salida de los registros
	 X, Y, Cin: Bit;
	 Cout, Sum: Bit;
	end record;
	type Table is array (0 to 7) of Entry;
	constant Tabla: Table:=
	(('0', '0', '0', '0', '0'),
	 ('0', '0', '1', '0', '1'),	    --Contiene los valores de entrada (Primeros 3) y los de salida
	 ('0', '1', '0', '0', '1'),
	 ('0', '1', '1', '1', '0'),
	 ('1', '0', '0', '0', '1'),
	 ('1', '0', '1', '1', '0'),			   
	 ('1', '1', '0', '1', '0'),		--Como la table es de tipo entry, cada fila corresponde a un 
	 ('1', '1', '1', '1', '1')	    --valor del record, pudiendose acceder con	X <= Tabla(i).X;  
	);
 begin
	for i in Tabla'range loop
	 X <= Tabla(i).X;				 -- Recorre todas las combinaciones en la tabla y asigna
	 Y <= Tabla(i).Y;                -- cada una a las entradas del sumador. 
	 Cin <= Tabla(i).Cin;             
     wait for 1 ps;					 --Espera 1 ns para permitir que los valores se propaguen.
	 assert
	  Cout = Tabla(i).Cout and		  --Se fija que los valores sean los esperados, sino tira error
	  Sum = Tabla(i).Sum;
	end loop;
	wait;
 end process;
end;
