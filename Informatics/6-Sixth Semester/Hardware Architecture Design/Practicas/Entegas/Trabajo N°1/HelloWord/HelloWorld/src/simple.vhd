--ENTITY simple IS
--			END simple;
--
--			ARCHITECTURE prueba OF simple IS
--				CONSTANT mensaje: String := "hola, mundo";
--				SIGNAL canal: Character := ' ';
--			BEGIN
--				p1: PROCESS
--					BEGIN
--						FOR i IN mensaje'Range LOOP
--							canal <= mensaje(i);
--							WAIT FOR 1 ns;
--						END LOOP;
--						WAIT;
--					END PROCESS;	
--			END prueba;

			
			
			
USE std.textio.all;
			ENTITY simple IS
			END simple;

			ARCHITECTURE prueba OF simple IS
				CONSTANT mensaje: String := "hola, mundo";
				SIGNAL canal: Character := ' ';
			BEGIN
				p1: PROCESS
				variable linea: line;
				variable dummy: side;
					BEGIN
						FOR i IN mensaje'Range LOOP
							canal <= mensaje(i);
							write(linea, mensaje(i), dummy,1);
							WAIT FOR 1 ns;
						END LOOP;
						writeline(output, linea);
						WAIT;
					END PROCESS;	
			END prueba;

