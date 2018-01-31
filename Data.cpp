#include<iostream>
#include<cctype>
#include<iomanip>
#include <cstdlib>
#include <fstream>//file stream
#include <sstream>//string stream
#include <string>
#include<stdio.h>
#include<stdlib.h>
#include "Data.h"

using namespace std;
const char FULL = '*';			//Seat taken
const char EMPTY = '#';
const int rows = 4;			   //Number of rows
const int columns = 5;
char map [rows][columns];
int seat = 450;
int seat2 = 0;
int Quit = 1;
int row2, column2;
int answer;




bool searchIc(string key){

     string line;
     bool search = false;

     ifstream passengerfile ("passenger.txt");

     if (passengerfile.is_open()){
        string ic;

            while ( getline(passengerfile, line) ){
                std::istringstream tokenizer(line);
                getline(tokenizer, ic, ',');

                if(key==ic)
                    search = true;
            }
            passengerfile.close();
        }
      else cout << "\nIc Successful.\n";
      return search;
}
void displayMenu(){ //menu interface
system("COLOR D"); //colour
system("CLS");      //clear screen
        cout<<"+=========================================================+ "<<endl;
        cout<<"|     Airline Ticket Booking System                       | "<<endl;
        cout<<"+=========================================================+ "<<endl;
        cout<<"|     Please select your choice from option below :       | "<<endl;
        cout<<"|                                                         |"<<endl;
        cout<<"|  1) BOOK AIRLINE TICKET                                 | "<<endl;
        cout<<"|  2) EDIT TICKET INFORMATION                             | "<<endl;
        cout<<"|  3) VIEW TICKET INFORMATION                             | "<<endl;
        cout<<"|  4) VIEW AVAILABLE SEATS                                | "<<endl;
        cout<<"|  5) CANCEL TICKET                                       | "<<endl;
        cout<<"|  6) QUIT THIS SYSTEM                                    | "<<endl;
        cout<<"+=========================================================+"<<endl;

}
void choices(){  //select choice for menu
string ans;
    int choice;

    do{

            displayMenu();

            cout<< "Please enter your choice and press enter key: ";
            cin>>choice;

            if(choice==1)
            {
                addPassenger();
                bookTicket();
            }
            else if(choice==2)
            {
                editPassengerInformation();
            }
            else if(choice==3)
            {
                displayAllPassenger();
            }
            else if(choice==4)
            {
                Show_Chart();
            }
            else if(choice==5)
            {
                cancelPassenger();
            }
            else if(choice==6)
            {
                quit();
            }
            else
            {
                cout<< "Invalid Input!!"<<endl;
            }

        cout<< "Press any key and enter key to continue: ";
        cin>>ans;
        }

    while(choice>0 ||choice<2);
}
void login(){ //login
system("COLOR F");
string username="";//initialize
string password="";//initialize
bool loginsuccess=false;

do
{   system("CLS");
    cout<<"\t==========="<<endl;
    cout<<"\tUSER LOGIN"<<endl;
    cout<<"\t==========="<<endl;
    cout<<"Username: ";
    cin>>username;
    cout<<"Password: ";
    cin>>password;
    if (username=="Admin"&&password=="admin123") {
        system("COLOR A");
        cout<<"\nSuccessful login, You may continue now..."<<endl<<endl;
        loginsuccess=true;
        system("PAUSE");
    }
    else{
        system("COLOR C");
        cout<<"Incorrect username or password."<<endl;
        cout<<"Please try again."<<endl<<endl;
        system("PAUSE");
        }
    }
while(!loginsuccess);
}
void bookTicket(){  //to book ticket
system("CLS");
    Show_Chart();   //show seat
    char ticketType;
    int counter=0;
    cout << "Purchase a Ticket\n\n";
				do
				{
				    getData(ticketType,row2,column2);
					if (map [row2-1] [column2-1] == '*')
						{
							cout << "Sorry that seat is sold-out, Please select a new seat.";
							cout << endl;
						}

					else
					{
						cout << "Confirm Purchase? Enter (1 = YES / 2 = NO)";
						cin >> answer;
						while (answer<1||answer>2)
                            {
                                cout << "Invalid Input."<<endl;
                                cout << "Confirm Purchase? Enter (1 = YES / 2 = NO)";
                                cin >> answer;
                            }

						if (answer == 1)
						{
							cout << "Your ticket purchase has been confirmed." << endl;
							map [row2-1][column2-1] = FULL;
							counter = counter + 1;
						}
						else if (answer == 2)
						{
							cout << "Would you like to look at another seat? (1 = YES / 2 = NO)";
							cout << endl;
							cin >> Quit;
							while (Quit<1||Quit>2)
                            {
                                cout << "Invalid Input."<<endl;
                                cout << "Would you like to look at another seat? (1 = YES / 2 = NO)";
                                cout << endl;
                                cin >> Quit;
                            }
						}

						cout << "Would you like to look at another seat?(1 = YES / 2 = NO)";
						cin >> Quit;
						while (Quit<1||Quit>2)
                        {
                            cout << "Invalid Input."<<endl;
                            cout << "Would you like to look at another seat?(1 = YES / 2 = NO)";
                            cin >> Quit;
                        }
					}
				}
				while (Quit == 1);
				cout << "Booked Ticket: " << counter<<endl;


}
void initialize(){ //initialize seats
     for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				map [i][j] = EMPTY;
		}
}
void getData(char& ticketType, int& row2, int& column2){ //get data for the seats
    char ans;

    cout << "The airplane has 4 rows, with 5 seats in each row. " << endl;

    cout << "Enter ticket type,\n"
         << "F for first class, \n"
         << "E for economy class:" << endl;
    cin >> ticketType;
    ticketType = static_cast<char>(toupper(ticketType));
    while(ticketType != 'F' && ticketType && ticketType != 'E')
    {
        cout << "Invalid ticket type." << endl;
        cout << "Enter ticket type,\n"
             << "F for first class, \n"
             << "E for economy class:" << endl;
        cin >> ticketType;
        ticketType = static_cast<char>(toupper(ticketType));
     }
     if(map[0][4]=='*')
    {
        cout<< "First Class seat is fulled. Do you accept economy class? "<<endl;
        cin>>ans;
    }
        if(ans=='y')
        {
            goto eco;
        }
         else if (ans=='n') {
            choices();
        }
    else if(map[1][4]=='*'&&map[2][4]=='*'&&map[3][4]=='*')
        {
        cout<< "Economy Class seat is fulled. Do you accept First class? "<<endl;
        cin>>ans;
        }
        if(ans=='y')
        {
            goto first;
        }
        else if (ans=='n'){
            choices();
        }


    switch(ticketType)
    {
           case 'F':
               first:
                cout <<  "Row 1 is first class,\n" ;
                cout << "Enter the row number you want to sit: " << endl ;
                cin >> row2;
                while(row2!=1)
                {
                    cout << "Invalid row type." << endl;
                    cout << "Enter the row number you want to sit: " << endl ;
                    cin >> row2;

                }
                break;
           case 'E':
               eco:
            cout <<  "row 2 through 4 are economy class." << endl;
                cout << "Enter the row number you want to sit: " << endl ;
                cin >> row2;
                while((row2!=2)&&(row2!=3)&&(row2!=4))
                {
                    cout << "Invalid row type." << endl;
                    cout << "Enter the row number you want to sit: " << endl ;
                    cin >> row2;
                }
                break;
    }// end switch



    cout << "Enter the seat number (from 1 to 5). " << endl;
    cin >> column2;
    column2 = static_cast<char>(toupper(column2));

    while(column2<1 || column2>5)
          {
              cout << "Invalid column type." << endl;
              cout << "Enter the seat number (from 1 to 5). " << endl;
              cin >> column2;
              column2 = static_cast<char>(toupper(column2));
          }
}
void addPassenger(){ //add passenger
    system("CLS");
    string fname,lname, ic, tel, passport;
    int choice;
    cout<<"==================="<<endl;
    cout<<"ADD A NEW PASSENGER"<<endl;
    cout<<"==================="<<endl<<endl;

    cout<<"IC: ";
    cin>>ic;

    if(!searchIc(ic)){

        cout<<"First Name: ";
        cin>>fname;
        cout<<"Last Name: ";
        cin>>lname;
        cout<<"Passport: ";
        cin>>passport;
        cout<<"Phone no.: ";
        cin>>tel;

            Passenger obj (fname,lname,ic,tel,passport);

            ofstream pasfile ("passenger.txt",ios::out | ios::app);

            if (pasfile.is_open())
            {
                pasfile << obj.getIc() << ",";
                pasfile << obj.getFirstName() << ",";
                pasfile << obj.getLastName() << ",";
                pasfile << obj.getPassport() <<",";
                pasfile << obj.getTel() << '\n';

                pasfile.close();
                cout << "\nRecord successfully added.\n" << endl;
            }
            else
            {
                cout << "\nIc successful\n."<<endl;
            }


   }
   else
    {
    cout << "Sorry. The passenger record already exists." << endl << endl;
    }
}
void editPassengerInformation(){ //edit
    system("COLOR B");
    system("CLS");
    string line, editIc;

    cout<<"======================="<<endl;
    cout<<"EDIT PASSENGER INFORMATION"<<endl;
    cout<<"======================="<<endl<<endl;

    cout << "Enter  IC: ";
    cin >> editIc;
    cout<<endl<<endl;

    //if id exists in file
    if(searchIc(editIc)){

        string ic, firstname, lastname, tel, passport;
        ifstream pas;

        pas.open("passenger.txt");
        ofstream temp;
        temp.open("temp.txt");

        while (getline(pas,line))
        {
            std::istringstream tokenizer(line);
                getline(tokenizer, ic, ',');
                getline(tokenizer, firstname, ',');
                getline(tokenizer, lastname, ',');
                getline(tokenizer, passport, ',');
                getline(tokenizer, tel);

            //for matched ID
            if (ic == editIc)
            {
                cout<<"====================="<< '\n';
                cout<<"PASSENGER INFORMATION"<< '\n';
                cout<<"====================="<< '\n';
                cout<<"IC: "<<ic << '\n';
                cout<<"First Name: "<< firstname << '\n';
                cout<<"Last Name: "<< lastname << '\n';
                cout<<"Passport: "<< passport << '\n';
                cout<<"Phone No."<< tel << endl << endl << endl;
                cout<<"===================="<< '\n';
                cout<<""<< '\n';
                cout<<"===================="<< '\n';
                cout<<"\nFirst Name: ";
                cin>>firstname;
                cout<<"Last Name: ";
                cin>>lastname;
                cout<<"\nPassport: ";
                cin>>passport;
                cout<<"Phone no.: ";
                cin>>tel;


            }
            temp<<ic << ",";
            temp<<firstname << ",";
            temp<<lastname << ",";
            temp<<passport<< ",";
            temp<<tel << '\n';

        }
        temp.close();
        pas.close();
        remove("passenger.txt");
        rename("temp.txt","passenger.txt");
        cout << "\nRecord successfully edited.\n" << endl;
    }
    else cout << "\nSorry. Record not found." << endl << endl;
}
void displayAllPassenger(){ //display details
system("COLOR E");
    system("CLS");
    string line;
    ifstream passengerfile ("passenger.txt");

    if (passengerfile.is_open())
    {
        cout<<"=================="<<endl;
        cout<<"VIEW ALL PASSENGER"<<endl;
        cout<<"=================="<<endl<<endl;

        while ( getline(passengerfile, line) ){

            string ic,fname,lname,tel,passport;

            std::istringstream tokenizer(line);
                getline(tokenizer, ic, ',');
                getline(tokenizer, fname, ',');
                getline(tokenizer, lname, ',');
                getline(tokenizer, passport, ',');
                getline(tokenizer, tel, ',');
                cout<<"Passenger "<<ic<<endl<<endl;
                cout<<"IC: "<<ic <<endl;
                cout<<"First Name: "<<fname<<endl;
                cout<<"Last Name: "<<lname <<endl;
                cout<<"Passport: "<<passport<<endl;
                cout<<"Phone No.: "<<tel<<endl;
                cout<<"==========================================="<<endl<<endl;
        }
        passengerfile.close();
    }
    else cout << "Failed to open file.";
}
void cancelPassenger(){
    system("COLOR C");
    system("CLS");
    string line, deleteIC;

    cout<<"========================="<<endl;
    cout<<"DELETE EXISTING PASSENGER"<<endl;
    cout<<"========================="<<endl<<endl;

    cout << "Enter PASSENGER Ic to delete: ";
    cin >> deleteIC;
    cout<<endl<<endl;

    //if id exists in file
    if(searchIc(deleteIC)){
        string ic, fname, lname, tel, passport;

        ifstream pas;
        pas.open("passenger.txt");

        ofstream temp;
        temp.open("temp.txt");

        while (getline(pas,line))
        {
            std::istringstream tokenizer(line);
            getline(tokenizer, ic, ',');

            //write record to be retained to temp file
            if (ic != deleteIC)
            {
                getline(tokenizer, fname, ',');
                getline(tokenizer, lname, ',');
                getline(tokenizer, passport, ',');
                getline(tokenizer, tel, ',');

                temp<<ic << ",";
                temp<<fname << ",";
                temp<<lname << ",";
                temp<<passport << ",";
                temp<<tel << ",";

            }
        }

        temp.close();
        pas.close();
        remove("passenger.txt");
        rename("temp.txt","passenger.txt");
        cout << "\nRecord successfully deleted.\n" << endl;
    }
    else cout << "\nSorry. Record not found." << endl << endl;
}
void Show_Chart (){ //show available seat in 2d array shape
    system("CLS");
    cout<<"==================="<<endl;
    cout<<"VIEW AVAILABLE SEAT"<<endl;
    cout<<"==================="<<endl<<endl;

	cout << "\tSeats" << endl;
	cout << "      1 2 3 4 5\n";
		for (int count = 0; count < 4; count++)
		{
			cout << endl << "Row " << (count + 1);
			for (int count2 = 0; count2 < 5; count2++)
			{
				cout << " " <<  map [count] [count2];
			}
		}
			cout << endl;
}
void quit(){ //quit system
std::ofstream ofs;
    ofs.open("passenger.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    system("pause");
    exit(0);
}





