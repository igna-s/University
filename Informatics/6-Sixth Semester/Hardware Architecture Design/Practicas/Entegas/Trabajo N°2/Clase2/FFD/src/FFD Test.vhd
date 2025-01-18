entity Test_DFF is end;

architecture Driver of Test_DFF is 
	component DFF
	   port (Preset, Clear, Clock, Data: in Bit; Q, Qbar: out Bit);
	end component;
	signal Preset, Clear: Bit := '1';
	signal Clock, Data, Q, QBar: Bit;
begin
  UUT: DFF port map (Preset, Clear, Clock, Data, Q, Qbar);
  Stimulus: Process
	Begin
	-- chequeo de preset y clear
  Preset <= '0'; wait for 5 ns; Preset <= '1'; wait for 5 ns;
  Clear <= '0'; wait for 5 ns; Clear <= '1'; wait for 5 ns;
-- interaccion de preset y clear
  Preset <= '0'; Clear <= '0'; wait for 5 ns;
  Preset <= '1'; Clear <= '1'; wait for 5 ns;
-- limpiar
  Clear <= '0', '1' after 5 ns; wait for 10 ns;
-- chequeo de datos y clock
  Data <= '1'; Clock <= '0' after 1 ns, '1' after 5 ns; wait for 10 ns;
  Data <= '0'; Clock <= '0' after 1 ns, '1' after 5 ns; wait for 10 ns;
-- limpiar
  Clear <= '0', '1' after 5 ns; wait for 10 ns;
--interaccion de preset y clock
  Data <= '0'; Preset <= '0', '1' after 10 ns;
  Clock <= '0', '1' after 5 ns; wait for 10 ns;
  Wait;
	end process;
end;
