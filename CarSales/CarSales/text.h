﻿/*
 * String Constants
 * Final
 */

#include<string>
using std::string;

//for converting enum to string
const string ColorStr[] = {
	"red", "orange", "yellow", "green", "blue", "violet", "white", "black", "gray"
};

const string EngineStr[] = {
	"diesel", "gas"
};

const string TransmissionStr[] = {
	"auto", "manual"
};

//graphics
const char TopDiv[3] = {char(218),char(194),char(191)}, // ┌┬┐
		   MidDiv[3] = {char(195),char(197),char(180)}, // ├┼┤
		   BotDiv[3] = {char(192),char(193),char(217)}, // └┴┘
		   VLine = char(196), //─
		   HLine = char(179), //│
           LoadE = char(176), //░
		   LoadF = char(178); //▓

// hindi lumalabas sa console puro question mark lang
// kaya load ulit sa populateGraphics function
//string
//TopVerticalLine = "┌──────────────────────────────────────────────────────────────────────────────┐",
//BotVerticalLine = "└──────────────────────────────────────────────────────────────────────────────┘";

const int 
	Lenght_QuitMessage = 5,
	Lenght_carDetails = 14,
	Lenght_WelcomeMessage = 8,

	Lenght_Null = 0
	;

//database filename
const string datafile = ".\\CarData.txt";

//messages and prompts
string carDetails_Fill[] ={
	"________________________________________________________________________________",
	"|                         Please Fill in the Details                           |",
	"|______________________________________________________________________________|",
	"|            Brand:                                       |_________________|  |",
	"|      Name of Car:                                       |_________________|  |",
	"|            Color:                                       |_________________|  |",
	"|  Efficiency(MPG):                                       |_________________|  |",
	"|       Speed(MPH):                                       |_________________|  |",
	"|  Dry Weight(lbs):                                       |_________________|  |",
	"|  Engine(dsl/gas):                                       |_________________|  |",
	"|     Transmission:                                       |_________________|  |",
	"| Manufacture Date:                                       |_________________|  |",
	"|       Price(Php):                                       |_________________|  |",
	"|_________________________________________________________|_________________|__|"
};
string carDetails_ShowInfo[] ={
	"________________________________________________________________________________",
	"|                      Showing Complete Car Information                        |",
	"|______________________________________________________________________________|",
	"|            Brand:                                       |_________________|  |",
	"|      Name of Car:                                       |_________________|  |",
	"|            Color:                                       |_________________|  |",
	"|       Efficiency:                                       |_________________|  |",
	"|            Speed:                                       |_________________|  |",
	"|       Dry Weight:                                       |_________________|  |",
	"|           Engine:                                       |_________________|  |",
	"|     Transmission:                                       |-----------------|  |",
	"| Manufacture Date:                                       |                 |  |",
	"|            Price:                                       |                 |  |",
	"|_________________________________________________________|_________________|__|"
};

string personInfo_Fill[] ={
	"________________________________________________________________________________",
	"|                         Please Fill in the Details                           |",
	"|______________________________________________________________________________|",
	"|       First Name:                                       |_________________|  |",
	"|        Last Name:                                       |_________________|  |",
	"|      Nationality:                                       |_________________|  |",
	"|  Billing Address:                                       |_________________|  |",
	"|     Work Address:                                       |_________________|  |",
	"|            Email:                                       |_________________|  |",
	"|    ContactNumber:                                       |_________________|  |",
	"|_________________________________________________________|_________________|__|"
};

string personInfo_ShowInfo[] ={
	"________________________________________________________________________________",
	"|                       Showing Complete Person Details                        |",
	"|______________________________________________________________________________|",
	"|       First Name:                                       |_________________|  |",
	"|        Last Name:                                       |_________________|  |",
	"|      Nationality:                                       |_________________|  |",
	"|  Billing Address:                                       |_________________|  |",
	"|     Work Address:                                       |_________________|  |",
	"|            Email:                                       |_________________|  |",
	"|    ContactNumber:                                       |-----------------|  |",
	"|       Price Paid:                                       |                 |  |",
	"|_________________________________________________________|_________________|__|"
};

const string
	WelcomeMessage[] = {
	"________________________________________________________________________________",
	"|______________________________________________________________________________|",
	"|  |________||_______|                                     |_______||_______|  |",
	"|  |________||_______|      Welcome to Mapua Car Sales     |_______||_______|  |",
	"|  |________||_______| ___________________________________ |_______||_______|  |",
	"|  |________||_______| |  [B]uy  |   [S]ell   |  [Q]uit  | |_______||_______|  |",
	"|  |________||_______| |_________|____________|__________| |_______||_______|  |",
	"|__|________||_______|_____________________________________|_______||_______|__|"
	},

	QuitMessage[] = {
	"________________________________________________________________________________",
	"|______________________________________________________________________________|",
	"| |________||_______|                                      |________||_______| |",
	"| |--------||_______| Are you sure you want to quit?[y/n]: |________||_______| |",
	"|_|________||_______|______________________________________|________||_______|_|"
	},

	NewMessage = ""
	;

