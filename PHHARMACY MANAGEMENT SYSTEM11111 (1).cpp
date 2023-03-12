#include <iostream>
#include <stdlib.h>
#include <string>
//#include <cctype>
//#include <cmath>
//#include <cstdio>
#include <fstream>
//#include <iomanip>
#define max 10
using namespace std;
struct Medicine
{
 int reciept_number;
 string customerName;
 string date;
 int quantity[10];
 string type = {"OTC"};
 int x, menu2[10];
    double amount[10];
    string medicineName[10]={"Probiotics","Vitamin C(500mg)",
    "Acid Free C(500mg)","Women'S Multivate","Marino Tablet","Maxi Cal Tablet",
 "Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen"};
 double Med[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
 double total;

}M;
void take_order();
 void expiredate();
 void introduction();
 void exit();
int main()
{
 system("COLOR 89");
 int menu;
 introduction();
 system("cls");
 do
 {
  cout<<"==============================\n";
  cout<<" Pharmacy Management System - \n";
  cout<<"===========================================\n";
  cout<<"--------------------------------------------------\n";
  cout<<"1. Take new Medicine order \n";
  cout<<"2. Expire date of medicines \n";
  cout<<"3. Exit \n";
  cout<<"--------------------------------------------------\n";
  cout<<"Enter your choice: \n";
  cin>>menu;
  switch (menu)
  {

  case 1:
   {
    take_order();
    break;
   }
   case 2:
   {
    expiredate();
    break;
   }
case 3:
   {
    exit();
    goto a;
    break;
   }
  default:
   {
    cout<<"You entered invalid choice  "<<endl;
    break;
   }
  }
 }while(menu!=3);
 a:
 cout<<"Thank you"<<endl;

 ofstream fout;
 fout.open("Pharmacy Management System.txt", ios::out);
    fout<<"Reciept Number : "<<M.reciept_number;
    fout<<"n";
    fout<<"Customer Name: "<<M.customerName<<endl;

    fout<<"Order Date : "<<M.date<<endl;

    fout<<"________________"<<endl;

    fout<< "==========================================================================" << endl;
    fout<< "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
    fout<< "=======++==================++================++===============++==========" << endl;
   for (int i=0;i<M.x;i++)
   {
    fout<<M.type <<"  ";
    fout<<M.medicineName[M.menu2[i]-1]<<" ";
    fout<<M.quantity[i] <<" ";
    fout<<M.amount[i]<<" Birr"<<endl;
    fout<<"_________________"<<endl;
   }

   M.total = M.amount[0]+M.amount[1]+M.amount[2]+M.amount[3]+M.amount[4]+
   M.amount[5]+M.amount[6]+M.amount[7]
   +M.amount[8]+M.amount[9];
   fout<<"Total Bill is : "<<M.total;
   fout <<"\n___________________\n";

   fout <<"Receipt Number : "<<M.reciept_number;
    fout <<"n";
    fout<<"Customer Name: "<<M.customerName<<endl;

fout<<"Order Date : "<<M.date<<endl;
    fout <<"n";
    fout<<"Total Bill is : "<<M.total;
    cout<<"Data inserted successfully..!!";
                fout.close();
 return 0;
}
void take_order()
{
 system("cls");
 int i;
int choice, quantity, price,None;
 cout <<"\nAdd Order Details: ";
 cout <<"_________ ";
    cout <<"******************\n";
    cout<<"DRUGS ID\t"<<"DRUGS TYPE\t"<<"DRUGS NAME\t"<<"\tDRUGS PRICE(birr)"<<endl;
    cout <<"******************\n";
                cout<<"0001\t\t"<<"OTC\t\t"<<"Probiotics\t\t"<<"birr 2.00"<<endl;
                cout<<"0002\t\t"<<"OTC\t\t"<<"Vitamin C(500mg)\t"<<"birr 3.00"<<endl;
                cout<<"0003\t\t"<<"OTC\t\t"<<"Acid Free C(500mg)\t"<<"birr 1.00"<<endl;
                cout<<"0004\t\t"<<"OTC\t\t"<<"Women'S Multivate\t"<<"birr 4.00"<<endl;
                cout<<"0005\t\t"<<"OTC\t\t"<<"marino Tablet\t\t"<<"birr 1.00"<<endl;
                cout<<"0006\t\t"<<"OTC\t\t"<<"maxi cal tablet\t\t"<<"birr 5.00"<<endl;
                cout<<"0007\t\t"<<"OTC\t\t"<<"animo zinc tablet\t"<<"birr 7.00"<<endl;
                cout<<"0008\t\t"<<"OTC\t\t"<<"burnex\t\t\t"<<"birr 4.00"<<endl;
                cout<<"0009\t\t"<<"OTC\t\t"<<"fabuloss\t\t"<<"birr 3.00"<<endl;
                cout<<"0010\t\t"<<"OTC\t\t"<<"propollen\t\t"<<"birr 5.00"<<endl;
               cout<<" "<<endl;
 cout << "Type Order no: ";
    cin >>M.reciept_number;
 cout<< "Enter Customer Name: ";
 cin>>M.customerName;
 cout<<"Enter Date : ";
 cin>>M.date;
 cout << "How many Medicine would you like to order:"<< endl;
 cout<<"( Maximum is 10 order for each transaction ) n";
 cout << "  " ;
 cin >> M.x;
 if (M.x >10)
 {
  cout << "The Medicine you order is exceed the maximum amount of order !";
  system("pause");
 }
 else
 for (i=0; i<M.x; i++)
 {
  cout << "Please enter your selection : "<<endl;
  cin>>M.menu2[i];
        cout<< "Medicine Name: " <<M.medicineName[M.menu2[i]-1]<<endl;
        cout << "How many medicine do you want: ";
        cin >>M.quantity[i];
        M.amount[i] = M.quantity[i]*M.Med[M.menu2[i]-1];
        cout << "The amount You need to pay is: " <<M.amount[i]<<" Birr"<<endl;
        system("PAUSE");
 }
 cout<<"==========================================================================="<<endl;
    cout << "Order Taken Successfully"<<endl;
    cout<<"==========================================================================="<<endl;
    cout << "Go to Receipt Menu to Pay The Bill"<<endl;
    cout<<"==========================================================================="<<endl;
 system ("PAUSE");
 }
void expiredate( )
 {
     cout<<"The expired date of the Probiotics  is 2023/3/13"<<endl;
     cout<<"The expired date of the Vitamin C(500mg) is 2023/3/23"<<endl;
     cout<<"The expired date of the Acid Free C(500mg)  is 2023/3/14"<<endl;
     cout<<"The expired date of the Marino Tablet is 2023/3/3"<<endl;
     cout<<"The expired date of the Maxi Cal Tablet  is 2023/2/10"<<endl;
     cout<<"The expired date of the Animo Zinc Tablet is 2023/5/13"<<endl;
     cout<<"The expired date of the burnex is 2023/6/3"<<endl;
     cout<<"The expired date of the fabuloss is 2023/7/1"<<endl;
     cout<<"The expired date of the propollen is 2023/12/3"<<endl;
     cout<<"The expired date of the Women'S Multivate is 2023/5/12"<<endl;
 }
  void introduction()
  {
      cout<< "***************\n";
      cout<< "Welcome to Ethiopian Kenema Medicine  Center"<<endl;
      cout<< "We are here to help our customers, Thank you for using our service."<<endl;
      cout<< "***************\n";
      cout<<"enter any key to continue"<<endl;
      cin.get();
  }
void exit()
{
 cout<<"nYou choose to exit.n"<<endl;
}
