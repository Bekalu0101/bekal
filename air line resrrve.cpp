//#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<string.h>
using namespace std;
void reserve_seat();
void available_flights();
void cancel_seat();
void Quit_program();
void change_seat();
int numseats=20;
int available;
int seatarray;

char l_name[30];

struct passenger
{
    char name[30];
    int pass_number;
    int cell_number;
    char address[40];
} pass;
struct Seat
{
    char pass_name[80];
    int Available;
};
struct Seat SeatArray[1][10];
int main()
{
    int c;
    cout<<"**************WELCOME TO AIRWAYS RESERVATION SYSTEM*************"<<endl;

    cout <<"All "<< numseats << " seats are available " << endl;
    cout<<"Please enter your name for login : ";
    cin>>l_name;
    system("CLS");
    cout<<" What Do You Want To Do ? "<<endl;
    cout<<"   1) Reserve Seat "<<endl;
    cout<<"   2) Main Menu "<<endl;
    cout<<"   3)available flights"<<endl;
    cout<<"  4) Cancel Seat "<<endl;
    cout<<"   5) Change Seat "<<endl;
    cout<<"   6) Quit Program "<<endl;
    cout<<"Enter Your Choice : "<<endl;
    cin>>c;
    if((c < 0) && (c > 5))
    {
        cout << "Invalid Choice" << endl;
    }
    else
        switch(c)
    {

    case 1:
        {
            c1.writeonfile();
            break;
        }
    case 2:
        {
          
            main();
            break;
        }
    case 3:
        {
            available_flights();
            break;
        }
    case 4:
        {
            cancel_seat();
            break;
        }
    case 5:
        {
            change_seat();
            break;
        }
    case 6:
        {
            Quit_program();
            break;
        }
    }
    system("pause");
}
void writeonfile()
{
   char ch;
ofstream myfile;
myfile.open("CMS.dat",ios::binariy|ios::app);
do
{
reserve_seat();
myfile.open(reinterprete_cast<char*>(this),sizeof(*this));
cout<<" do you want to reserve again y/n"<<endl;
cin>>ch;
}
while(ch=='y')
cout<< " reserved sucessfully"<<endl;
created...";
myfile.close;


}

void reserve_seat()
{
    int t;
    char ch;
    cout<<"************* SEAT RESEVATION **************"<<endl;
    cout<<" Please Enter Your Name : "<<endl;
    cin>>pass.name;
    cout<<" Please Enter Your Passport Number : "<<endl;
    cin>>pass.pass_number;
    cout<<" Please Enter Your Cell Number : "<<endl;
    cin>>pass.cell_number;
    cout<<" Please Enter Your Address: "<<endl;
    cin>>pass.address;
    cout<<" Please Enter Your Ticket Number :"<<endl;
    cin>>t;
    system("CLS");
    cout<<"*************Pssenger Details*************"<<endl;
    cout<<"    Passenger Name  =   "<<pass.name<<endl;
    cout<<"    Passport Number =   "<<pass.pass_number<<endl;
    cout<<"    Cell Number     =   "<<pass.cell_number<<endl;
    cout<<"    Address         =   "<<pass.address<<endl;
    cout<<"    Ticket Number   =   "<<t<<endl;
    numseats--;
    cout<<"Do you want to Enter Again(Y/N)? "<<endl;
    cin>>ch;
    {
        switch(ch)

        {
        case 'Y':
        case 'y':
        {
            reserve_seat();
            break;
        }
        case 'N':

        case 'n':
        {
            main();

            break;
        }
        }
    }
}

void available_flights()
{
    int s;
    cout<<"***********************************************************************************************************"<<endl;
    cout<<"                                           AVAILBLE FLIGHTS                "<<endl;
    cout<<"***********************************************************************************************************"<<endl;
    cout<<" Serial Number       Flight Number           From         Destination      Time            Cost "<<endl;
    cout<<"      1                  PKR-108            Karachi          Lahore        11:00pm          100$ "<<endl;

    cout<<"      2                  PKR-320            Lahore            Dubai        01:00am          250$ "<<endl;
    cout<<"      3                  PKR-170          Islamabad          Karachi       03:00pm          100$ "<<endl;
    cout<<"      4                  PKR-102            Sialkot           Paris        02:00am          500$ "<<endl;
    cout<<"      5                  PKR-101            Quetta           New York      09:00am          400$ "<<endl;
    cout<<" Enter The Serail Number Of Flight In Which You Want To Travel : "<<endl;
    cin>>s;
    if(s==1)
    {
        cout<<" Serial Number       Flight Number           From         Destination        Time            Cost "<<endl;
        cout<<"      1                  PKR-108            Karachi          Lahore       11:00pm           100$ "<<endl;
    }
    else if(s==2)
    {
        cout<<" Serial Number       Flight Number           From         Destination           Time            Cost "<<endl;
        cout<<"      2                  PKR-320            Lahore            Dubai 01:00am          250$ "<<endl;
    }
    else if(s==3)
    {
        cout<<" Serial Number       Flight Number           From         Destination           Time            Cost "<<endl;
        cout<<"      3                  PKR-170          Islamabad          Karachi03:00pm          100$ "<<endl;
    }
    else if(s==4)
    {
        cout<<" Serial Number       Flight Number           From         Destination           Time            Cost "<<endl;
        cout<<"      4                  PKR-102            Sialkot           Paris 02:00am          500$ "<<endl;
    }
    else
    {
        cout<<" Serial Number       Flight Number           From         Destination           Time            Cost "<<endl;
        cout<<"      5                  PKR-101            Quetta           New York          09:00am          400$ "<<endl;
    }
    cout<<"succesfully completed"<<endl;


}
void cancel_seat()
{
    char passenger_name[50];
    cout<<"Enter passenger name for cancelling"<<endl;
    cin>>passenger_name;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<2; j++)
        {
            if(strcmp(passenger_name,pass.name)==0)
            {
                cout<<"Seat has been cancelled..."<<endl;
                numseats++;
                available=1;
                return;
            }
        }
    }
    cout<<"Passenger Name not found..."<<endl;
}
void change_seat()

//This function is for Change the seat
{    char MovePassenger[80];
    int SeatRow, SeatColumn;
cout << "Enter the passenger name to be moved: ";
cin >> MovePassenger;
for(int i = 0; i < 5; i++)
{
    for(int j = 0; j < 2; j++)
    {
        if(strcmp(pass.name, MovePassenger) == 0)


        {
            SeatRow = i;
            SeatColumn = j;
        }
    }
}
if(numseats <= 0)
{
    cout << "No seat available there for you cannot change seat" << endl;
    return;
}
else
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 2; j++)
        {

            if(available == 1)
            {

                strcpy_s(pass.name, MovePassenger);
                SeatArray[SeatRow][SeatColumn].Available = 1;
                SeatArray[i][j].Available = 0vz;
                return;
            }
        }

    }
}
}
void Quit_program()
{
    cout<<"****************GOOD BYE FROM AIRWAYS RESERVATION SYSTEM*******************"<<endl;










}