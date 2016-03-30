/*
 * Programmers: 1. Valdez III, Noli M.
 *              2. Reyes, John Henry
 *              3. Ocampo, E.G.
 *				4. Espiritu, Shenica
 *				5. Castillo, Carlo
 *
 *          Title: Car Sales
 * Course/Section: CS127L/BC2
 *           Date: 4th Quarter / SY:2013-2014
 *      Professor: Gloren S. Fuentes
 *
 *  Info:
 *              This program will.... blah balh blah
 *
 *  Notes:
 *				Final
 */

#include<iostream>  //for i/o
#include<fstream>   //for file streaming
#include<conio.h>   //for _getch()
#include<windows.h> //for gotoxy
#include<string>

#include"carInfo.h" // Header file for car information
#include"text.h" //Strings

using namespace std;

//global declaration for car data
car *CarData;
//number of cars in carData
int CarsTotal = 0;

/////////////////////////////////////////////////////////////////
//Reference: http://www.cplusplus.com/forum/general/33846/     //
//Precondition: get two integers                               //
//Postcondition: sets the two integers as new cursor coordinate//
void gotoxy(int x, int y);                                     //
//Returns X coordinate of the cursor                           //
int wherex();                                                  //
//returns Y coordinate of the cursor                           //
int wherey();                                                  //
/////////////////////////////////////////////////////////////////

//Show Welcome Screen
//returns user choice
char Welcome();
//confirm quit
//returns confirmation
bool Quit();

//Write all data on a text file
void writeToFile();
//Read all data from a text file
void readFromFile();

//Do this if user is buying a car
void Buy();
//Do this if user is selling a car
void Sell();

//Show All Available Cars
void ShowInventory();

//Show Car details
//return y/n if user wants to buy or nmot
char ShowCar(int);
void deleteCar(int);
//Show Sold Cars
void ShowSales();

//Promts if user input is invalid
//Clears if valid
void promtInvalid(string,int);

//get Car information to sell
//returns car data
car getCarInfo();
//store car info on database
void storeCar(const car newCar[]);

//Loading
//Enter Number of seconds and Loading Message
void Load(int Time, string Message);

/*
 * CarSales
 */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////Main()
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	system("cls");

	readFromFile(); //if there is a text file containing cars
					// then load it to the CarData struct
					// else continue
	cout << endl << endl << endl << " Loading Program please wait..." << endl;
	Load(10," "); // load for N seconds
				 // kunwari lang

	while(true)
	{ 
		char choice = Welcome();
		Load(3,"Loading...");
		if( choice =='b') // the user is buying 
		{
			Buy(); //if there is no car to sell, prompt
							 //the user then go back to welcome screen
		}
		else if(choice == 's')// the user is trying to sell
		{
			Sell(); //if input is valid, then save to text file.
				    // else promt and try again.
		}
		else if(Quit()) //if quitting, then break from while;
			       break;
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////Buy()
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Buy()
{
	ShowInventory();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////ShowInventory()
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ShowInventory()
{
	restart:
	system("cls");
		cout << "________________________________________________________________________________"
			 << "|                            Showing All Cars                                  |"
			 << "|______________________________________________________________________________|"
			 << "| #  |  Brand         |  Name              |  Color     |  Price               |"
			 << "|____|________________|____________________|____________|______________________|";

								for(int i = 0 ; i < CarsTotal ; i++) //print all cars.
								{
									gotoxy(0,i+5);
									cout << "| " << i+1;
									gotoxy(4,i+5);
									cout << " |  " << CarData[i].Brand.substr(0,13);
									gotoxy(21,i+5);
									cout << "                                 ";
									gotoxy(21,i+5);
									cout << " |  " << CarData[i].CarName.substr(0,17);
									gotoxy(42,i+5);
									cout << "                                 ";
									gotoxy(42,i+5);
									cout << " |  " << ColorStr[static_cast<int>(CarData[i].CarColor)];
									gotoxy(55,i+5);
									cout << " |  " << "Php " << CarData[i].Price;
									gotoxy(78,i+5);
									cout << " |";
								}
	
	if( CarData[0].Brand != "no data")
	{
		cout << "|____|________________|____________________|____________|______________________|"
			 << "|                                                                              |"
			 << "|   Enter Number of Car:                             **enter zero(0) to quit** |"
			 << "|______________________________________________________________________________|";
		int bottomY = wherey()-2; // go to the bottom then up 2 rows.
		try
		{
			int choice = -1;
			while(true)
			{
				try
				{
					gotoxy(25, bottomY); //go beside Number of car: 
					cin >> choice;
					if(cin.fail()) //if choice is improper; fix it
						throw 0;
					else if(choice == 0)//goto quitting if user wants to quit
						throw 1;
					else if(choice < 1 || choice > CarsTotal)//check if the car exist
						throw 3;

					if(ShowCar(choice-1) == 'n') //if car exist, then show car details
						goto restart; // if the user does not want to buy the car, pick again
					else 
						deleteCar(choice - 1);//delete selected car from Cardata
					break;
				}
				catch(int e)
				{
					gotoxy(0, bottomY); //clear prevo\ious entry
					cout << "|   Enter Number of Car:                                                       |";

					if(e == 0 ) //if the input is not a number, fix it
					{
						cin.clear();
						cin.ignore(1000,'\n');
						
					}
					else if(e == 1)//if user wants to quit (pressed 0)
						break;
					else if(e == 2)//if the number input is not in range
					{
						gotoxy(0,bottomY+2); //goto bottom
						cout << "|                     ***That Car does not exist***                            |"
							 << "|______________________________________________________________________________|";
					}
				}
			}

		}
		catch(int e){}//empty catch
	}// if there is no data then promt: carData->Brand == no data
	else
	{
		cout << "|                                                                              |";
		cout << "|                No Car is Available Please Check Again later.                 |";
		cout << "|______________________________________________________________________________|";
		cout << endl;
		system("pause");
	}

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////ShowCar()
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
char ShowCar(int CarIndex)
{
	system("cls");
	//show frame
	for(int i = 0 ; i < Lenght_carDetails; i++)
	{
		cout << carDetails_ShowInfo[i];
	}

	int Y = 3; // third row is where brand starts
	gotoxy(20,Y++); // always go beside the label while user input
	cout << CarData[CarIndex].Brand.substr(0,30);
	gotoxy(20,Y++);
	cout << CarData[CarIndex].CarName.substr(0,30);
	gotoxy(20,Y++);
	cout << ColorStr[static_cast<int>(CarData[CarIndex].CarColor)];
	gotoxy(20,Y++);
	cout << CarData[CarIndex].Efficiency;
	gotoxy(20,Y++);
	cout << CarData[CarIndex].Speed;
	gotoxy(20,Y++);
	cout << CarData[CarIndex].DryWeight;
	gotoxy(20,Y++);
	cout << EngineStr[static_cast<int>(CarData[CarIndex].Engine)]; //convert enum to string by using the parallel string array
	gotoxy(20,Y++);
	cout << TransmissionStr[static_cast<int>(CarData[CarIndex].Transmission)];
	gotoxy(20,Y++);
	cout << CarData[CarIndex].ManufactureDate.Day << " " << CarData[CarIndex].ManufactureDate.Month << " "
		 << CarData[CarIndex].ManufactureDate.Year;
	gotoxy(20,Y++);
	cout << CarData[CarIndex].Price;


	gotoxy(0,++Y);// go to the bottom
	cout << "|                                                                              |"
		 << "|                 Would you like to buy this car? [y/n]                        |"
		 << "|______________________________________________________________________________|";
	do
	{
		char choice = tolower(_getch()); //get choice until correct
		if(choice == 'y'|| choice == 'n')
		{
			return choice;
		}
	}while(true);
}

void deleteCar(int index)
{
	car *swap = CarData;
	CarData = new car[--CarsTotal];//assign a new container for cardata 
								   // equals to CarsTotal minus 1
	int j = 0;// i and j won't be parallel if an i is deleted or ignored
	for(int i = 0 ; i < CarsTotal+1; i++) // copy all swap to carData
	{	
		if(i==index)//delete car by ignoring from copy
		{
			if(j > 0) // j must not be less than 0 or error
			    --j; //to prevent an empty array when one i is deleted, j must step backward
			continue;
		}
		CarData[j] = swap[i]; //keep copying swap to Cardata
		j++;//increment j parallel to i
	}

	if(CarsTotal == 0)//rewrite the sentinel if all cars is deleted
	{
		CarData = new car(); //temporary create a new car to save the sentinel value
		CarData->Brand="no data";
	}

	Load(5,"Buying Car...");
	storeCar(CarData); // rewrite datafile with the new carData
	system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////Sell()
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Sell()
{
	//initialize a container for a new car
	car *NewCar = new car();

	//get data to sell car
	*NewCar = getCarInfo();

	//use function to save the data
	Load(3,"Saving...");

	//save car to CarData
	storeCar(CarData);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////storeCar()
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void storeCar(const car newCar[])
{
	//rewirite textfile with new values
	ofstream write(datafile);

	for(int i=0; i < CarsTotal; i++)
	write  << endl << newCar[i].Brand << endl
			<< newCar[i].CarName << endl
			<< newCar[i].CarColor << endl
			<< newCar[i].Efficiency << endl
			<< newCar[i].Speed << endl
			<< newCar[i].DryWeight << endl
			<< newCar[i].Engine << endl
			<< newCar[i].Transmission << endl
			<< newCar[i].ManufactureDate.Day << ' ' << newCar[i].ManufactureDate.Month << ' ' << newCar[i].ManufactureDate.Year << endl
			<< newCar[i].Price;
	//close the file stream after writing
	write.close();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////readFromFile()
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void readFromFile()
{
	CarsTotal = 0; //assume no car is available
	CarData = new car(); //allocate space to write the sentinel
	CarData->Brand = "no data"; //incase there is no data.txt or there is no car available
								//write the sentinel

	ifstream read(datafile);//open data.txt
	string x; //temp storage to get newline sentinel
	getline(read,x);
	if(x!="")//if textfile is corrupted or edited outside the program, prompt then try to delete the text file
	{
		cout << "\n\n***********************************************************\n"
			 <<     "**Sorry, something went wrong while reading the text file**\n"
			 <<     "***********************************************************\n";
		Load(10,"Fixing / Deleting Wrong data...");
		storeCar(CarData);
		
	}
	else
	while(read.good())
		{
			car getCar;
			int tmp;;
			//get car data here
			getline(read,getCar.Brand);
			getline(read,getCar.CarName);
			read >> tmp; getCar.CarColor = static_cast<color>(tmp);
			read >> getCar.Efficiency;
			read >> getCar.Speed;
			read >> getCar.DryWeight;
			read >> tmp; getCar.Engine = static_cast<engine>(tmp);
			read >> tmp; getCar.Transmission = static_cast<transmission>(tmp);
			read >> getCar.ManufactureDate.Day >> getCar.ManufactureDate.Month >> getCar.ManufactureDate.Year;
			read >> getCar.Price;
			getline(read,x); // go to nextline
			//////////////////////////

			car *swap = new car[CarsTotal];
			swap = CarData;
			CarData = new car[++CarsTotal];

			for(int i = 0; i < CarsTotal-1; i++)
			{
				CarData[i] = swap[i];
			}

			CarData[CarsTotal-1] = getCar;
		}
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////Welcome()
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
char Welcome()
{
	system("cls");
	gotoxy(0,4);
	//show welcome screen message
	//ask if the user wants to buy, or sell
	for(int i = 0 ; i < Lenght_WelcomeMessage; i++)
		cout << WelcomeMessage[i];

	//get choice
	do
	{
		char choice = tolower(_getch());
		if(choice == 'b' || choice == 's' || choice == 'q') // buy | sell
			return choice;
	}while(true);//unless the user pick the right choice, the loop wont break;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////Quit()
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Quit()
{
	system("cls");
	cout << endl << endl << endl; // endline para gumitna

	//Show Quit message Screen
	//and ask if the user wants to quit
	for(int i = 0; i < Lenght_QuitMessage; i++)
		cout << QuitMessage[i];
	
	//get choice
	do
	{
		char choice= tolower(_getch());
		if(choice == 'y') // no | yes
		{
			Load(3,"Quitting...");  // kunwari naglo-load  :)
			return true;
		}
		else if( choice == 'n' )
			return false;
	}while(true);//unless the user pick the right choice, the loop wont break;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////getCarInfo()
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
car getCarInfo()
{
	system("cls");
	car *NewCar = new car();
	
	cout << endl << endl;
	for(int i = 0 ; i < Lenght_carDetails ; i++) //print the carDetails table
		cout << carDetails_Fill[i];
	
	//Brand is in x=20, y=3
	int Y=4,X=20; //sets the relative coordinate
	gotoxy(X,Y);

	//Using do while
	////////////////////////Brand///////////////////////
	do
	{
		gotoxy(0,Y+1); //go to respective row
		cout << carDetails_Fill[3]; //fix prompt 

		gotoxy(X,Y+1); //go beside the brand label
		getline(cin,NewCar->Brand);
		if(NewCar->Brand=="" || NewCar->Brand=="\n"|| NewCar->Brand=="\r")//if there is no user input, don't accept
		{
			promtInvalid("Please Enter A Brand!",Y+1);//print a promt at the bottom
			continue;
		}
		promtInvalid("",0); //clear the promt at the bottom
		break;
	}while(true);
	cin.clear();

	//Using try-catch
	//following lines are just the same, use comments from car name as reference
	/////////////////////CarName///////////////////////
	while(true)
	{
		int addY = 2;
		try{
			gotoxy(0,Y+addY); //go to respective row
		    cout << carDetails_Fill[4]; //fix promt incase user input overlaps
			gotoxy(X,Y+addY); //go beside the proper label
			getline(cin,NewCar->CarName); 
			switch(NewCar->CarName[0])
			{
				case NULL: //if there is no user input, don't accept
				case ' ': //if the user types a space first, don't accept
				case '\n': //if user just pressed enter, don't accpet it
				case '\r': //if user just pressed enter, don't accpet it
					throw 0;
			}
			promtInvalid("",0); //clear the promt at the bottom
			break;
		}
		catch(int e)
		{
			promtInvalid("Please Enter A Name!",Y+addY); //print a promt at the bottom
			continue;
		}
	}

	/////////////////////CarColor///////////////////////
	while(true)
	{
		int addY = 3;
		string Color;
		try{
			gotoxy(0,Y+addY);
		    cout << carDetails_Fill[5];
			gotoxy(X,Y+addY);
			getline(cin,Color);
			for(int i = 0; i < 8; i++)
			{
				if( ColorStr[i] == Color  )  //Case Sensitive
				{
					NewCar->CarColor = static_cast<color>(i);
					promtInvalid("",0);
					throw 1;
				}
			}
			throw 0;
		}
		catch(int e)
		{
			if( e == 1)
				break;
			promtInvalid("Please enter a valid color (ROYGBV WGB)!",Y+addY);
			continue;
		}
	}

	/////////////////////Efficiency///////////////////////
	while(true)
	{
		int addY = 4;
		try{
			gotoxy(0,Y+addY);
		    cout << carDetails_Fill[6];
			gotoxy(X,Y+addY);
			cin >> NewCar->Efficiency;
			if(cin.fail())
				throw 0;
			else if(NewCar->Efficiency < 0 || NewCar->Efficiency > 100)
				throw 1;
			promtInvalid("",0);
			break;
		}
		catch(int e)
		{
			cin.clear();
			cin.ignore(1000,'\n');
			promtInvalid("Please Enter a number (Miles Per Gallon) less than 100!",Y+addY);
			continue;
		}
	}

	/////////////////////Speed///////////////////////
	while(true)
	{
		int addY = 5;
		try{
			gotoxy(0,Y+addY);
		    cout << carDetails_Fill[7];
			gotoxy(X,Y+addY);
			cin >> NewCar->Speed;
			if(cin.fail())
				throw 0;
			else if(NewCar->Speed < 0 || NewCar->Speed > 400)
				throw 1;
			promtInvalid("",0);
			break;
		}
		catch(int e)
		{
			cin.clear();
			cin.ignore(1000,'\n');
			promtInvalid("Please Enter a positive number (Miles per Hour) less than 400!",Y+addY);
			continue;
		}
	}

	/////////////////////Weight///////////////////////
	while(true)
	{
		int addY = 6;
		try{
			gotoxy(0,Y+addY);
		    cout << carDetails_Fill[8];
			gotoxy(X,Y+addY);
			cin >> NewCar->DryWeight;
			if(cin.fail())
				throw 0;
			else if(NewCar->DryWeight < 0)
				throw 1;
			promtInvalid("",0);
			break;
		}
		catch(int e)
		{
			cin.clear();
			cin.ignore(1000,'\n');
			promtInvalid("Please Enter a positive number in Pounds)!",Y+addY);
			continue;
		}
	}

	/////////////////////Engine///////////////////////
	while(true)
	{
		int addY = 7;
		string Engine;
		try{
			gotoxy(0,Y+addY);
		    cout << carDetails_Fill[9];
			gotoxy(X,Y+addY);
			getline(cin,Engine);
			if(cin.fail())
				throw 2;
			for(int i = 0; i < 2; i++)
			{
				if( EngineStr[i] == Engine  )  //Case Sensitive
				{
					NewCar->Engine = static_cast<engine>(i);
					promtInvalid("",0);
					throw 1;
				}
			}
			throw 0;
		}
		catch(int e)
		{
			if(e == 2)
			{
				cin.clear();
				cin.ignore(1000,'\n');
			}
			else if( e == 1)
				break;
			promtInvalid("Please enter a \"diesel\" or \"gas\"!",Y+addY);
			continue;
		}
	}

	/////////////////////Transmission///////////////////////
	while(true)
	{
		int addY = 8;
		string Transmission;
		try{
			gotoxy(0,Y+addY);
		    cout << carDetails_Fill[10];
			gotoxy(X,Y+addY);
			getline(cin,Transmission);
			for(int i = 0; i < 2; i++)
			{
				if( TransmissionStr[i] == Transmission  )  //Case Sensitive
				{
					NewCar->Transmission = static_cast<transmission>(i);
					promtInvalid("",0);
					throw 1;
				}
			}
			throw 0;
		}
		catch(int e)
		{
			if( e == 1)
				break;
			promtInvalid("Please enter a \"auto\" or \"manual\"!",Y+addY);
			continue;
		}
	}

	/////////////////////Manufacture Date///////////////////////
	while(true)
	{
		int addY = 9;
		try{
			gotoxy(0,Y+addY);
		    cout << carDetails_Fill[11];
			gotoxy(X,Y+addY);
			cin >> NewCar->ManufactureDate.Day;
			gotoxy(X+3,Y+addY);
			cin >> NewCar->ManufactureDate.Month;
			gotoxy(X+6,Y+addY);
			cin >> NewCar->ManufactureDate.Year;
			if(cin.fail())
				throw 0;
			else if(NewCar->ManufactureDate.Day < 1 || NewCar->ManufactureDate.Day > 31)
				throw 1;
			else if(NewCar->ManufactureDate.Month < 1 || NewCar->ManufactureDate.Month > 12)
				throw 2;
			else if(NewCar->ManufactureDate.Year < 1920)
				throw 3;
			else if(NewCar->ManufactureDate.Year > 2014)
				throw 4;
			promtInvalid("",0);
			break;
		}
		catch(int e)
		{
			switch(e)
			{
				case 0:
					cin.clear();
					cin.ignore(1000,'\n');
					promtInvalid("Please Enter a positive number [dd mm yyyy]!",Y+addY);
					break;
				case 1:
					promtInvalid("Days must be from 1-31! [dd mm yyyy]",Y+addY);
					break;
				case 2:
					promtInvalid("Months must be from 1-12! [dd mm yyyy]",Y+addY);
					break;
				case 3:
					promtInvalid("We Don't Accept Old Cars! [dd mm yyyy]",Y+addY);
					break;
				case 4:
					promtInvalid("We Don't Accept cars from the \"future\"! [dd mm yyyy]",Y+addY);
					break;
			}
			
			continue;
		}
	}

	/////////////////////Price///////////////////////
	while(true)
	{
		int addY = 10;
		try{
			gotoxy(0,Y+addY);
		    cout << carDetails_Fill[12];
			gotoxy(X,Y+addY);
			cin >> NewCar->Price;
			if(cin.fail())
				throw 0;
			else if(NewCar->Price < 0)
				throw 1;
			promtInvalid("",0);
			break;
		}
		catch(int e)
		{
			if( e == 0)
			{
				cin.clear();
				cin.ignore(1000,'\n');
			}
			promtInvalid("Please Enter a positive number in Phillipine Peso!",addY);
			continue;
		}
	}
	promtInvalid("",0);
	system("pause");
	gotoxy(0,wherey()-1);
	cout << "                                                                               \r";
	gotoxy(0,wherey()-2);

	//add to car data.
	car *swap = CarData;
	CarData = new car[++CarsTotal];
	for(int i = 0 ; i < CarsTotal-1; i++)
		CarData[i] = swap[i];
	CarData[CarsTotal-1] = *NewCar;

	return *NewCar;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////promtInvalid()
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void promtInvalid(string Message,int Y)
{
	if(Message!="")//if there is a message
	{
		gotoxy(0,Lenght_carDetails+2); //goto the bottom of the table
		cout << "| ";
		int center = ( 40 - ( ( ( Message.length() + 10 ) ) / 2 ) ) - 2 ; //align center the message 
		     // Lenght of console = 80, half is 40
		     // 40 - ( ( Length of message + total number of askterisk ) / 2  ) - 2 
		     //                                       divide by two to get half center ,  minus 2 for padding
		gotoxy( center  , Lenght_carDetails+2); //center the message
		cout << "***** " << Message << " *****";
		gotoxy(79,Lenght_carDetails+2);
		cout<<"|";
		cout << "|______________________________________________________________________________|";
	}
	else //there is no message so clear prompt instead
	{
		gotoxy(0,Lenght_carDetails+2);
		cout << "                                                                                ";
		cout << "                                                                                ";
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////Load())
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Load(int Time,string Message)
{
	int padding = 2; //padding, para di sagad sa gilid, mag dadagdag lang ng spaces.
	int Blocks = 80 - padding; //length of the progress bar
	int seconds = (Time-1) * 50;   //computation: Total Time = 10miliseconds * (Seconds - 1) * 100
																// counting starts at Zero(0) so minus 1
	int y = wherey()+1; //save current y coordinate

	cout << "________________________________________________________________________________" << endl;
	gotoxy(0,y+2);
	cout << "________________________________________________________________________________" << endl;

	gotoxy(0,y);
	cout << "  " << Message << " 0% Complete " << endl; //print 0% first

	for(int i = 0; i < Blocks; i ++)
	{
		cout << LoadE; //LoadE = char(176)
	}

	//start loop, overwrite previous text using gotoxy(int,int)
	for(int i = 0; i < seconds+1; i++)
	{
		gotoxy(0,y);
		cout << "  " << Message << " " << int(((double)i / seconds)*100) << "% complete" << endl 
			 << "  ";	
		
		//for(int j = 0 ; j < 60/(seconds-i+1); j++)
		for(int j = 0 ; j < int(((double)i/seconds)*Blocks)-padding; j++)
			cout << LoadF;

		Sleep(1); // pause for 1 millisecond
	}
	gotoxy(0,y+4); // go to the end of the line
				   // para di pumatong sa next line
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////gotoxy()
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void gotoxy( int column, int line )
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle( STD_OUTPUT_HANDLE ),
		coord
		);
}

int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle( STD_OUTPUT_HANDLE ),
		&csbi
		))
		return -1;
	return csbi.dwCursorPosition.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle( STD_OUTPUT_HANDLE ),
		&csbi
		))
		return -1;
	return csbi.dwCursorPosition.Y;
}