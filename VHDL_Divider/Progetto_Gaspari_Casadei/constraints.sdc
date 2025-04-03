##
create_clock -name CLOCK -period 6.00 -waveform {0 3} [get_ports {clk}]

derive_clock_uncertainty

 set_max_delay -from resetn 6