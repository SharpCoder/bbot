EESchema Schematic File Version 4
EELAYER 30 0
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
L bbot-component-library:L293D U9
U 1 1 606C2560
P 5950 2000
F 0 "U9" V 5879 2478 50  0000 L CNN
F 1 "L293D" V 5970 2478 50  0000 L CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 5950 1250 50  0000 C CNN
F 3 "" H 5800 1950 50  0001 C CNN
	1    5950 2000
	0    1    1    0   
$EndComp
$Comp
L Regulator_Linear:L7805 U5
U 1 1 606D0E09
P 2700 1050
F 0 "U5" H 2700 1199 50  0000 C CNN
F 1 "L7805" H 2700 1290 50  0000 C CNN
F 2 "bbot-pcb:L7805-A" H 1900 750 50  0000 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2700 1000 50  0001 C CNN
	1    2700 1050
	-1   0    0    1   
$EndComp
$Comp
L bbot-component-library:ArduinoProMicro U4
U 1 1 606D85DE
P 2200 2750
F 0 "U4" H 2125 3475 50  0000 C CNN
F 1 "ArduinoProMicro" H 2125 3384 50  0000 C CNN
F 2 "Package_DIP:DIP-28_W15.24mm" H 2150 3550 50  0000 C CNN
F 3 "" H 1900 3550 50  0001 C CNN
	1    2200 2750
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0101
U 1 1 606DFC80
P 7150 1250
F 0 "#PWR0101" H 7150 1100 50  0001 C CNN
F 1 "+12V" H 7150 1100 50  0000 C CNN
F 2 "" H 7150 1250 50  0001 C CNN
F 3 "" H 7150 1250 50  0001 C CNN
	1    7150 1250
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC595 U7
U 1 1 606C82E5
P 3550 2750
F 0 "U7" H 3550 3531 50  0000 C CNN
F 1 "74HC595" H 3550 3440 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 3600 3600 50  0000 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 3550 2750 50  0001 C CNN
	1    3550 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 1450 6200 1600
Wire Wire Line
	5700 1600 5700 1450
Wire Wire Line
	5700 2350 5700 2500
Wire Wire Line
	6200 2350 6200 2500
Text HLabel 5700 2500 0    50   Input ~ 0
MOTOR1_C
Text HLabel 6200 1450 2    50   Input ~ 0
MOTOR1_A
Text HLabel 5700 1450 0    50   Input ~ 0
MOTOR1_B
Text HLabel 3950 2350 2    50   Input ~ 0
MOTOR1_A
Text HLabel 3950 2450 2    50   Input ~ 0
MOTOR1_B
Text HLabel 3950 2550 2    50   Input ~ 0
MOTOR1_C
Text HLabel 3950 2650 2    50   Input ~ 0
MOTOR1_D
Wire Wire Line
	6200 3900 6200 3800
Wire Wire Line
	5700 3900 5700 3800
Wire Wire Line
	6200 4650 6200 4750
Wire Wire Line
	5700 4650 5700 4750
Text HLabel 6200 3800 2    50   Input ~ 0
MOTOR2_A
Text HLabel 5700 3800 0    50   Input ~ 0
MOTOR2_B
Text HLabel 5700 4750 0    50   Input ~ 0
MOTOR2_C
Text HLabel 6200 4750 2    50   Input ~ 0
MOTOR2_D
Text HLabel 3950 2750 2    50   Input ~ 0
MOTOR2_A
Text HLabel 3950 2850 2    50   Input ~ 0
MOTOR2_B
Text HLabel 3950 2950 2    50   Input ~ 0
MOTOR2_C
Text HLabel 3950 3050 2    50   Input ~ 0
MOTOR2_D
Text HLabel 5900 3900 1    50   Input ~ 0
GND
Text HLabel 6000 3900 1    50   Input ~ 0
GND
Text HLabel 5900 4650 3    50   Input ~ 0
GND
Text HLabel 6000 4650 3    50   Input ~ 0
GND
Text HLabel 6000 2350 3    50   Input ~ 0
GND
Text HLabel 5900 2350 3    50   Input ~ 0
GND
Text HLabel 5900 1600 1    50   Input ~ 0
GND
Text HLabel 6000 1600 1    50   Input ~ 0
GND
Text HLabel 3550 3450 3    50   Input ~ 0
GND
Text HLabel 2000 4150 3    50   Input ~ 0
GND
Text HLabel 1800 2450 0    50   Input ~ 0
GND
Text HLabel 1800 2550 0    50   Input ~ 0
GND
Text HLabel 2700 750  1    50   Input ~ 0
GND
Text HLabel 7150 1250 2    50   Input ~ 0
12V
Text HLabel 3000 1050 2    50   Input ~ 0
12V
Text HLabel 6300 2350 2    50   Input ~ 0
12V
Text HLabel 5600 1600 0    50   Input ~ 0
12V
Text HLabel 6300 4650 2    50   Input ~ 0
12V
Text HLabel 5600 3900 0    50   Input ~ 0
12V
Wire Wire Line
	2400 1050 2250 1050
Text HLabel 2250 1050 0    50   Input ~ 0
5V
Text HLabel 2450 2550 2    50   Input ~ 0
5V
Text HLabel 3550 2150 0    50   Input ~ 0
5V
Text HLabel 2100 4150 3    50   Input ~ 0
5V
Text HLabel 2200 4150 3    50   Input ~ 0
SDA
Text HLabel 2300 4150 3    50   Input ~ 0
SCL
Text HLabel 1800 2650 0    50   Input ~ 0
SDA
Text HLabel 1800 2750 0    50   Input ~ 0
SCL
Text HLabel 6100 1600 1    50   Input ~ 0
MOTOR1_PHASE_A
Text HLabel 5800 1600 1    50   Input ~ 0
MOTOR1_PHASE_B
Text HLabel 5800 2350 3    50   Input ~ 0
MOTOR1_PHASE_C
Text HLabel 6100 2350 3    50   Input ~ 0
MOTOR1_PHASE_D
$Comp
L bbot-component-library:L293D U10
U 1 1 606C1081
P 5950 4300
F 0 "U10" V 5879 4778 50  0000 L CNN
F 1 "L293D" V 5970 4778 50  0000 L CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 5900 3550 50  0000 C CNN
F 3 "" H 5800 4250 50  0001 C CNN
	1    5950 4300
	0    1    1    0   
$EndComp
Text HLabel 5600 2350 0    50   Input ~ 0
5V
Text HLabel 6300 1600 2    50   Input ~ 0
5V
Text HLabel 6300 3900 2    50   Input ~ 0
5V
Text HLabel 5600 4650 0    50   Input ~ 0
5V
Text HLabel 6100 3900 1    50   Input ~ 0
MOTOR2_PHASE_A
Text HLabel 5800 3900 1    50   Input ~ 0
MOTOR2_PHASE_B
Text HLabel 5800 4650 3    50   Input ~ 0
MOTOR2_PHASE_C
Text HLabel 6100 4650 3    50   Input ~ 0
MOTOR2_PHASE_D
Text HLabel 3150 2550 0    50   Input ~ 0
SHIFT_CLCK
Text HLabel 3150 2650 0    50   Input ~ 0
5V
Text HLabel 3150 2950 0    50   Input ~ 0
SHIFT_LATCH
Text HLabel 3150 2350 0    50   Input ~ 0
SHIFT_DATA
Text HLabel 1800 2850 0    50   Input ~ 0
SHIFT_CLCK
Text HLabel 1800 2950 0    50   Input ~ 0
SHIFT_DATA
Text HLabel 1800 3050 0    50   Input ~ 0
SHIFT_LATCH
$Comp
L bbot-component-library:HA-552-4P U1
U 1 1 6071100B
P 6950 4550
F 0 "U1" H 7328 4758 50  0000 L CNN
F 1 "HA-552-4P" H 7328 4667 50  0000 L CNN
F 2 "bbot-pcb:HA-522P-Latch_Terminal" H 7328 4576 50  0000 L CNN
F 3 "" H 6950 4550 50  0001 C CNN
	1    6950 4550
	1    0    0    -1  
$EndComp
Text HLabel 6200 2500 2    50   Input ~ 0
MOTOR1_D
$Comp
L bbot-component-library:HA-552-4P U3
U 1 1 60714D0C
P 7000 2250
F 0 "U3" H 7378 2458 50  0000 L CNN
F 1 "HA-552-4P" H 7378 2367 50  0000 L CNN
F 2 "bbot-pcb:HA-522P-Latch_Terminal" H 7378 2276 50  0000 L CNN
F 3 "" H 7000 2250 50  0001 C CNN
	1    7000 2250
	1    0    0    -1  
$EndComp
Text HLabel 7300 2250 3    50   Input ~ 0
MOTOR1_PHASE_D
Text HLabel 7200 2250 3    50   Input ~ 0
MOTOR1_PHASE_C
Text HLabel 7100 2250 3    50   Input ~ 0
MOTOR1_PHASE_B
Text HLabel 7000 2250 3    50   Input ~ 0
MOTOR1_PHASE_A
Text HLabel 7250 4550 3    50   Input ~ 0
MOTOR2_PHASE_D
Text HLabel 7150 4550 3    50   Input ~ 0
MOTOR2_PHASE_C
Text HLabel 7050 4550 3    50   Input ~ 0
MOTOR2_PHASE_B
Text HLabel 6950 4550 3    50   Input ~ 0
MOTOR2_PHASE_A
$Comp
L bbot-component-library:HMC5883L U2
U 1 1 606D2B12
P 2150 4000
F 0 "U2" H 2378 3951 50  0000 L CNN
F 1 "HMC5883L" H 2378 3860 50  0000 L CNN
F 2 "bbot-pcb:HMC588L" H 2200 4300 50  0000 C CNN
F 3 "" H 2200 4200 50  0001 C CNN
	1    2150 4000
	1    0    0    -1  
$EndComp
$Comp
L bbot-component-library:Screw_Terminal_2 U6
U 1 1 607194F6
P 7150 1000
F 0 "U6" H 7328 1258 50  0000 L CNN
F 1 "Screw_Terminal_2" H 7328 1167 50  0000 L CNN
F 2 "bbot-pcb:Screw_Terminal_2" H 7328 1076 50  0000 L CNN
F 3 "" H 7150 1000 50  0001 C CNN
	1    7150 1000
	1    0    0    -1  
$EndComp
Text Notes 7000 600  0    50   ~ 0
Battery Pack
Wire Wire Line
	7150 1250 7150 1000
Text HLabel 7250 1000 2    50   Input ~ 0
GND
$EndSCHEMATC
