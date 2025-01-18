
entity Test_Utils is end;

use work.Utils.all;

architecture Driver of Test_Utils is
  signal N: Natural;
  signal B: Bit_Vector(5 downto 0);
  signal C: Bit;

  use work.Utils.all;

begin

  CLK: Clock(C, 10 ns, 10 ns);
  
  process
    use work.Utils.all;
  begin  
    for i in 0 to 31 loop
            B <= Convert (i, B'Length) after 10 ns;
            wait for 10 ns;
        end loop;
        wait;
  end process;

  N <= Convert (B) after 1 ns;

end;
