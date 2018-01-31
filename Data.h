#ifndef Data_h
#define Data_h
void displayMenu();
void choices();
void login();
void bookTicket();
void initialize( char form[][5]);
void getData(char& ticketType, int& row2, int& column2);
void displayAllPassenger();
void cancelPassenger();
void addPassenger();
void Show_Chart();
void initialize();
void quit();
void editPassengerInformation();
using namespace std;

class Human{

    private:
        string ic, firstname, lastname, passport, tel;

    public:
        Human(string fname,string lname,string p_ic,string p_tel,string p_passport){
            firstname=fname;
            lastname=lname;
            ic=p_ic;
            tel=p_tel;
            passport=p_passport;
        }

        string getFirstName(){
            return firstname;
        }

        string getLastName(){
            return lastname;
        }

        string getIc(){
            return ic;
        }

        string getTel(){
            return tel;
        }
        string getPassport(){
            return passport;
        }
};
class Passenger: public Human{


    public:
        Passenger(string fname,string lname,string p_ic,string p_tel,string p_passport) : Human(fname,lname,p_ic,p_passport,p_tel){
        }

};

#endif
