#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;


class cashRegister{
    private:
    int cashOnHand;

    public:
    cashRegister(){
        cashOnHand = 500;
    }
    cashRegister(int cash){
        cashOnHand =cash ;

    }
    void acceptAmount(int amount) {
        cashOnHand += amount;

    }
};

class dispenserType{
    private:
    int numberOfItems;
    int cost;

    public:
    dispenserType (){
        numberOfItems = 50;
    }
    dispenserType (int items,int cost1){
        numberOfItems = items;
        cost = cost1;

    }

    int getNoOfItems(){
        return numberOfItems;
    }
    int getCost(){
        return cost;
    }
    void makeSale() {
        numberOfItems -= 1;
    }





};


void showSelection(){
    cout << "************************************" << endl;
    cout << "--------WELCOME TO CANDY SHOP-------" << endl;
    cout << "************************************" << endl;
    cout << "What do you want to buy"
            "\n1. Candy \n2. Cookies \n3. Chips \n4. Gums . \n5. Exit" << endl;
    cout << "Enter your Choice:";
}

void sellProduct(dispenserType item, cashRegister counter){
    int amount;
    cout << "The price of item is: " << item.getCost() << endl;
    cout << "Enter your amount:";
    cin >> amount;
    if (amount >= item.getCost()){
        if (item.getNoOfItems() > 0){
            item.makeSale();
            counter.acceptAmount(item.getCost());
            cout << "Item has been dispensed. The change is: " << amount - item.getCost() << endl;
            return;
        }else{
            cout << "No more items available." << endl;
            return;
        }
    }else{
        cout << "The entered amount is less than the item cost.\n";
        return;
    }

}



int main(){
cashRegister counter;
dispenserType candy(100, 50);
dispenserType chips(100, 65);
dispenserType gum(75, 45);
dispenserType cookies(50, 85);
int choice;
showSelection();
cin >> choice;
while (choice != 5)
{
	switch (choice)
	{
			case 1:
			sellProduct(candy, counter);
			break;
		case 2:
			sellProduct(chips, counter);
			break;
		case 3:
			sellProduct(gum, counter);
			break;
		case 4:
			sellProduct(cookies, counter);
			break;
		default:
			cout << "Invalid selection." << endl;
	}
	showSelection();
	cin >> choice;
}	
return 0;
}















