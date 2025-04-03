library ieee;
use ieee.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Testbench is
end Testbench;

Architecture A of Testbench is

 component divider_serial is
 port (
 clk : in  std_logic;
 resetn : in  std_logic;
 IN_A     : in  std_logic_vector(15 downto 0); -- dividend
 IN_B     : in  std_logic_vector(15 downto 0); -- divider
 OUT_DIV  : out std_logic_vector(15 downto 0); -- quotient
 OUT_REM  : out std_logic_vector(15 downto 0); -- reminder
 start    : in  std_logic;
 elab     : out std_logic;
 done     : out std_logic
 );
 end component;


  signal clk, resetn, start, elab, done: std_logic;
  signal IN_A, IN_B: std_logic_vector(15 downto 0);
  signal OUT_DIV, OUT_REM: std_logic_vector(15 downto 0);

  constant clk_period : time := 8 ns;

begin

  UUT : divider_serial
        port map (clk, resetn, IN_A, IN_B, OUT_DIV, OUT_REM, start, elab, done);

   xsclock_engine : process
    begin
      clk <= '0';
      wait for clk_period/2;
      clk <= '1';
      wait for clk_period/2;
    end process;

    reset_engine : process
      begin
	resetn <= '1';
        wait for clk_period;
        resetn <='0';
        wait for clk_period;
        resetn <= '1';
        wait;
    end process;

    input_engine: process
	begin
		wait for 2*clk_period;
		start <= '1';
		IN_A <= conv_std_logic_vector(34562, 16);
		IN_B <= conv_std_logic_vector(29536, 16);
		wait for clk_period;
		start <= '0';
		wait for 17*clk_period;
		start <= '1';
		IN_A <= conv_std_logic_vector(61283, 16);
		IN_B <= conv_std_logic_vector(11342, 16);
		wait for clk_period;
		start <= '0';
		wait for 18*clk_period;
		start <= '1';
		IN_A <= conv_std_logic_vector(59876, 16);
		IN_B <= conv_std_logic_vector(13, 16);
		wait for clk_period;
		start <= '0';
		wait for 17*clk_period;
		start <= '1';
		IN_A <= conv_std_logic_vector(26229, 16);
		IN_B <= conv_std_logic_vector(9580, 16);
		wait for clk_period;
		start <= '0';
		wait for 17*clk_period;
		start <= '1';
		IN_A <= conv_std_logic_vector(48543, 16);
		IN_B <= conv_std_logic_vector(2, 16);
		wait for clk_period;
		start <= '0';
		wait for 17*clk_period;
		start <= '1';
		IN_A <= conv_std_logic_vector(27632, 16);
		IN_B <= conv_std_logic_vector(65535, 16);
		wait for clk_period;
		start <= '0';
		wait for 17*clk_period;
		start <= '1';
		IN_A <= conv_std_logic_vector(65535, 16);
		IN_B <= conv_std_logic_vector(1, 16);
		wait for clk_period;
		start <= '0';
		wait for 17*clk_period;
		start <= '1';
		IN_A <= conv_std_logic_vector(28465, 16);
		IN_B <= conv_std_logic_vector(9422, 16);
		wait for clk_period;
		start <= '0';
		wait for 17*clk_period;
		start <= '1';
		IN_A <= conv_std_logic_vector(63231, 16);
		IN_B <= conv_std_logic_vector(3, 16);
		wait for clk_period;
		start <= '0';
		wait for 17*clk_period;
		start <= '1';
		IN_A <= conv_std_logic_vector(32490, 16);
		IN_B <= conv_std_logic_vector(1907, 16);
		wait for clk_period;
		start <= '0';
		wait for 17*clk_period;
		start <= '1';
		IN_A <= conv_std_logic_vector(45682, 16);
		IN_B <= conv_std_logic_vector(8, 16);
		wait for clk_period;
		start <= '0';
		wait for 15*clk_period;
	end process;
    
end A;