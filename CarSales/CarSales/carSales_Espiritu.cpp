#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include<windows.h> 
using namespace std;

void buyerInfo();
void CarInformation();
void writeCarInfo();
void tryAgain();
void quit();
void menu();


struct Buyer
{
	string FirstName;
	string LastName;
	string Nationality;
	string BillingAddress;
	string WorkAddress;
	string Email;
	string ContactNumber;
	
}info;

struct Car
{
	string color;
	string engine;
	string transmission;
	int day, month, year;
	int mDay, mMonth, mYear;
	int length, width, height;
	string brand;
	string carName;
	string typeOfCar;
	double EfficiencyMetric, // Kilometers per liter / MPG
		   EfficiencyEnglish,
		   EfficiencyElec;
     
    double TankCapacity, // liter
			Battery;
			double SpeedMetric, // KPH / MPH
            SpeedEnglish;

	double DryWeightMetric, //kilo
			DryWeightEnglish; // pound
	
	int HorsePower;
	string Serial; //AAABBB123

	double Price;
}details;


int main()
{
	system("cls");
	menu();
	system ("pause");
	return 0;
}

void buyerInfo()
{

	cout<<"First Name: ";
	getline(cin,info.FirstName);
	cin.ignore();
	cout<<"Last Name: ";
	getline(cin,info.LastName);
	
}

void CarInformation()
{
	cout<<"Welcome!\n Press any key to continue";

	cin.ignore();
	system("cls");
	cout<<"Please input the car details\n";
	cout<<"            Brand: ";
	getline(cin,details.brand);
	cout<<"      Name of Car: ";
	getline(cin,details.carName);
	cout<<"            Color: ";
	getline(cin,details.color);         
	cout<<"           Engine: ",
	getline(cin,details.engine);
	cout<<"     Transmission: ";
	getline(cin,details.transmission);
	cout<<"           Serial: ";
	getline(cin,details.Serial);
	
	cout<<" [Manufacture Date]\n "
	    <<"            Month: ";
	cin>>details.mMonth;
	cout<<"              Day: ";
	cin>>details.mDay;
	cout<<"             Year: ";
	cin>>details.mYear;
	cout<<"            Price: ";
	cin>>details.Price;
	cout<<"   \n   [Efficiency]\n "
	    <<"       in METRIC: ";
    cin>>details.EfficiencyMetric;
    cout<<"       in ENGLISH: ";
    cin>>details.EfficiencyEnglish;
    cout<<"          in ELEC: ";
    cin>>details.EfficiencyElec;
    cout<<endl;
	cout<<"\nCapacity (maH/L): ";
	cin>>details.TankCapacity;
	cout<<"  \n      [Speed]\n "
	    <<"       in English: ";
	cin>>details.SpeedEnglish;
	cout<<"        in Metric: ";
	cin>>details.SpeedMetric;
	cout<<"  \n  [Dry Weight]\n "
	    <<"       in English: ";
    cin>>details.DryWeightEnglish;
	cout<<"        in Metric: ";
	cin>>details.DryWeightMetric;
	cout<<"      Horse Power: ";
	cin>>details.HorsePower;
	cout<<"    \n     [Dimention]\n ";
	cout<<"           Length: ";
	cin>>details.length;
	cout<<"            Width: ";
	cin>>details.width;
	cout<<"           Height: ";
	cin>>details.height;
	cout<<endl;
		cin.ignore();
	writeCarInfo();
    
}

void writeCarInfo()
{
	
	ofstream carDet;
	string filename;
	cout<<"         Name of file: ";
	getline(cin,filename);
	carDet.open(filename.c_str());
	carDet<<
	"            Brand: "<<details.brand<<endl<<
	"      Name of Car: "<<details.carName<<endl<<
	"            Color: "<<details.color<<endl<<
	"       Efficiency: "<<details.EfficiencyElec<<" / "<<details.EfficiencyEnglish<<" / "<<details.EfficiencyMetric<<endl<<
	" Capacity (maH/L): "<<details.TankCapacity<<endl<<
	"            Speed: "<<details.SpeedEnglish<<" / "<<details.SpeedMetric<<endl<<
	"       Dry Weight: "<<details.DryWeightEnglish<<" / "<<details.DryWeightMetric<<endl<<
	"      Horse Power: "<<details.HorsePower<<endl<<
	"        Dimention: "<<details.length<<" / "<<details.width<<details.height<<endl<<
	"           Engine: "<<details.engine<<endl<<
	"     Transmission: "<<details.transmission<<endl<<
	" Manufacture Date: "<<details.mMonth<<"/"<<details.mDay<<"/"<<details.mYear<<endl<<
	"           Serial: "<<details.Serial<<endl<<
	"            Price: "<<details.Price<<endl;
	
	tryAgain();
	
}

void tryAgain()
{
	char ans;
	cout<<"Input a new Car? [y/n]: ";
	cin>>ans;
	
	tolower(ans);
	if (ans=='y')
	      CarInformation();
    else
          quit();
}

void quit()
{
	char answer;
	cout<<"Go back to menu? [y/n]: ";
	cin>>answer;
	tolower(answer);
	if (answer=='y')
	    main();
	else
	    exit( 0 );
	system("pause");
}

void menu()
{
	int sagot;
	cout<<"*************************\n"
	    <<"*     What are you?     *\n"
	    <<"*     [1] Employee      *\n"
	    <<"*     [2] Buyer         *\n"
	    <<"*     [3] Quit          *\n"
	    <<"*************************\n"
		<<"Enter choice: ";
	 cin>>sagot;
	 
	switch(sagot)
	{
		case 1: CarInformation();
		         break;
		case 2:  buyerInfo();
		         break;
		case 3:  exit ( 0 );
		         break;
	}
	
}

