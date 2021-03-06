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
L bbot-component-library:L293D MOTOR1_L293D1
U 1 1 606C2560
P 5950 2000
F 0 "MOTOR1_L293D1" V 5879 2478 50  0000 L CNN
F 1 "L293D" V 5970 2478 50  0000 L CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 5950 1250 50  0000 C CNN
F 3 "" H 5800 1950 50  0001 C CNN
	1    5950 2000
	0    1    1    0   
$EndComp
$Comp
L 74xx:74HC595 SHIFT_REGISTER1
U 1 1 606C82E5
P 3550 2750
F 0 "SHIFT_REGISTER1" H 3550 3531 50  0000 C CNN
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
Text HLabel 5900 4650 3    50   Input ~ 0
GND
Text HLabel 5900 1600 1    50   Input ~ 0
GND
Text HLabel 2050 850  1    50   Input ~ 0
GND
Text HLabel 2650 1150 2    50   Input ~ 0
12V
Text HLabel 6300 2350 2    50   Input ~ 0
5V
Text HLabel 5600 1600 0    50   Input ~ 0
12V
Text HLabel 6300 4650 2    50   Input ~ 0
5V
Text HLabel 5600 3900 0    50   Input ~ 0
12V
Text HLabel 1550 1150 0    50   Input ~ 0
5V
Text HLabel 3550 2150 0    50   Input ~ 0
5V
Text HLabel 6100 1600 1    50   Input ~ 0
MOTOR1_PHASE_A
Text HLabel 5800 1600 1    50   Input ~ 0
MOTOR1_PHASE_B
Text HLabel 5800 2350 3    50   Input ~ 0
MOTOR1_PHASE_C
Text HLabel 6100 2350 3    50   Input ~ 0
MOTOR1_PHASE_D
$Comp
L bbot-component-library:L293D MOTOR2_L293D1
U 1 1 606C1081
P 5950 4300
F 0 "MOTOR2_L293D1" V 5879 4778 50  0000 L CNN
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
SHIFT_CLR
Text HLabel 3150 2950 0    50   Input ~ 0
GND
Text HLabel 3150 2350 0    50   Input ~ 0
SHIFT_DATA
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
L bbot-component-library:Screw_Terminal_2 BatteryPack1
U 1 1 607194F6
P 7150 1000
F 0 "BatteryPack1" H 7328 1258 50  0000 L CNN
F 1 "Screw_Terminal_2" H 7328 1167 50  0000 L CNN
F 2 "bbot-pcb:Screw_Terminal_2" H 7328 1076 50  0000 L CNN
F 3 "" H 7150 1000 50  0001 C CNN
	1    7150 1000
	1    0    0    -1  
$EndComp
Text Notes 7000 600  0    50   ~ 0
Battery Pack
Text HLabel 7250 1000 2    50   Input ~ 0
GND
$Comp
L Regulator_Linear:L7805 MOSFET1
U 1 1 606D0E09
P 2050 1150
F 0 "MOSFET1" H 2050 1299 50  0000 C CNN
F 1 "L7805" H 2050 1390 50  0000 C CNN
F 2 "bbot-pcb:L7805-A" H 1250 850 50  0000 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2050 1100 50  0001 C CNN
	1    2050 1150
	-1   0    0    1   
$EndComp
$Comp
L bbot-component-library:Screw_Terminal_2 PowerSwitch1
U 1 1 60720FFC
P 7650 1650
F 0 "PowerSwitch1" H 7828 1863 50  0000 L CNN
F 1 "Screw_Terminal_2" H 7828 1772 50  0000 L CNN
F 2 "bbot-pcb:Screw_Terminal_2" H 7650 1650 50  0001 C CNN
F 3 "" H 7650 1650 50  0001 C CNN
	1    7650 1650
	1    0    0    -1  
$EndComp
Text HLabel 7750 1650 2    50   Input ~ 0
12V
Text Notes 7850 1350 0    50   ~ 0
Power Switch
Wire Wire Line
	7150 1000 7150 1650
Wire Wire Line
	7150 1650 7650 1650
Wire Wire Line
	5700 2350 5700 2500
Wire Wire Line
	6200 2350 6200 2500
Text HLabel 3150 2850 0    50   Input ~ 0
SHIFT_LATCH
$Comp
L bbot-component-library:ADXL335 U2
U 1 1 607BD863
P 1450 5600
F 0 "U2" H 1728 5496 50  0000 L CNN
F 1 "ADXL335" H 1728 5405 50  0000 L CNN
F 2 "bbot-pcb:ADXL335" H 1500 5800 50  0000 C CNN
F 3 "" H 1200 5650 50  0001 C CNN
	1    1450 5600
	1    0    0    -1  
$EndComp
Text HLabel 1200 5550 0    50   Input ~ 0
3V
Text HLabel 1200 5650 0    50   Input ~ 0
A0
Text HLabel 700  5700 0    50   Input ~ 0
A1
Text HLabel 1200 5850 0    50   Input ~ 0
A2
Text HLabel 1200 5950 0    50   Input ~ 0
GND
Text HLabel 3550 3450 3    50   Input ~ 0
GND
$Comp
L bbot-component-library:ArduinoProMicro U4
U 1 1 608BA4F8
P 1550 2450
F 0 "U4" H 1475 3175 50  0000 C CNN
F 1 "ArduinoProMicro" H 1475 3084 50  0000 C CNN
F 2 "promicro:ProMicro" H 1250 3250 50  0001 C CNN
F 3 "" H 1250 3250 50  0001 C CNN
	1    1550 2450
	1    0    0    -1  
$EndComp
$Comp
L Sparkfun:SPARKFUN-RESISTORS_4.7KOHM-0603-1_10W-1% R1
U 1 1 608BCB4A
P 1200 4000
F 0 "R1" V 1137 4068 45  0000 L CNN
F 1 "SPARKFUN-RESISTORS_4.7KOHM-0603-1_10W-1%" V 1221 4068 45  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 1284 4068 20  0000 L CNN
F 3 "" H 1200 4000 60  0001 C CNN
	1    1200 4000
	0    1    1    0   
$EndComp
$Comp
L Sparkfun:SPARKFUN-RESISTORS_4.7KOHM-0603-1_10W-1% R2
U 1 1 608BDF88
P 1200 4650
F 0 "R2" V 1137 4718 45  0000 L CNN
F 1 "SPARKFUN-RESISTORS_4.7KOHM-0603-1_10W-1%" V 1221 4718 45  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 1284 4718 20  0000 L CNN
F 3 "" H 1200 4650 60  0001 C CNN
	1    1200 4650
	0    1    1    0   
$EndComp
Text HLabel 1200 4850 3    50   Input ~ 0
GND
Text HLabel 1200 3800 1    50   Input ~ 0
5V
Wire Wire Line
	1200 4200 1200 4300
Wire Wire Line
	1200 4300 1600 4300
Connection ~ 1200 4300
Wire Wire Line
	1200 4300 1200 4450
Text HLabel 1600 4300 2    50   Input ~ 0
3V
Text HLabel 1800 1950 2    50   Input ~ 0
5V
Text HLabel 1150 2150 0    50   Input ~ 0
GND
Text HLabel 1800 2650 2    50   Input ~ 0
A0
Text HLabel 1800 2550 2    50   Input ~ 0
A1
Text HLabel 1800 2450 2    50   Input ~ 0
A2
Text Notes 1200 3550 0    50   ~ 0
Step-down converter
Text HLabel 1150 2750 0    50   Input ~ 0
SHIFT_LATCH
Text HLabel 1150 2850 0    50   Input ~ 0
SHIFT_DATA
Text HLabel 1150 2650 0    50   Input ~ 0
SHIFT_CLCK
Text HLabel 1150 2550 0    50   Input ~ 0
SHIFT_CLR
$Comp
L Device:C C2
U 1 1 608C7BCB
P 900 5850
F 0 "C2" V 648 5850 50  0000 C CNN
F 1 "C.0047mf" V 739 5850 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D3.4mm_W2.1mm_P2.50mm" H 938 5700 50  0001 C CNN
F 3 "~" H 900 5850 50  0001 C CNN
	1    900  5850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 608C879A
P 1600 1300
F 0 "C4" V 1348 1300 50  0000 C CNN
F 1 "L7805_OUT_CAP" V 1250 1300 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 1638 1150 50  0001 C CNN
F 3 "~" H 1600 1300 50  0001 C CNN
	1    1600 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 608C9E4F
P 2550 1300
F 0 "C5" V 2298 1300 50  0000 C CNN
F 1 "L7805_IN_CAP" V 2400 1100 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 2588 1150 50  0001 C CNN
F 3 "~" H 2550 1300 50  0001 C CNN
	1    2550 1300
	1    0    0    -1  
$EndComp
Text HLabel 1600 1450 0    50   Input ~ 0
GND
Text HLabel 2550 1450 2    50   Input ~ 0
GND
Wire Wire Line
	1550 1150 1600 1150
Wire Wire Line
	1600 1150 1750 1150
Connection ~ 1600 1150
Wire Wire Line
	2350 1150 2550 1150
Wire Wire Line
	2550 1150 2650 1150
Connection ~ 2550 1150
Wire Wire Line
	700  5700 900  5700
Wire Wire Line
	900  5700 1000 5700
Wire Wire Line
	1000 5700 1000 5750
Wire Wire Line
	1000 5750 1200 5750
Connection ~ 900  5700
Text HLabel 900  6000 3    50   Input ~ 0
GND
$EndSCHEMATC
