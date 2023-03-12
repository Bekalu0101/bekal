
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class nodeStack
{
public:
    int accountNo;
    string HolderName;
    int  balance;
    nodeStack *next;
    nodeStack()
    {
        HolderName="";
    }
    nodeStack(int accountNo, string HolderName ,int balance)
    {
        this->accountNo = accountNo;
        this->HolderName = HolderName;
        this->balance = balance;
    }
};
class stack
{
    nodeStack *top;
    public:

   void createStack()
   {
       top = NULL;
   }
   bool isEmpty()
   {
       return top==NULL;
   }
   void push();
   void pop();
   void display();
   void search();
};
void stack::push()
{
    int newaccountNo,newbalance;
    string newHolderName;
    nodeStack *node = new nodeStack;
    if (node == NULL)
    {
        cout << "Cannot allocate memory" << endl;
    }
    else
    {
        system("");
        cout << "<<<<<<<<<<<<Insert customer>>>>>>>>>>>>" << endl;
        cout << "account number:";
        cin >> newaccountNo;
        cout << "Account Holder Name:";
        cin >> newHolderName;
        cout << "balance:";
        cin >>newbalance;
        node->accountNo =newaccountNo;
        node->HolderName=newHolderName;
        node->balance=newbalance;
        node->next = top;
        top = node;
    }

}
void stack::pop()
{
    nodeStack *delNode;
    system("");
     cout << "<<<<<<<<<<<<remove customer>>>>>>>>>>>>" << endl;
    cout << "customer account number: " << top->accountNo << endl;
    cout << "customer Name:" << top->HolderName << endl;
    cout << "balance: " << top->balance << endl;
    cout << "<< press any key to continue>>";
    cin.get();
    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        delNode =top;
        top = top->next;
        free(delNode);
    }
}
void stack::display()
{
    int counter =0;
    nodeStack *currNode= top;
    system("");
    cout << "<<<<<<<<<<<<Display customers>>>>>>>>>>>>" << endl;
    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        while (currNode != NULL)
        {
            cout << "["<<counter+1<<"] customer account number:"<< currNode->accountNo << endl;
            cout << "\t" << "customer Name:" << currNode->HolderName << endl;
            cout << "\t" << "balance:" << currNode->balance << endl;

            currNode = currNode->next;
        }
    }
}
void stack::search()
{
    int  input;
    nodeStack *currNode = top;
    system ("");
    cout << "<<<<<<< Search customer account no(s) >>>>>>>" << endl;
    cout << "Enter account number:";
    cin >> input;
    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        while (currNode != NULL)
        {
            if(currNode->accountNo == input)
            {
                cout << "Student ID:"<< currNode->accountNo<< endl;
                cout << "\t" << "Student Name:" << currNode->HolderName << endl;
                cout << "\t" << "course Title:" << currNode->balance<< endl;
                cout << "Finish Searching ... press any key to continue " << endl;
                cin.get();
                break;
            }
            else
                currNode = currNode->next;
        }
    }
}
void dispMenu()
{
    system ("");
    cout << "WELCOME TO BANK MANAGEMENT SYSTEM DEAR AMINA" << endl
         << "\n\t 1.Insert account." << endl
        << "\n\t 2.Remove account holder." << endl
        << "\n\t 3.Search account holder." << endl
        << "\n\t 4.Display  accounts." << endl
        << "\n\t 5.exit." << endl;
}
int main()
{
    stack accountRec;
    accountRec.createStack();
    int choice;
    do
    {
        dispMenu();
        cout << "\nEnter your choice[1-5]: ";
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
            case 1: accountRec.push();
            break;
            case 2: accountRec.pop();
            break;
            case 3: accountRec.search();
            break;
            case 4:accountRec.display();
            break;
            default:
            cout << "\n Thank you.. see you again.." << endl;
            return 0;
        }
    }while((choice>0)&&(choice<5));
    return 0;
}
