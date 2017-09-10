
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

int main() {
	int price, quantity;
	string itemname, specificName;
	int i = 0;
	const int NUM_ITEMS = 2;
	ItemToPurchase objectOne;
	ItemToPurchase objectTwo;
	for (int i = 0; i < NUM_ITEMS; ++i) {
		cout << "Item" << i + 1 << endl << "Enter the item: ";
		getline(cin, itemname);
		cout << "Enter the item's price: ";
		cin >> price;
		cout << "Enter the item's qunatity: ";
		cin >> quantity;

		cout << "Enter the item's specific name: ";
		cin.ignore();
		getline(cin, specificName);
		
		if (i == 0) {
			objectOne.SetName(itemname);
			objectOne.SetPrice(price);
			objectOne.SetQuantity(quantity);
			objectOne.SetDescription(specificName);
		}
		else if (i == 1) {
			objectTwo.SetName(itemname);
			objectTwo.SetPrice(price);
			objectTwo.SetQuantity(quantity);
			objectTwo.SetDescription(specificName);
		}
		cin.ignore();
	}

	
	cout << "TOTAL COST\n";
	objectOne.printTotal();
	objectTwo.printTotal();
	objectOne.PrintItemDescription();
	objectTwo.PrintItemDescription();
	system("pause");

	string userName, Date;
	ShoppingCart shopObject;

	cout << "Enter your name please: " << endl;
	getline(cin, userName);
	cout << "Enter the order's date: \n";
	getline(cin, Date);
	shopObject.PrintMenu();
	ShoppingCart shopObject(userName, Date);

	system("pause");
	return 0;
}
