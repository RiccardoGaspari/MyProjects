library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
 
 entity divider_serial is
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
 end divider_serial;

architecture behavioral of divider_serial is

signal in_a_reg: std_logic_vector (14 downto 0);
signal in_b_reg: std_logic_vector (15 downto 0);
signal a_pad_d, a_pad_q: std_logic_vector (15 downto 0);
signal div_d, div_q, rem_d, rem_q: std_logic_vector(15 downto 0);
signal shift, reset_cont: std_logic;

signal sub: std_logic_vector(16 downto 0);

type stato is (idle, elaboration, waiting, finished);
signal cs, ns: stato;

signal cont: std_logic_vector(3 downto 0);


component COUNTER 
     generic(cw: natural:=16);
     port (
        CLK   : in  std_logic;
        RESET : in  std_logic;
        ENABLE : in std_logic;
        COUNT : out std_logic_vector(cw-1 downto 0)
		  ); 
end component;

begin

	reset_cont <= not(resetn and shift);

   cont0 : COUNTER
	generic map(cw => 4)
	port map (		
                  CLK   => clk,
                  RESET => reset_cont,
						ENABLE => '1',
                  COUNT => cont
	);
	
-- Registro di 15 bit con enable (start) e reset asincrono di campionamento divisore (escluso MSB) con rete di shift
	process(clk, resetn)
	begin
		if resetn = '0' then
			in_a_reg <= (others => '0');
		elsif clk'event and clk='1' then
			if start='1' then
				in_a_reg <= IN_A(14 downto 0);
			elsif shift='1' then
				in_a_reg <= in_a_reg(13 downto 0) & '0';
			end if;
		end if;
	end process;
	
-- Registro con enable (start) e reset asincrono di campionamento MSB dell'ingresso e shift con registro di campionamento del divisore (in_a_reg)
	process(clk, resetn)
	begin
		if resetn = '0' then
			a_pad_q <= (others => '0');
		elsif clk'event and clk='1' then
			if start='1' then
				a_pad_q <= "000000000000000" & IN_A(15);
			elsif shift='1' then
				a_pad_q <= a_pad_d(14 downto 0) & in_a_reg(14);
			else
				a_pad_q <= a_pad_d;
			end if;
		end if;
	end process;
	
-- Collegamento uscita registro di appoggio a registro di uscita
	rem_d <= a_pad_q;
	
-- Registro con enable (start) e reset asincrono di campionamento dividendo
	process(clk, resetn)
	begin
		if resetn = '0' then
			in_b_reg <= (others => '0');
		elsif clk'event and clk='1' and start='1' then
			in_b_reg <= IN_B;
		end if;
	end process;
	
-- registro di stato di gestione FSM
	process(clk, resetn)
	begin
		if resetn = '0' then
			cs <= idle;
		elsif clk'event and clk='1' then
			cs <= ns;
		end if;
	end process;
	
-- Registro di campionamento dell'uscita OUT_REM
	process(clk, resetn)
	begin
		if resetn='0' then
			rem_q <= (others => '0');
		elsif clk'event and clk='1' then
			rem_q <= rem_d;
		end if;
	end process;
	
-- Assegnamento uscita OUT_REM
	OUT_REM <= rem_q;

-- Registro di campionamento dell'uscita OUT_DIV
	process(clk, resetn)
	begin
		if resetn='0' then
			div_q <= (others => '0');
		elsif clk'event and clk='1' then
			div_q <= div_d;
		end if;
	end process;
	
-- Assegnamento uscita OUT_DIV
	OUT_DIV <= div_q;
	
-- Rete combinatoria algoritmo di divisione
	process(cs, start, div_q, a_pad_q, in_b_reg, sub)
	begin
		case cs is
			when elaboration =>
				-- Shift verso sx di div_q
				div_d(15 downto 1) <= div_q(14 downto 0);
				-- Calcolo sottrazione con segno
				sub <= signed('0' & a_pad_q) - signed('0' & in_b_reg);
				-- Assegnamento LSB a seconda dei casi + valutazione resto parziale divisione
				-- oss.: lo shift di rem viene fatto nel registro
				if sub(16) = '0' then -- sub >= 0
					div_d(0) <= '1';
					a_pad_d <= sub(15 downto 0);
				else -- sub < 0
					div_d(0) <= '0';
					a_pad_d <= a_pad_q;
				end if;
			when waiting =>
				-- Permanenza dei valori in attesa della propagazione del regnale a_pad_q in rem_q
				div_d <= div_q;
				a_pad_d <= a_pad_q;
				sub <= (others => '0');
			when others =>
				div_d <= (others => '0');
				a_pad_d <= (others => '0');
				sub <= (others => '0');
			end case;
	end process;
	
-- Assegnamento uscite elab e done
	process(cs)
	begin
		elab <= '0';
		done <= '0';
		case cs is
			when elaboration =>
				elab <= '1';
			when waiting =>
				elab <= '1';
			when finished =>
				done <= '1';
			when others =>
				elab <= '0';
				done <= '0';
			end case;
	end process;
	
-- Rete combinatoria di gestione FSM (si rimanda al dds nella relazione di progetto)
	process(cs, start, cont)
	begin
		case cs is
			when idle =>
				shift <= '0';
				if start = '1' then
					ns <= elaboration;
				else
					ns <= idle;
				end if;
			when elaboration =>
				if cont < "1111" then
					shift <= '1';
				else
					shift <= '0';
				end if;
				if cont = "1111" then
					ns <= waiting;
				else
					ns <= cs;
				end if;
			when waiting =>
				ns <= finished;
				shift <= '0';
			when finished =>
				shift <= '0';
				if start = '1' then
					ns <= elaboration;
				else
					ns <= idle;
				end if;
			when others =>
				shift <= '0';
				ns <= idle;
			end case;
	end process;
	
end behavioral;