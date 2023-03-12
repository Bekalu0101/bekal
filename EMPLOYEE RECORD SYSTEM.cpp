
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void choice();
struct EMP
{
  char  ID[25];
  char NAME[30];
  char ADDRESS[15];
  char  CONTACT[10];
  char  SALARY[25];

}EMP;
void createEMP(){
    ofstream ofile;

    ofile.open("EMPrecord.txt",ios::app);
    if(ofile.fail()){
            cout<<"failed to open the file";}
    else
        {


            cout<<" ENTER RECORD OF THE EMPLOYEE "<<endl;
    cout<<"\nEnter The ID OF EMPLOOYE ";
  cin>>EMP.ID;
  cout<<"\n ENTER EMPLOOYE NAME : ";
  cin>>EMP.NAME ;
  cout<<"\nENTER ADDRESS OF EMPLOOYE: ";
  cin>>EMP.ADDRESS;
  cout<<"\n ENTER CONTACT OF THE EMPLOOYE : ";
  cin>>EMP.CONTACT;
  cout<<"\n ENTER SALARY OF THE EMPLOOYE ";
  cin>>EMP.SALARY;

  //inserting the data in to the EMPrecord.txt file
  ofile.write((char*)&EMP,sizeof(EMP));
  cout<<"EMP record added completlly!!";
  ofile.close();
    }

    choice();
    }



void readEMPrecord(){
    ifstream ifile;
    ifile.open("EMPRecord.txt",ios::in);
    if(ifile.fail()){
        cout<<"can not open the file sorry!!";
    }
    else{
        cout<<"EMPrecords"<<endl;
        cout<<"ID\t\tNAME\t\tADDRESS\t\tCONTACT\t\tSALARY\t\t"<<endl;
        cout<<"--------------------------------------------------------------------------------------"<<endl;
        while(ifile.read((char*)&EMP,sizeof(EMP)));{
            cout<<EMP.ID<<"\t\t"<<EMP.NAME<<"\t\t"<<EMP.ADDRESS<<"\t\t"<<EMP.CONTACT<<"\t\t"<<EMP.SALARY<<"\t\t"<<endl;
        }

        ifile.close();
    }choice();
}
void searchEMPrecord(){
    char ch[10];
    int a=0;
    ifstream ifile;
    ifile.open("EMPRecord.txt",ios::in);
    if(ifile.fail()){
        cout<<"error in opening the file!!";
    }
    else
        {
        cout<<"ENTER THE ID NUMBER EMP YOU WANT TO SEE"<<endl;
        cin>>ch;
        while(ifile.read((char*)&EMP,sizeof(EMP))){
            if(strcmp(EMP.ID,ch)){
                cout<<" THE EMPOOYE RECORD THAT YOU WANT SEE IS  "<<endl;
                cout<<"ID ="<<EMP.ID<<endl;
                 cout<<"NAME ="<<EMP.NAME<<endl;
                  cout<<"ADDRESS="<<EMP.ADDRESS<<endl;
                   cout<<"CONTACT="<<EMP.CONTACT<<endl;
                    cout<<"SALARY="<<EMP.SALARY<<endl;

                     a=1;

            }
        }
        if(a==0){
            cout<<"SORRY THE EMPLOOYEE RECORD IS NOT FOUND!!!";
        }

    ifile.close();
    }
choice();

}
void modifyEMPrecord(){
    char ch[10];
    int found=0;
    cout<<" Enter ID Employee to be modified"<<endl;
    cin>>ch;
    fstream file;
    file.open("EMPRecord.txt",ios::out|ios::in);
    if(file.fail()){
        cout<<"error in open the file";
    }
    else{
            //search
            while(file.read((char*)&EMP,sizeof(EMP))&& found==0){

                if(strcmp(EMP.ID,ch)){
                    cout<<"Enter the new details of the employee"<<endl;
                    cout<<"Enter the new ID "<<endl;
                    cin>>EMP.ID;
                     cout<<"Enter the new name of the employee"<<endl;
                    cin>>EMP.NAME;
                     cout<<"Enter the new address of the employee"<<endl;
                    cin>>EMP.ADDRESS;
                     cout<<"Enter the new contact of the employee"<<endl;
                    cin>>EMP.CONTACT;
                     cout<<"Enter the new  salary of the employee"<<endl;
                    cin>>EMP.SALARY;
                    int back=-1*sizeof(EMP);
                    file.seekp(back,ios::cur);
                    file.write((char*)&EMP,sizeof(EMP));
                    found=1;
                    cout<<"YEAH!! modified successfully!!";
                }
            }
        if(found==0){
            cout<<"EMPLOOYEE record not found sorry!!";
        }

    }
    file.close();
    choice();

}
void deleteEMPRecord(){
    //search
    char ch[25];
    cout<<"Enter ID of employee that you want to delete";
    cin>>ch;
    ifstream ifile;
    ifile.open("EMPRecord.txt");
    ofstream ofile;
    ofile.open("TO.txt");
    while(ifile.read((char*)&EMP,sizeof(EMP)))
        {
            if(strcmp(EMP.ID,ch))
            {
                    ofile.write((char*)&EMP,sizeof(EMP));
            }
          }
          cout<<"you deleted from the record successfully";
ifile.close();
ofile.close();
remove("EMPRecord.txt");
rename("TO.txt","EMPRecord.txt");
cout<<"EMP record deleted successfully!!";
choice();
}
void choice(){
    int ch;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-"<<endl<<endl;
    cout<<" DEAR WELCOME TO OUR EMPLOOYEE  RECORD MANAGMENT SYSTEM PROJECT!!"<<endl<<endl;
  cout<<"PRESS 1.TO CREATE EMPLOOYEE RECORD"<<endl<<endl;
  cout<<"PRESS 2.TO DISPLAY ALL EMPLOOYEE RECORDS"<<endl<<endl;
  cout<<"PRESS 3.TO SEARCH EMPLOOYEE RECORD "<<endl<<endl;
  cout<<"PRESS 4.TO MODIFY EMPLOOYE RECORD"<<endl<<endl;
  cout<<"PRESS 5.TO DELETE EMPLOOYEE RECORD"<<endl<<endl;
  tryagain:
      cout<<"PLEASE ENTER YOUR CHOICE  [1-5]"<<endl;
      cin>>ch;
      switch(ch){
    case 1:
    createEMP();
    break;
  case 2:
      readEMPrecord();

       break;
  case 3:
      searchEMPrecord();

        break;
  case 4:
      modifyEMPrecord();

        break;
  case 5:
       deleteEMPRecord();

        break;
    default:
        cout<<"sorry you entered invalid number"<<endl;
        goto tryagain;
        break;



      }


}


 int main()
 {
     choice();
    createEMP();
          //readEMPRecord();
            // searchEMPRecord();
           // modifyEMPRecord();
       // deleteEMPRecord();
        return 0;

    }
