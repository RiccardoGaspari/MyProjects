
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;                         

entity COUNTER is
  generic(cw : natural:= 16);
  port (
    CLK   : in  std_logic;
    RESET : in  std_logic;
    ENABLE : in std_logic;
    COUNT : out  std_logic_vector(cw-1 downto 0)              
    );   
end COUNTER;

architecture A of COUNTER is
signal next_value, value_temp : unsigned(cw-1 downto 0);

begin 
  process(CLK) -- PROCESSO: parte di codice valutata solo quando cambia un valore della sensitivity list
     begin
      if CLK'event and CLK='1' then
        if RESET='1' then
          value_temp <= (others => '0');
        elsif ENABLE = '1' then
          value_temp <= next_value;
        end if;
      end if;
   end process;

 COUNT <= std_logic_vector(value_temp);
 next_value <= value_temp + conv_unsigned(1,cw);  

end A;

