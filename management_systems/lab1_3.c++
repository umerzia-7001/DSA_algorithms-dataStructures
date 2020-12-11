#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class Bank_Account {
    
public :    // member variables
    string customer_name;
    long account_number;
    float balance;
};
// child class
class savings: public Bank_Account{
    
public: // parameterized constructor
    savings(string customer_name1,long account_number1,float balance1){  //Parameterized Constructor
        customer_name=customer_name1;
        account_number=account_number1;
        balance=balance1;
        
    }
public: // deposisting amount
    void deposit(float amt) {
        balance+=amt;
        std::cout<<"amount deposited "<<amt<<std::endl;
}
    void display(){ // viewing balance
        std:cout<<"Savings account balance is "<<balance<<std::endl;
    }

    void withdraw()  //withdrawing an amount
{
        int wamt1;
        cout<<"\n Enter Withdraw Amount = ";
        cin>>wamt1;
        if(wamt1>balance)
                cout<<"\n Cannot Withdraw Amount";
        balance-=wamt1;
}  

};
// child class
class current:public Bank_Account{
    
public: // parameterized constructor
    current(string customer_name2,long account_number2,float balance2){  //Parameterized Constructor
        customer_name=customer_name2;
        account_number=account_number2;
        balance=balance2;
}

public: // deposisting amount
    void deposit(float amt1) {
        balance+=amt1;
        std::cout<<"amount deposited "<<amt1<<std::endl;
            
}
    void display(){ // viewing balance

        std:cout<<"Current account balance is "<<balance<<std::endl;
    }
    void withdraw() {
        //withdrawing an amount

        int wamt1;
        cout<<"\n Enter Withdraw Amount = ";
        cin>>wamt1;
        if(wamt1>balance)
                cout<<"\n Cannot Withdraw Amount";
        balance-=wamt1;
}
};
int main()
{
    
        string customer_name;
        long account_number;
        float balance;
        float amount;
        char account_type;

        cout<<"\n Enter Details: \n";
        cout<<"-----------------------";
        cout<<"\n Accout No. ";
        cin>>account_number;
        cout<<"\n Customer Name : ";
        cin>>customer_name;
        cout<<"-----------------------";
        cout<<"\n Account Type (S/C): ";
        cin>>account_type;
       switch(account_type){
           case 'S':
           {
               savings b1( customer_name,account_number, balance);  //object is created
               cout<<"enter amount to deposit ";
                cin>>amount;
                b1.deposit(amount); //
                b1.display();
       
                b1.withdraw();
                b1.display();
                break;
           }
           case 'c':
           {
               savings c1( customer_name,account_number, balance);  //object is created
               cout<<"enter amount to deposit ";
                cin>>amount;
                c1.deposit(amount); //
                c1.display();
       
                c1.withdraw();
                c1.display();
                break;

           }
       }
        
        return 0;
}
