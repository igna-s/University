entity Test_ShiftN is end;

architecture Driver of Test_ShiftN is
  component ShiftN
    port (CLK: in  Bit;  CLR: in  Bit; LD: in  Bit;
          SH: in  Bit;  DIR: in  Bit;
          D: in Bit_Vector; Q: out  Bit_Vector);
  end component;
  signal CLK, CLR, LD, SH, DIR: Bit;
  signal D: Bit_Vector(1 to 4);
  signal Q: Bit_Vector(8 downto 1);
begin
  UUT: ShiftN port map (CLK, CLR, LD, SH, DIR, D, Q);
  Stimulus: process
     begin  
        CLR <= '1', '0' after 10ns;     -- limpiar el registro
        wait for 10ns;
        D <= "1110";                        -- cargar el registro
        LD <= '1', '0' after 10ns;
        CLK <= '0', '1' after 3 ns;
        wait for 10 ns;
        SH <= '1';                              -- desplazar a izquierda el patrón de bits
        DIR <= '1';
        for i in 1 to 5 loop
            CLK <= '0', '1' after 3ns;
            wait for 10ns;
        end loop;
        DIR <= '0';                            -- desplazar a derecha el patrón de bits
        for i in 1 to 8 loop
            CLK <= '0', '1' after 3ns;
            wait for 10ns;
        end loop;
        wait;
     end process;
end;
