EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Carte étudiant"
Date "2021-06-29"
Rev "1.4"
Comp "INSA GEI"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x16 J2
U 1 1 5E4851B3
P 7350 2450
F 0 "J2" V 7350 3250 50  0000 L CNN
F 1 "Conn_01x14" H 7430 2351 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x16_P2.54mm_Vertical" H 7350 2450 50  0001 C CNN
F 3 "~" H 7350 2450 50  0001 C CNN
	1    7350 2450
	0    -1   -1   0   
$EndComp
$Comp
L carte_etudiant-rescue:NUCLEO64-F103RB-Insa U1
U 1 1 5E490880
P 4000 3250
F 0 "U1" H 2950 5350 50  0000 C CNN
F 1 "NUCLEO64-F103RB" H 2850 5200 50  0000 C CNN
F 2 "Insa:ST_Morpho_Connector_64" H 4550 1350 50  0001 L CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/data_brief/DM00105918.pdf" H 3100 1850 50  0001 C CNN
	1    4000 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5E4948A4
P 10750 1300
F 0 "#PWR0102" H 10750 1050 50  0001 C CNN
F 1 "GND" H 10755 1127 50  0000 C CNN
F 2 "" H 10750 1300 50  0001 C CNN
F 3 "" H 10750 1300 50  0001 C CNN
	1    10750 1300
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5E494D2B
P 10250 1050
F 0 "#FLG0101" H 10250 1125 50  0001 C CNN
F 1 "PWR_FLAG" H 10250 1223 50  0000 C CNN
F 2 "" H 10250 1050 50  0001 C CNN
F 3 "~" H 10250 1050 50  0001 C CNN
	1    10250 1050
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5E496844
P 10250 1300
F 0 "#FLG0102" H 10250 1375 50  0001 C CNN
F 1 "PWR_FLAG" H 10250 1473 50  0000 C CNN
F 2 "" H 10250 1300 50  0001 C CNN
F 3 "~" H 10250 1300 50  0001 C CNN
	1    10250 1300
	-1   0    0    1   
$EndComp
Wire Wire Line
	10250 1050 10750 1050
Wire Wire Line
	10750 1300 10250 1300
Wire Wire Line
	6550 5150 6550 5050
Wire Wire Line
	6350 5150 6350 5100
Wire Wire Line
	6350 4750 6250 4750
$Comp
L power:GND #PWR0101
U 1 1 5E4A3E36
P 6250 4750
F 0 "#PWR0101" H 6250 4500 50  0001 C CNN
F 1 "GND" H 6255 4577 50  0000 C CNN
F 2 "" H 6250 4750 50  0001 C CNN
F 3 "" H 6250 4750 50  0001 C CNN
	1    6250 4750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5E4A485B
P 3700 5350
F 0 "#PWR0103" H 3700 5100 50  0001 C CNN
F 1 "GND" H 3705 5177 50  0000 C CNN
F 2 "" H 3700 5350 50  0001 C CNN
F 3 "" H 3700 5350 50  0001 C CNN
	1    3700 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 5250 3500 5250
Connection ~ 3500 5250
Wire Wire Line
	3500 5250 3600 5250
Connection ~ 3600 5250
Wire Wire Line
	3600 5250 3700 5250
Connection ~ 3700 5250
Wire Wire Line
	3700 5250 3800 5250
Connection ~ 3800 5250
Wire Wire Line
	3800 5250 3900 5250
Connection ~ 3900 5250
Wire Wire Line
	3900 5250 4500 5250
Wire Wire Line
	3700 5250 3700 5350
NoConn ~ 3400 1250
NoConn ~ 3500 1250
NoConn ~ 3600 1250
NoConn ~ 3700 1250
NoConn ~ 3900 1250
NoConn ~ 4000 1250
NoConn ~ 4100 1250
NoConn ~ 4500 1250
NoConn ~ 2900 1750
NoConn ~ 2900 1850
NoConn ~ 2900 2950
NoConn ~ 2900 3050
NoConn ~ 2900 3150
NoConn ~ 2900 3350
NoConn ~ 2900 3450
NoConn ~ 2900 3550
NoConn ~ 2900 3650
NoConn ~ 2900 3750
NoConn ~ 2900 3850
NoConn ~ 2900 3950
NoConn ~ 2900 4050
NoConn ~ 2900 4150
NoConn ~ 2900 4250
NoConn ~ 2900 4350
NoConn ~ 2900 4450
NoConn ~ 2900 4550
NoConn ~ 2900 4650
NoConn ~ 2900 4750
NoConn ~ 2900 4850
NoConn ~ 5100 4850
NoConn ~ 5100 4750
NoConn ~ 5100 4650
NoConn ~ 5100 4550
NoConn ~ 5100 4450
NoConn ~ 5100 4350
NoConn ~ 5100 4250
NoConn ~ 5100 4150
NoConn ~ 5100 4050
NoConn ~ 5100 3950
NoConn ~ 5100 3850
NoConn ~ 5100 3750
NoConn ~ 5100 3650
NoConn ~ 5100 3550
NoConn ~ 5100 3450
NoConn ~ 5100 3350
NoConn ~ 5100 3150
NoConn ~ 5100 3050
NoConn ~ 5100 2950
NoConn ~ 5100 2850
NoConn ~ 5100 2750
NoConn ~ 5100 2650
NoConn ~ 5100 2550
NoConn ~ 5100 2450
NoConn ~ 5100 2350
NoConn ~ 5100 2250
NoConn ~ 5100 2150
NoConn ~ 5100 2050
NoConn ~ 5100 1950
NoConn ~ 5100 1850
NoConn ~ 5100 1750
NoConn ~ 5100 1650
NoConn ~ 6550 5650
NoConn ~ 6650 5650
NoConn ~ 6750 5650
NoConn ~ 6850 5650
NoConn ~ 6950 5650
NoConn ~ 7050 5650
NoConn ~ 7150 5650
NoConn ~ 7250 5650
NoConn ~ 7350 5650
NoConn ~ 7450 5650
NoConn ~ 7550 5650
NoConn ~ 7650 5650
NoConn ~ 7750 5650
NoConn ~ 7850 5650
NoConn ~ 7950 5650
$Comp
L Connector_Generic:Conn_02x20_Odd_Even J1
U 1 1 5E47CF68
P 7250 5450
F 0 "J1" V 7300 6500 50  0000 R CNN
F 1 "Conn_02x15_Odd_Even" V 7255 4662 50  0001 R CNN
F 2 "Insa:5-5530843-4-PCB" H 7250 5450 50  0001 C CNN
F 3 "~" H 7250 5450 50  0001 C CNN
	1    7250 5450
	0    -1   -1   0   
$EndComp
NoConn ~ 8250 5650
NoConn ~ 8150 5650
NoConn ~ 8050 5650
NoConn ~ 6450 5650
NoConn ~ 6350 5650
Wire Wire Line
	6650 2750 9700 2750
Wire Wire Line
	6750 2900 9700 2900
Wire Wire Line
	6850 3050 9700 3050
Wire Wire Line
	6950 3200 9700 3200
Wire Wire Line
	7050 3350 9700 3350
Wire Wire Line
	7150 3500 9700 3500
Wire Wire Line
	7250 3650 9700 3650
Wire Wire Line
	7350 3800 9700 3800
Wire Wire Line
	7450 3950 9700 3950
Wire Wire Line
	7550 4100 9700 4100
Wire Wire Line
	7650 4250 9700 4250
Wire Wire Line
	7750 4400 9700 4400
Wire Wire Line
	7850 4550 9700 4550
Wire Wire Line
	7950 4700 9700 4700
Connection ~ 6650 2750
Wire Wire Line
	6650 2750 6650 5150
Connection ~ 6750 2900
Wire Wire Line
	6750 2900 6750 5150
Connection ~ 6850 3050
Wire Wire Line
	6850 3050 6850 5150
Connection ~ 6950 3200
Wire Wire Line
	6950 3200 6950 5150
Connection ~ 7050 3350
Wire Wire Line
	7050 3350 7050 5150
Connection ~ 7150 3500
Wire Wire Line
	7150 3500 7150 5150
Connection ~ 7250 3650
Wire Wire Line
	7250 3650 7250 5150
Connection ~ 7350 3800
Wire Wire Line
	7350 3800 7350 5150
Connection ~ 7450 3950
Wire Wire Line
	7450 3950 7450 5150
Connection ~ 7550 4100
Wire Wire Line
	7550 4100 7550 5150
Connection ~ 7650 4250
Wire Wire Line
	7650 4250 7650 5150
Connection ~ 7750 4400
Wire Wire Line
	7750 4400 7750 5150
Connection ~ 7850 4550
Wire Wire Line
	7850 4550 7850 5150
Connection ~ 7950 4700
Wire Wire Line
	7950 4700 7950 5150
Wire Wire Line
	6650 2650 6650 2750
Wire Wire Line
	6750 2650 6750 2900
Wire Wire Line
	6850 2650 6850 3050
Wire Wire Line
	6950 2650 6950 3200
Wire Wire Line
	7050 2650 7050 3350
Wire Wire Line
	7150 2650 7150 3500
Wire Wire Line
	7250 2650 7250 3650
Wire Wire Line
	7350 2650 7350 3800
Wire Wire Line
	7450 2650 7450 3950
Wire Wire Line
	7550 2650 7550 4100
Wire Wire Line
	7650 2650 7650 4250
Wire Wire Line
	7750 2650 7750 4400
Wire Wire Line
	7850 2650 7850 4550
Wire Wire Line
	7950 2650 7950 4700
Wire Wire Line
	8050 2650 8050 4850
Text Label 9700 2750 2    50   ~ 0
CAPTEUR_SPI_MOSI
Text Label 9700 2900 2    50   ~ 0
CAPTEUR_SPI_MISO
Text Label 9700 3050 2    50   ~ 0
CAPTEUR_SPI_CLK
Text Label 9700 3200 2    50   ~ 0
CAPTEUR_SPI_CS
Text Label 9700 3350 2    50   ~ 0
PLATEAU_DIRECTION
Text Label 9700 3500 2    50   ~ 0
SERVO_VOILE_PWM
Text Label 9700 3650 2    50   ~ 0
PLATEAU_PWM
Text Label 9700 3800 2    50   ~ 0
UART_RX
Text Label 9700 3950 2    50   ~ 0
UART_TX
Text Label 9700 4100 2    50   ~ 0
CAPTEUR_I2C_SCL
Text Label 9700 4250 2    50   ~ 0
CAPTEUR_I2C_SDA
Text Label 9700 4400 2    50   ~ 0
GIROUETTE_PHB
Text Label 9700 4550 2    50   ~ 0
GIROUETTE_PHA
Text Label 9700 4700 2    50   ~ 0
GIROUETTE_INDEX
Text Label 9700 4850 2    50   ~ 0
TENSION_BATTERIE
Wire Wire Line
	8050 5150 8050 5100
Wire Wire Line
	8050 5100 6450 5100
Connection ~ 6350 5100
Wire Wire Line
	6350 5100 6350 4750
Wire Wire Line
	6450 5100 6450 5150
Connection ~ 6450 5100
Wire Wire Line
	6450 5100 6350 5100
Wire Wire Line
	8050 4850 9700 4850
Wire Wire Line
	8050 5000 8150 5000
Connection ~ 8050 4850
Wire Wire Line
	3800 1250 3800 950 
$Comp
L power:+5V #PWR0104
U 1 1 5E77E45F
P 3800 950
F 0 "#PWR0104" H 3800 800 50  0001 C CNN
F 1 "+5V" H 3815 1123 50  0000 C CNN
F 2 "" H 3800 950 50  0001 C CNN
F 3 "" H 3800 950 50  0001 C CNN
	1    3800 950 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0105
U 1 1 5E77F67D
P 10750 1050
F 0 "#PWR0105" H 10750 900 50  0001 C CNN
F 1 "+5V" H 10765 1223 50  0000 C CNN
F 2 "" H 10750 1050 50  0001 C CNN
F 3 "" H 10750 1050 50  0001 C CNN
	1    10750 1050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0106
U 1 1 5E780E0F
P 6550 5050
F 0 "#PWR0106" H 6550 4900 50  0001 C CNN
F 1 "+5V" H 6565 5223 50  0000 C CNN
F 2 "" H 6550 5050 50  0001 C CNN
F 3 "" H 6550 5050 50  0001 C CNN
	1    6550 5050
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x16 J3
U 1 1 60081935
P 7350 1950
F 0 "J3" V 7350 2750 50  0000 L CNN
F 1 "Conn_01x14" H 7430 1851 50  0001 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x16_P2.54mm_Vertical" H 7350 1950 50  0001 C CNN
F 3 "~" H 7350 1950 50  0001 C CNN
	1    7350 1950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6650 2650 6650 2150
Connection ~ 6650 2650
Wire Wire Line
	6750 2150 6750 2650
Connection ~ 6750 2650
Wire Wire Line
	6850 2650 6850 2150
Connection ~ 6850 2650
Wire Wire Line
	6950 2150 6950 2650
Connection ~ 6950 2650
Wire Wire Line
	7050 2150 7050 2650
Connection ~ 7050 2650
Wire Wire Line
	7150 2150 7150 2650
Connection ~ 7150 2650
Wire Wire Line
	7250 2150 7250 2650
Connection ~ 7250 2650
Wire Wire Line
	7350 2650 7350 2150
Connection ~ 7350 2650
Wire Wire Line
	7450 2150 7450 2650
Connection ~ 7450 2650
Wire Wire Line
	7550 2650 7550 2150
Connection ~ 7550 2650
Wire Wire Line
	7650 2150 7650 2650
Connection ~ 7650 2650
Wire Wire Line
	7750 2650 7750 2150
Connection ~ 7750 2650
Wire Wire Line
	7850 2150 7850 2650
Connection ~ 7850 2650
Wire Wire Line
	7950 2650 7950 2150
Connection ~ 7950 2650
Wire Wire Line
	8050 2150 8050 2650
Connection ~ 8050 2650
$Comp
L power:GND #PWR0107
U 1 1 60C93D1F
P 2650 6750
F 0 "#PWR0107" H 2650 6500 50  0001 C CNN
F 1 "GND" H 2655 6577 50  0000 C CNN
F 2 "" H 2650 6750 50  0001 C CNN
F 3 "" H 2650 6750 50  0001 C CNN
	1    2650 6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 6550 2300 6750
Wire Wire Line
	2300 6750 2650 6750
Wire Wire Line
	2950 6750 2950 6550
Connection ~ 2650 6750
Wire Wire Line
	2650 6750 2950 6750
Wire Wire Line
	8150 2150 8150 2650
Wire Wire Line
	8150 5000 8150 5150
Wire Wire Line
	8050 4850 8050 5000
Wire Wire Line
	8250 5150 8250 5000
Wire Wire Line
	8250 4900 8150 4900
Wire Wire Line
	8150 4900 8150 2650
Connection ~ 8150 2650
Wire Wire Line
	9700 5000 8250 5000
Connection ~ 8250 5000
Wire Wire Line
	8250 5000 8250 4900
Text Label 9700 5000 2    50   ~ 0
SPI_CS2
$Comp
L Graphic:Logo_Open_Hardware_Small LOGO1
U 1 1 60E31959
P 10800 6900
F 0 "LOGO1" H 10800 7175 50  0001 C CNN
F 1 "Logo_Open_Hardware_Small" H 10800 6675 50  0001 C CNN
F 2 "Insa:insa-image" H 10800 6900 50  0001 C CNN
F 3 "~" H 10800 6900 50  0001 C CNN
	1    10800 6900
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J10
U 1 1 60E869DB
P 2200 6350
F 0 "J10" V 2118 6162 50  0000 R CNN
F 1 "Conn_01x02" V 2073 6162 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2200 6350 50  0001 C CNN
F 3 "~" H 2200 6350 50  0001 C CNN
	1    2200 6350
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J11
U 1 1 60E86EF8
P 2950 6350
F 0 "J11" V 2868 6162 50  0000 R CNN
F 1 "Conn_01x02" V 2823 6162 50  0001 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2950 6350 50  0001 C CNN
F 3 "~" H 2950 6350 50  0001 C CNN
	1    2950 6350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3050 6550 2950 6550
Connection ~ 2950 6550
Wire Wire Line
	2200 6550 2300 6550
Connection ~ 2300 6550
$EndSCHEMATC
