EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:kicad_test-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LM741 U1
U 1 1 5968EA2C
P 4450 3050
F 0 "U1" H 4450 3300 50  0000 L CNN
F 1 "LM741" H 4450 3200 50  0000 L CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 4500 3100 50  0001 C CNN
F 3 "" H 4600 3200 50  0000 C CNN
	1    4450 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 3050 4950 3050
Text Label 4950 3050 0    60   ~ 0
TEST_THING
$Comp
L CONN_01X01 P1
U 1 1 5968E96B
P 5000 2400
F 0 "P1" H 5000 2500 50  0000 C CNN
F 1 "CONN_01X01" V 5100 2400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01" H 5000 2400 50  0001 C CNN
F 3 "" H 5000 2400 50  0000 C CNN
	1    5000 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2400 4800 2600
Text Label 4800 2600 0    60   ~ 0
TEST_THING
$EndSCHEMATC
