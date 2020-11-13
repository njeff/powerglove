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
L Device:C C2
U 1 1 5FA9D475
P 4900 2700
F 0 "C2" H 5015 2746 50  0000 L CNN
F 1 "1u" H 5015 2655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4938 2550 50  0001 C CNN
F 3 "~" H 4900 2700 50  0001 C CNN
	1    4900 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5FA9E888
P 3800 3350
F 0 "C1" H 3915 3396 50  0000 L CNN
F 1 "1u" H 3915 3305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3838 3200 50  0001 C CNN
F 3 "~" H 3800 3350 50  0001 C CNN
	1    3800 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 3200 4800 3200
Wire Wire Line
	5350 2850 5350 2550
Wire Wire Line
	5350 2550 4900 2550
Wire Wire Line
	5450 2850 5450 2550
Wire Wire Line
	5450 2550 5350 2550
Connection ~ 5350 2550
$Comp
L power:GND #PWR09
U 1 1 5FA9F875
P 4900 2850
F 0 "#PWR09" H 4900 2600 50  0001 C CNN
F 1 "GND" H 4905 2677 50  0000 C CNN
F 2 "" H 4900 2850 50  0001 C CNN
F 3 "" H 4900 2850 50  0001 C CNN
	1    4900 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5FA9FC6B
P 3800 3500
F 0 "#PWR05" H 3800 3250 50  0001 C CNN
F 1 "GND" H 3805 3327 50  0000 C CNN
F 2 "" H 3800 3500 50  0001 C CNN
F 3 "" H 3800 3500 50  0001 C CNN
	1    3800 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5FAA029E
P 5400 3950
F 0 "#PWR010" H 5400 3700 50  0001 C CNN
F 1 "GND" H 5405 3777 50  0000 C CNN
F 2 "" H 5400 3950 50  0001 C CNN
F 3 "" H 5400 3950 50  0001 C CNN
	1    5400 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5FAAB80C
P 4600 2950
F 0 "R2" H 4670 2996 50  0000 L CNN
F 1 "10k" H 4670 2905 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4530 2950 50  0001 C CNN
F 3 "~" H 4600 2950 50  0001 C CNN
	1    4600 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5FAAC503
P 4300 2950
F 0 "R1" H 4370 2996 50  0000 L CNN
F 1 "10k" H 4370 2905 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4230 2950 50  0001 C CNN
F 3 "~" H 4300 2950 50  0001 C CNN
	1    4300 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 3300 4600 3300
Text Label 4100 3300 0    50   ~ 0
SCL
Text Label 4100 3400 0    50   ~ 0
SDA
$Comp
L power:+3V3 #PWR011
U 1 1 5FAAE080
P 5450 2400
F 0 "#PWR011" H 5450 2250 50  0001 C CNN
F 1 "+3V3" H 5465 2573 50  0000 C CNN
F 2 "" H 5450 2400 50  0001 C CNN
F 3 "" H 5450 2400 50  0001 C CNN
	1    5450 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 2550 5450 2400
Connection ~ 5450 2550
$Comp
L power:+3V3 #PWR06
U 1 1 5FAAE7E8
P 4300 2700
F 0 "#PWR06" H 4300 2550 50  0001 C CNN
F 1 "+3V3" H 4315 2873 50  0000 C CNN
F 2 "" H 4300 2700 50  0001 C CNN
F 3 "" H 4300 2700 50  0001 C CNN
	1    4300 2700
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR07
U 1 1 5FAAEE8D
P 4600 2700
F 0 "#PWR07" H 4600 2550 50  0001 C CNN
F 1 "+3V3" H 4615 2873 50  0000 C CNN
F 2 "" H 4600 2700 50  0001 C CNN
F 3 "" H 4600 2700 50  0001 C CNN
	1    4600 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2800 4600 2700
Wire Wire Line
	4300 2800 4300 2700
Wire Wire Line
	4300 3100 4300 3400
Wire Wire Line
	4600 3100 4600 3300
Connection ~ 4600 3300
Wire Wire Line
	4600 3300 4100 3300
$Comp
L Connector_Generic:Conn_01x05 J5
U 1 1 5FAD3E6C
P 9100 1750
F 0 "J5" V 8972 2030 50  0000 L CNN
F 1 "Conn_01x05" V 9063 2030 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 9100 1750 50  0001 C CNN
F 3 "~" H 9100 1750 50  0001 C CNN
	1    9100 1750
	0    1    1    0   
$EndComp
Text Notes 8850 1950 0    50   ~ 0
5V Regulator
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5FADBF4F
P 6600 3350
F 0 "J4" H 6680 3342 50  0000 L CNN
F 1 "Conn_01x02" H 6680 3251 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x01_P2.54mm_Vertical" H 6600 3350 50  0001 C CNN
F 3 "~" H 6600 3350 50  0001 C CNN
	1    6600 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3300 6400 3300
Wire Wire Line
	6400 3300 6400 3350
Wire Wire Line
	6000 3500 6400 3500
Wire Wire Line
	6400 3500 6400 3450
$Comp
L power:+3V3 #PWR08
U 1 1 5FADECB6
P 4600 3750
F 0 "#PWR08" H 4600 3600 50  0001 C CNN
F 1 "+3V3" H 4615 3923 50  0000 C CNN
F 2 "" H 4600 3750 50  0001 C CNN
F 3 "" H 4600 3750 50  0001 C CNN
	1    4600 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 3600 4800 3800
Wire Wire Line
	4800 3800 4600 3800
Wire Wire Line
	4600 3800 4600 3750
Wire Wire Line
	4800 3500 4100 3500
Text Label 4100 3500 0    50   ~ 0
INT
Wire Wire Line
	2650 2600 2900 2600
Text Label 2900 2600 0    50   ~ 0
VBAT
Wire Wire Line
	2650 3500 2900 3500
Wire Wire Line
	2650 3600 2900 3600
Wire Wire Line
	2650 3700 2900 3700
Text Label 2900 3500 0    50   ~ 0
SCL
Text Label 2900 3600 0    50   ~ 0
SDA
Text Label 2900 3700 0    50   ~ 0
INT
Text Label 2900 3900 0    50   ~ 0
SERVO1
Text Label 2900 3800 0    50   ~ 0
SERVO2
Wire Wire Line
	2900 3800 2650 3800
Wire Wire Line
	2900 3900 2650 3900
Text Notes 3700 2300 0    80   ~ 0
Haptic Driver
Wire Notes Line
	3600 2100 7250 2100
Wire Notes Line
	7250 2100 7250 4300
Wire Notes Line
	7250 4300 3600 4300
Wire Notes Line
	3600 4300 3600 2100
Wire Notes Line
	10000 5550 7500 5550
Wire Notes Line
	10000 3900 10000 5550
Wire Notes Line
	7500 5550 7500 3900
Wire Notes Line
	7500 3900 10000 3900
Wire Notes Line
	7500 3750 7500 2100
Wire Notes Line
	10000 3750 7500 3750
Wire Notes Line
	10000 2100 10000 3750
Wire Notes Line
	7500 2100 10000 2100
Wire Wire Line
	7550 4900 7950 4900
Text Label 7550 4900 0    50   ~ 0
SERVO2
Text Label 7550 3100 0    50   ~ 0
SERVO1
Text Notes 8850 4150 0    50   ~ 0
Servo Level Shifter
Wire Wire Line
	8500 4650 9200 4650
Wire Wire Line
	9100 4500 9100 4750
Wire Wire Line
	9100 4750 9200 4750
Wire Wire Line
	9100 4850 9100 5050
Wire Wire Line
	9200 4850 9100 4850
$Comp
L power:GND #PWR021
U 1 1 5FAC4072
P 9100 5050
F 0 "#PWR021" H 9100 4800 50  0001 C CNN
F 1 "GND" H 9105 4877 50  0000 C CNN
F 2 "" H 9100 5050 50  0001 C CNN
F 3 "" H 9100 5050 50  0001 C CNN
	1    9100 5050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR020
U 1 1 5FAC4068
P 9100 4500
F 0 "#PWR020" H 9100 4350 50  0001 C CNN
F 1 "+5V" H 9115 4673 50  0000 C CNN
F 2 "" H 9100 4500 50  0001 C CNN
F 3 "" H 9100 4500 50  0001 C CNN
	1    9100 4500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J7
U 1 1 5FAC405E
P 9400 4750
F 0 "J7" H 9480 4792 50  0000 L CNN
F 1 "Conn_01x03" H 9480 4701 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 9400 4750 50  0001 C CNN
F 3 "~" H 9400 4750 50  0001 C CNN
	1    9400 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 4650 8500 4550
Connection ~ 8500 4650
Wire Wire Line
	8500 5100 8500 5300
Connection ~ 7950 4900
Wire Wire Line
	7950 4900 8200 4900
Wire Wire Line
	7950 5000 7950 4900
$Comp
L power:GND #PWR013
U 1 1 5FAC404D
P 7950 5300
F 0 "#PWR013" H 7950 5050 50  0001 C CNN
F 1 "GND" H 7955 5127 50  0000 C CNN
F 2 "" H 7950 5300 50  0001 C CNN
F 3 "" H 7950 5300 50  0001 C CNN
	1    7950 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5FAC4043
P 7950 5150
F 0 "R4" H 8020 5196 50  0000 L CNN
F 1 "10k" H 8020 5105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7880 5150 50  0001 C CNN
F 3 "~" H 7950 5150 50  0001 C CNN
	1    7950 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 4700 8500 4650
Wire Wire Line
	8500 4150 8500 4250
$Comp
L power:+5V #PWR016
U 1 1 5FAC4037
P 8500 4150
F 0 "#PWR016" H 8500 4000 50  0001 C CNN
F 1 "+5V" H 8515 4323 50  0000 C CNN
F 2 "" H 8500 4150 50  0001 C CNN
F 3 "" H 8500 4150 50  0001 C CNN
	1    8500 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5FAC402D
P 8500 4400
F 0 "R6" H 8570 4446 50  0000 L CNN
F 1 "10k" H 8570 4355 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8430 4400 50  0001 C CNN
F 3 "~" H 8500 4400 50  0001 C CNN
	1    8500 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5FAC4023
P 8500 5300
F 0 "#PWR017" H 8500 5050 50  0001 C CNN
F 1 "GND" H 8505 5127 50  0000 C CNN
F 2 "" H 8500 5300 50  0001 C CNN
F 3 "" H 8500 5300 50  0001 C CNN
	1    8500 5300
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:BSS123 Q2
U 1 1 5FAC4019
P 8400 4900
F 0 "Q2" H 8606 4946 50  0000 L CNN
F 1 "BSS123" H 8606 4855 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8600 4825 50  0001 L CIN
F 3 "http://www.diodes.com/assets/Datasheets/ds30366.pdf" H 8400 4900 50  0001 L CNN
	1    8400 4900
	1    0    0    -1  
$EndComp
Text Notes 8850 2350 0    50   ~ 0
Servo Level Shifter
Wire Wire Line
	8500 2850 9200 2850
Wire Wire Line
	9100 2700 9100 2950
Wire Wire Line
	9100 2950 9200 2950
Wire Wire Line
	9100 3050 9100 3250
Wire Wire Line
	9200 3050 9100 3050
$Comp
L power:GND #PWR019
U 1 1 5FABC029
P 9100 3250
F 0 "#PWR019" H 9100 3000 50  0001 C CNN
F 1 "GND" H 9105 3077 50  0000 C CNN
F 2 "" H 9100 3250 50  0001 C CNN
F 3 "" H 9100 3250 50  0001 C CNN
	1    9100 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR018
U 1 1 5FABB61C
P 9100 2700
F 0 "#PWR018" H 9100 2550 50  0001 C CNN
F 1 "+5V" H 9115 2873 50  0000 C CNN
F 2 "" H 9100 2700 50  0001 C CNN
F 3 "" H 9100 2700 50  0001 C CNN
	1    9100 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J6
U 1 1 5FABAFEE
P 9400 2950
F 0 "J6" H 9480 2992 50  0000 L CNN
F 1 "Conn_01x03" H 9480 2901 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 9400 2950 50  0001 C CNN
F 3 "~" H 9400 2950 50  0001 C CNN
	1    9400 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 2850 8500 2750
Connection ~ 8500 2850
Wire Wire Line
	8500 3300 8500 3500
Connection ~ 7950 3100
Wire Wire Line
	7950 3100 7550 3100
Wire Wire Line
	7950 3100 8200 3100
Wire Wire Line
	7950 3200 7950 3100
$Comp
L power:GND #PWR012
U 1 1 5FAB0839
P 7950 3500
F 0 "#PWR012" H 7950 3250 50  0001 C CNN
F 1 "GND" H 7955 3327 50  0000 C CNN
F 2 "" H 7950 3500 50  0001 C CNN
F 3 "" H 7950 3500 50  0001 C CNN
	1    7950 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5FAB020A
P 7950 3350
F 0 "R3" H 8020 3396 50  0000 L CNN
F 1 "10k" H 8020 3305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7880 3350 50  0001 C CNN
F 3 "~" H 7950 3350 50  0001 C CNN
	1    7950 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 2900 8500 2850
Wire Wire Line
	8500 2350 8500 2450
$Comp
L power:+5V #PWR014
U 1 1 5FAAF773
P 8500 2350
F 0 "#PWR014" H 8500 2200 50  0001 C CNN
F 1 "+5V" H 8515 2523 50  0000 C CNN
F 2 "" H 8500 2350 50  0001 C CNN
F 3 "" H 8500 2350 50  0001 C CNN
	1    8500 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5FAAB4AF
P 8500 2600
F 0 "R5" H 8570 2646 50  0000 L CNN
F 1 "10k" H 8570 2555 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8430 2600 50  0001 C CNN
F 3 "~" H 8500 2600 50  0001 C CNN
	1    8500 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5FAAAEE2
P 8500 3500
F 0 "#PWR015" H 8500 3250 50  0001 C CNN
F 1 "GND" H 8505 3327 50  0000 C CNN
F 2 "" H 8500 3500 50  0001 C CNN
F 3 "" H 8500 3500 50  0001 C CNN
	1    8500 3500
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:BSS123 Q1
U 1 1 5FAA0700
P 8400 3100
F 0 "Q1" H 8606 3146 50  0000 L CNN
F 1 "BSS123" H 8606 3055 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8600 3025 50  0001 L CIN
F 3 "http://www.diodes.com/assets/Datasheets/ds30366.pdf" H 8400 3100 50  0001 L CNN
	1    8400 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 1400 8900 1550
Wire Wire Line
	9000 1550 9000 1400
Wire Wire Line
	9100 1550 9100 1400
Wire Wire Line
	9200 1400 9200 1550
Wire Wire Line
	9300 1550 9300 1400
Text Label 9100 1400 1    50   ~ 0
VBAT
Text Label 9200 1400 1    50   ~ 0
GND
$Comp
L power:+5V #PWR022
U 1 1 5FB2293C
P 9300 1400
F 0 "#PWR022" H 9300 1250 50  0001 C CNN
F 1 "+5V" H 9315 1573 50  0000 C CNN
F 2 "" H 9300 1400 50  0001 C CNN
F 3 "" H 9300 1400 50  0001 C CNN
	1    9300 1400
	1    0    0    -1  
$EndComp
Text Label 9000 1400 1    50   ~ 0
EN
Text Label 8900 1400 1    50   ~ 0
PG
$Comp
L Connector_Generic:Conn_01x06 J2
U 1 1 5FB32D8E
P 2450 3700
F 0 "J2" H 2368 3175 50  0000 C CNN
F 1 "Conn_01x06" H 2368 3266 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 2450 3700 50  0001 C CNN
F 3 "~" H 2450 3700 50  0001 C CNN
	1    2450 3700
	-1   0    0    1   
$EndComp
Connection ~ 4300 3400
Wire Wire Line
	4300 3400 4100 3400
Wire Wire Line
	4300 3400 4800 3400
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5FAA616E
P 2450 2600
F 0 "J1" H 2368 2817 50  0000 C CNN
F 1 "Conn_01x02" H 2368 2726 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2450 2600 50  0001 C CNN
F 3 "~" H 2450 2600 50  0001 C CNN
	1    2450 2600
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5FAA98F5
P 2900 2700
F 0 "#PWR04" H 2900 2450 50  0001 C CNN
F 1 "GND" H 2905 2527 50  0000 C CNN
F 2 "" H 2900 2700 50  0001 C CNN
F 3 "" H 2900 2700 50  0001 C CNN
	1    2900 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 2700 2900 2700
Text Notes 1950 4400 0    50   ~ 0
To Buckler (header connection)
$Comp
L power:GND #PWR01
U 1 1 5FB2FC84
P 2750 5350
F 0 "#PWR01" H 2750 5100 50  0001 C CNN
F 1 "GND" H 2755 5177 50  0000 C CNN
F 2 "" H 2750 5350 50  0001 C CNN
F 3 "" H 2750 5350 50  0001 C CNN
	1    2750 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 5300 2750 5350
Connection ~ 2750 5300
Wire Wire Line
	2650 5300 2750 5300
Wire Wire Line
	2750 5200 2750 5300
Wire Wire Line
	2650 5200 2750 5200
$Comp
L power:+3V3 #PWR02
U 1 1 5FB2C6C7
P 2850 4700
F 0 "#PWR02" H 2850 4550 50  0001 C CNN
F 1 "+3V3" H 2865 4873 50  0000 C CNN
F 2 "" H 2850 4700 50  0001 C CNN
F 3 "" H 2850 4700 50  0001 C CNN
	1    2850 4700
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03
U 1 1 5FB2C441
P 2850 5100
F 0 "#PWR03" H 2850 4950 50  0001 C CNN
F 1 "+5V" H 2865 5273 50  0000 C CNN
F 2 "" H 2850 5100 50  0001 C CNN
F 3 "" H 2850 5100 50  0001 C CNN
	1    2850 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 5100 2850 5100
$Comp
L Connector_Generic:Conn_01x07 J3
U 1 1 5FB2A376
P 2450 5000
F 0 "J3" H 2368 4475 50  0000 C CNN
F 1 "Conn_01x07" H 2368 4566 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical" H 2450 5000 50  0001 C CNN
F 3 "~" H 2450 5000 50  0001 C CNN
	1    2450 5000
	-1   0    0    1   
$EndComp
NoConn ~ 2650 4900
Connection ~ 2750 4800
Wire Wire Line
	2750 5000 2750 4800
Wire Wire Line
	2650 5000 2750 5000
Wire Wire Line
	2750 4700 2850 4700
Connection ~ 2750 4700
Wire Wire Line
	2750 4800 2750 4700
Wire Wire Line
	2650 4800 2750 4800
Wire Wire Line
	2650 4700 2750 4700
Text Notes 1950 3100 0    50   ~ 0
To Buckler (jumpers)\n
Text Notes 1950 2250 0    50   ~ 0
From Battery (2S Lipo)
Text Notes 2150 5750 0    50   ~ 0
ToF Sensor
Wire Wire Line
	2650 6250 2900 6250
Wire Wire Line
	2650 6350 2900 6350
Text Label 2900 6350 0    50   ~ 0
SCL
Text Label 2900 6250 0    50   ~ 0
SDA
Wire Wire Line
	3150 6150 3150 6200
Wire Wire Line
	2650 6150 3150 6150
$Comp
L power:GND #PWR024
U 1 1 5FAF6B54
P 3150 6200
F 0 "#PWR024" H 3150 5950 50  0001 C CNN
F 1 "GND" H 3155 6027 50  0000 C CNN
F 2 "" H 3150 6200 50  0001 C CNN
F 3 "" H 3150 6200 50  0001 C CNN
	1    3150 6200
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR023
U 1 1 5FAF9080
P 3150 6000
F 0 "#PWR023" H 3150 5850 50  0001 C CNN
F 1 "+3V3" H 3165 6173 50  0000 C CNN
F 2 "" H 3150 6000 50  0001 C CNN
F 3 "" H 3150 6000 50  0001 C CNN
	1    3150 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 6050 3150 6000
Wire Wire Line
	2650 6050 3150 6050
$Comp
L powerglove_library:DRV2605 U1
U 1 1 5FB13902
P 5400 3400
F 0 "U1" H 5750 2950 50  0000 C CNN
F 1 "DRV2605" H 5850 2850 50  0000 C CNN
F 2 "Package_SO:VSSOP-10_3x3mm_P0.5mm" H 5400 3400 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/symlink/drv2605l.pdf" H 5400 3400 50  0001 C CNN
	1    5400 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5FAF0DDB
P 4300 5200
F 0 "R7" H 4370 5246 50  0000 L CNN
F 1 "10k" H 4370 5155 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4230 5200 50  0001 C CNN
F 3 "~" H 4300 5200 50  0001 C CNN
	1    4300 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5FAF2A87
P 4300 5600
F 0 "R8" H 4370 5646 50  0000 L CNN
F 1 "10k" H 4370 5555 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4230 5600 50  0001 C CNN
F 3 "~" H 4300 5600 50  0001 C CNN
	1    4300 5600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R9
U 1 1 5FAF4D96
P 4300 6050
F 0 "R9" H 4370 6096 50  0000 L CNN
F 1 "10k" H 4370 6005 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4230 6050 50  0001 C CNN
F 3 "~" H 4300 6050 50  0001 C CNN
	1    4300 6050
	1    0    0    -1  
$EndComp
Text Label 4300 4950 0    50   ~ 0
VBAT
Wire Wire Line
	4300 4950 4300 5050
Wire Wire Line
	4300 5350 4300 5450
Wire Wire Line
	4300 5750 4300 5800
$Comp
L power:GND #PWR025
U 1 1 5FB03B96
P 4300 6200
F 0 "#PWR025" H 4300 5950 50  0001 C CNN
F 1 "GND" H 4305 6027 50  0000 C CNN
F 2 "" H 4300 6200 50  0001 C CNN
F 3 "" H 4300 6200 50  0001 C CNN
	1    4300 6200
	1    0    0    -1  
$EndComp
Text Label 4650 5800 0    50   ~ 0
monitor
Wire Wire Line
	4650 5800 4300 5800
Connection ~ 4300 5800
Wire Wire Line
	4300 5800 4300 5900
$Comp
L Connector_Generic:Conn_01x04 J8
U 1 1 5FAF6479
P 2450 6250
F 0 "J8" H 2368 5825 50  0000 C CNN
F 1 "Conn_01x04" H 2368 5916 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 2450 6250 50  0001 C CNN
F 3 "~" H 2450 6250 50  0001 C CNN
	1    2450 6250
	-1   0    0    1   
$EndComp
Text Label 2900 3400 0    50   ~ 0
monitor
Wire Wire Line
	2900 3400 2650 3400
Text Notes 4150 4750 0    50   ~ 0
Divider for Battery Monitoring\n
Wire Notes Line
	4100 4550 5350 4550
Wire Notes Line
	5350 4550 5350 6500
Wire Notes Line
	5350 6500 4100 6500
Wire Notes Line
	4100 6500 4100 4550
$EndSCHEMATC
