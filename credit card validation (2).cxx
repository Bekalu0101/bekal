//CREDIT CARD VALIDATION
#include <iostream>
#include<fstream>
#include<string.h>
#include<cmath>
#include<cstring>
using namespace std;
char menu();
int getDigit(int num)
{
  if ( num <= 9)

    return num;

  return num / 10 + num % 10;
}

int first_digit(string num )
{
  for (unsigned i=0; i<1; ++i)
     return num.at(i)-'0';
}

int odd(string num)
{
    int i, sum=0;
    int digit=num.length();
    for(i=digit-1;i>=0;i-=2)
        {sum += num[i]- '0';}
    return sum;
}

int even(string num)
{
    int i, sum=0;
   int digit=num.length();
    for(i=digit-2;i>=0;i-=2)
    {sum += getDigit(int(num[i]-'0')*2);}
    return sum;
}

bool isValid(string num)

{
  return (num.length() >= 13 && num.length() <= 16) &&
         (first_digit(num) ==3 || first_digit(num) ==4 || first_digit(num) ==5 ||first_digit(num) ==6) &&
         ((even(num) +  odd(num)) % 10 == 0);
}

char validation(string num)
{
 cout <<  (isValid(num) ? "valid" : "invalid");
}

char type(string num)
{
    switch(first_digit(num))
    {
    case 3:
        cout << "American Express Card"<<endl;
        break;
    case 4:
        cout << "Visa Card"<<endl;
        break;
    case 5:
        cout << "Master Card"<<endl;
        break;
    case 6:
        cout << "Discover Card"<<endl;
        break;
    default:
        cout << "invalid card number";
    }
}

char line()
{
    for (int i=0;i<=80;i++)
        cout<<'*';
}

struct Record
{
    string card_num;
    char card_validation;
    char card_type;
    char fulName[25] ;
    char bank[30];
    char bank_branch[50];
}rec;

void new_record()
{

   string card_num;
char fulName [25];
char bank[30];
    char bank_branch[50];
   ofstream ofile;
ofile.open("new_record.txt",ios::app);
if(ofile.fail())

{
    cout<<"fail to open the file";
}
else
{
    cout<< "please enter your credit card no"<<endl;
cin>>rec.card_num;
cout<<"please enter your fullname"<<endl;
cin >> rec.fulName;
cout<<"please enter bank"<<endl;
cin>> rec.bank;
cout<<"please enter bank_branch"<<endl;
cin >> rec.bank_branch;
//rec.card_validation = validation(card_num);
//rec.card_type=type(card_num);
ofile.write((char*)&rec,sizeof (rec));
cout<<"RECORED ADDED  ";
ofile.close();}
menu();}

void list_all()
{

    ifstream ifile;
    ifile.open("new_recored.txt",ios::in);
    if(ifile.fail())
    {
        cout<<"can not open file";
    }
    else
    {
        cout<<"new_recoreds"<<endl;
        cout<<"card_num \t card_validation \t type\t fullname\t bank name \t bank branch"<<endl;
        line();
    while(ifile.read((char*)&rec,sizeof(rec)));
    {
        cout<<rec.card_num<<"\t\t";
        cout<< rec.card_validation<<"\t\t";
        cout <<rec.card_type<<"\t\t" ;
        cout <<rec.fulName<<"\t\t"<<rec.bank<<"\t\t"<<rec.bank_branch<<"\t"<<endl;
        }
        ifile.close();
    }
    menu();
}
void check_validation()
{
    string card_num;
     cout<<"enter your card number"<<endl;
         cin>>card_num;
        cout<<"your card"<<card_num <<"is"<<validation(card_num);;

        menu();
}
void visit_recored()
{
    string card_num;
    string card;
    int n=0;
    ifstream ifile;
    ifile.open("new_recored.txt",ios::in);
    if(ifile.fail())
    {
            cout<<"error!! can not open file"<<endl;
    }
     else
     {
    cout<<"enter the card number you wish to visit"<<endl;
    cin>>card;
     while(ifile.read((char*)&rec,sizeof(rec)));
     {

              cout<<"card number="<<rec.card_num<<endl;
              cout<<"validation="<<rec.card_validation<<endl;
              cout<<"card type"<<rec.card_type<<endl;
              cout<<"bank name"<<rec.bank<<endl;
              cout<<"bank branch"<<rec.bank_branch<<endl;


     }
ifile.close();


}}

void upgrade()
{
    string num;int n=0;
    char fulName[25] ;
    char bank[30];
    char bank_branch[50];
    cout<<"enter card number to be upgraded"<<endl;
    cin>>num;
    fstream file;
    file.open("new_record.txt",ios::out|ios::in);
    if(file.fail())
    {
        cout<<"error";}
        else {
                while(file.read((char*)&rec,sizeof(rec))&&n==0)
        {
            cout<<"enter new details of the user"<<endl;
                   cout<<"enter new card number"<<endl;
                   cin>>rec.card_num;
                   rec.card_validation=validation(num);
                   rec.card_type=type(num);
                   cout<<"enter new name"<<endl;
                   cin.getline(fulName,25);
                   cout<<"enter new bank name"<<endl;
                   cin.getline(bank,25);
                   cout<<"enter new bank branch"<<endl;
                   cin.getline(bank_branch,30);
                   int m=-1*sizeof(rec);
                   file.seekp(m,ios::cur);
                   file.write((char*)&rec,sizeof(rec));
                   n=1;
                   cout<<"upgraded";}
        if(n=0)
                   {
                   cout<<"recored not found";}
                   file.close();}
                   menu();
                   }

char menu()
{
int yesno,x;
cout<<"\n menu"<<endl;
line();
cout<<"\nto check card validation enter 1"<<endl;
cout<<"to create  new card recored enter 2"<<endl;
cout<<"to visit  old record enter 3"<<endl;
cout<<"to upgrade existing record enter 4"<<endl;
cout<<"to lose out all records enter 5"<<endl;
line();
do{
cout<<"\nenter your choice(1-5)"<<endl;
cin>>x;
switch(x)
{
case 1:
    check_validation();
    break;
case 2:
    new_record();
     break;
 case 3:
    visit_recored();
     break;
case 4:
    upgrade();
    break;
case 5:
    list_all();
    break;
default:
    cout<<"error!!wrong input"<<endl;
}
cout << "Do you want to continue?"<<endl;
cout << "enter 1 to continue \n enter 0 to end"<<endl;
cin >> yesno;
}
while(yesno!=0);
}

int main()
{
    menu();
    return 0;
}
