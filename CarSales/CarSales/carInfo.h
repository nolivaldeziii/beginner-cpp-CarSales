/*
 * Struct for car Information
 * Final
 */

#include<string>
using std::string;

enum color {
	Red,
	Orange,
	Yellow,
	Green,
	Blue,
	Violet,
	White,
	Black,
	Gray
};

enum engine {
	Diesel,
	Gas
};

enum transmission {
	Auto,
	Manual
};

struct date {
	int Day;
	int Month;
	int Year;
};

struct car{
	string Brand;
	string CarName;
	color CarColor;

	double Efficiency;
	double Speed;
	double DryWeight;
	engine Engine;
	transmission Transmission;

	date ManufactureDate; //DD/MM/YYYY

	long int Price; 
};


	