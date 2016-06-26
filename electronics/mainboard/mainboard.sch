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
LIBS:autoCar
LIBS:BeagleBone-Black-Cape-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 2
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
L BeagleBone_Black_Header P8
U 1 1 576ECD01
P 8075 3575
F 0 "P8" H 8075 4775 50  0000 C CNN
F 1 "BeagleBone_Black_Header" V 8075 3575 50  0000 C CNN
F 2 "" H 8075 2725 60  0000 C CNN
F 3 "" H 8075 2725 60  0000 C CNN
	1    8075 3575
	1    0    0    -1  
$EndComp
$Comp
L BeagleBone_Black_Header P9
U 1 1 576ECDB5
P 3450 3475
F 0 "P9" H 3450 4675 50  0000 C CNN
F 1 "BeagleBone_Black_Header" V 3450 3475 50  0000 C CNN
F 2 "" H 3450 2625 60  0000 C CNN
F 3 "" H 3450 2625 60  0000 C CNN
	1    3450 3475
	1    0    0    -1  
$EndComp
$Comp
L GNDD #PWR01
U 1 1 576ED070
P 3100 2300
F 0 "#PWR01" H 3100 2050 50  0001 C CNN
F 1 "GNDD" H 3100 2150 50  0000 C CNN
F 2 "" H 3100 2300 50  0000 C CNN
F 3 "" H 3100 2300 50  0000 C CNN
	1    3100 2300
	-1   0    0    1   
$EndComp
$Comp
L GNDD #PWR02
U 1 1 576ED0D0
P 3850 2300
F 0 "#PWR02" H 3850 2050 50  0001 C CNN
F 1 "GNDD" H 3850 2150 50  0000 C CNN
F 2 "" H 3850 2300 50  0000 C CNN
F 3 "" H 3850 2300 50  0000 C CNN
	1    3850 2300
	-1   0    0    1   
$EndComp
Wire Wire Line
	3200 2375 3100 2375
Wire Wire Line
	3100 2375 3100 2300
Wire Wire Line
	3850 2300 3850 2375
Wire Wire Line
	3850 2375 3700 2375
Wire Wire Line
	2925 2475 3200 2475
Wire Wire Line
	3700 2475 4025 2475
$Comp
L +3V3 #PWR03
U 1 1 576ED13C
P 4025 2375
F 0 "#PWR03" H 4025 2225 50  0001 C CNN
F 1 "+3V3" H 4025 2515 50  0000 C CNN
F 2 "" H 4025 2375 50  0000 C CNN
F 3 "" H 4025 2375 50  0000 C CNN
	1    4025 2375
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR04
U 1 1 576ED168
P 2925 2400
F 0 "#PWR04" H 2925 2250 50  0001 C CNN
F 1 "+3V3" H 2925 2540 50  0000 C CNN
F 2 "" H 2925 2400 50  0000 C CNN
F 3 "" H 2925 2400 50  0000 C CNN
	1    2925 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2925 2475 2925 2400
Wire Wire Line
	4025 2475 4025 2375
$Comp
L +5V #PWR05
U 1 1 576ED194
P 4175 2475
F 0 "#PWR05" H 4175 2325 50  0001 C CNN
F 1 "+5V" H 4175 2615 50  0000 C CNN
F 2 "" H 4175 2475 50  0000 C CNN
F 3 "" H 4175 2475 50  0000 C CNN
	1    4175 2475
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR06
U 1 1 576ED1AC
P 2775 2475
F 0 "#PWR06" H 2775 2325 50  0001 C CNN
F 1 "+5V" H 2775 2615 50  0000 C CNN
F 2 "" H 2775 2475 50  0000 C CNN
F 3 "" H 2775 2475 50  0000 C CNN
	1    2775 2475
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 2575 2775 2575
Wire Wire Line
	2775 2575 2775 2475
Wire Wire Line
	3700 2575 4175 2575
Wire Wire Line
	4175 2575 4175 2475
$Comp
L SYS_5V #PWR07
U 1 1 576ED1DA
P 2600 2625
F 0 "#PWR07" H 2600 2475 50  0001 C CNN
F 1 "SYS_5V" H 2600 2765 50  0000 C CNN
F 2 "" H 2600 2625 60  0000 C CNN
F 3 "" H 2600 2625 60  0000 C CNN
	1    2600 2625
	1    0    0    -1  
$EndComp
$Comp
L SYS_5V #PWR08
U 1 1 576ED1F6
P 4350 2625
F 0 "#PWR08" H 4350 2475 50  0001 C CNN
F 1 "SYS_5V" H 4350 2765 50  0000 C CNN
F 2 "" H 4350 2625 60  0000 C CNN
F 3 "" H 4350 2625 60  0000 C CNN
	1    4350 2625
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 2675 4350 2675
Wire Wire Line
	2600 2675 3200 2675
Text Label 2800 2775 2    60   ~ 0
PWR_BUT
Text Label 4175 2775 0    60   ~ 0
SYS_RESET
Wire Wire Line
	2600 2675 2600 2625
Wire Wire Line
	4350 2675 4350 2625
Wire Wire Line
	3700 2775 4175 2775
Wire Wire Line
	3200 2775 2800 2775
$Comp
L GNDD #PWR09
U 1 1 576ED30F
P 3450 4800
F 0 "#PWR09" H 3450 4550 50  0001 C CNN
F 1 "GNDD" H 3450 4650 50  0000 C CNN
F 2 "" H 3450 4800 50  0000 C CNN
F 3 "" H 3450 4800 50  0000 C CNN
	1    3450 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 4575 3100 4575
Wire Wire Line
	3100 4475 3100 4800
Wire Wire Line
	3100 4800 3800 4800
Wire Wire Line
	3700 4575 3800 4575
Wire Wire Line
	3800 4800 3800 4475
Connection ~ 3450 4800
Wire Wire Line
	3800 4475 3700 4475
Connection ~ 3800 4575
Wire Wire Line
	3200 4475 3100 4475
Connection ~ 3100 4575
$Comp
L GNDD #PWR010
U 1 1 576ED496
P 8075 2225
F 0 "#PWR010" H 8075 1975 50  0001 C CNN
F 1 "GNDD" H 8075 2075 50  0000 C CNN
F 2 "" H 8075 2225 50  0000 C CNN
F 3 "" H 8075 2225 50  0000 C CNN
	1    8075 2225
	-1   0    0    1   
$EndComp
Wire Wire Line
	7825 2475 7750 2475
Wire Wire Line
	7750 2475 7750 2225
Wire Wire Line
	7750 2225 8400 2225
Wire Wire Line
	8325 2475 8400 2475
Wire Wire Line
	8400 2475 8400 2225
Connection ~ 8075 2225
$EndSCHEMATC
