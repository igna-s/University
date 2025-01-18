---- Simule la entidad Adder8 y el testbench provisto. 
---  ¿es necesario agregar una sentencia assert para desplegar algún reporte en el testbench?. Justifique
---  la respuesta.



entity Test_Adder8 is end;

architecture Driver of Test_Adder8 is
          component Adder8
            port (A, B: in Bit_Vector(7 downto 0); Cin: in Bit; Cout: out Bit; Sum: out Bit_Vector(7 downto 0));
          end component;
          signal A, B, Sum: Bit_Vector(7 downto 0);	  --Pueden tener cualquier nombre
          signal Cin, Cout: Bit := '0';
begin
         UUT: Adder8 port map (A, B, Cin, Cout, Sum);	--Instanciacion de componentes con las senales anterirores
         Stimulus: process
	        variable Temp: Bit_Vector(7 downto 0); 
	        variable Expected_Sum: Bit_Vector(7 downto 0);
            begin
                Temp := "00000000";
                for i in 1 to 32 loop		 -- Dependiendo del índice i, asigna valores a A y B:
                  if i mod 2 /= 1 then
                    A <= Temp; B <= "00000001";	  --Si i es impar, A se establece en Temp y B se establece en 1.
                  else
                    B <= Temp; A <= "00000001";	  --Si i es par, B se establece en Temp y A se establece en 1.
                  end if;
                  wait for 1 ns;
	   Temp := Sum;	--Guarda la salida del Adder8 (Sum) en temp	 
                end loop;
                wait; -- to terminate simulation
            end process;
end;


