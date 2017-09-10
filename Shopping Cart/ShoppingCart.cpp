
#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

char userInput;
string newItem, newDescription, remove;
int newPrice, newQuantity;
ItemToPurchase modifyObject;


ShoppingCart::ShoppingCart()
{
}


ShoppingCart::ShoppingCart(string  purchaserName, string orderDate) {
	customerName = purchaserName;
	currentDate = orderDate;
}
void ShoppingCart::getCustomerName() {

}
void ShoppingCart::getDate() {

}
void ShoppingCart::AddItem(string addItem ) {
	cartItems.push_back(addItem);
}
void ShoppingCart::RemoveItem(string ItemRem ) {
	for (int i = 0; i <= cartItems.size(); i++) {
		if (ItemRem == cartItems.(i)) {
			cout << "You have removed " << ItemRem << "from your cart. \n";
			// delete ??
			cartItems.erase(ItemRem);
		}
		else {
			cout << "Item not found\n";
		}
	}
}
void ShoppingCart::ModifyItem (string , int, int) {

}
int ShoppingCart::getNumItemsInCart() {
	int numItems=0;
	for (int i = 0; i <= cartItems.size(); i++) {
		numItems = numItems + 1;
	}
	cout <<"You have "<< numItems<<" items in your cart. \n";
	return numItems;
}
int ShoppingCart::getCostOfCart() {
	int cost = 1;

}
void ShoppingCart::PrintTotal() {
	if (cartItems.size == 0) {
		cout << "Shopping cart is empty.\n";
	}
	else {
		cout << customerName << " " << currentDate << endl
			<< "Number of Items: " << cartItems.size() << endl; // Nike Romaleos 2 @ $189 = $378
		for (int i = 0; i <= cartItems.size(); i++) {
			cout << cartItems.(i) << endl;
		}
	}
}
void ShoppingCart::PrintDescriptions() {

}
void ShoppingCart::PrintMenu() {
	char userInput;
	string newItem, newDescription, remove;
	int newPrice, newQuantity;
	ItemToPurchase modifyObject;
	
	do {
		cout << "MENU \n"
			<< "a - Add item to cart \n"
			<< "d - Remove item from cart \n"
			<< "c - Change item quantity \n"
			<< "i - Output items' descriptions \n"
			<< "o - Output shopping cart \n"
			<< "q - Quit";
			cout << endl;
			cout << "Choose an option : \n";
		    cin >> userInput;
			switch (userInput)
			{
			case 'A':
			case 'a':
				cout << "ADD ITEM TO CART\n"
					<< "Enter the item name : \n";//Nike Romaleos
					cin >> newItem;
					AddItem(newItem);
					cout << "Enter the item description : \n";
					cin >> newDescription;         //Volt color, Weightlifting shoes
					//PrintDescriptions(newDescription);
					cout << "Enter the item price : \n"; //189
					cin >> newPrice;
					cout << "Enter the item quantity : \n";
					cin >> newQuantity;
					break;
			case 'd':
			case 'D':
				cout << "REMOVE ITEM FROM CART\n"
					<< "Enter name of item to remove : \n";
				cin >> remove;
				RemoveItem(remove);
				break;
			case 'c':
			case 'C':
				cout << "CHANGE ITEM QUANTITY\n"
					<< "Enter the item name : \n" // Nike Romaleos
					<< "Enter the new quantity : \n"; //3I"
				
				break;
			case 'i':
			case 'I':
				cout << "Printing the Item's description: \n";
				PrintDescriptions();
			case 'o':
			case 'O':
				cout << "Output Shopping Cart: \n";
				// call shopping cart fun
			default:
				break;
			}

	} while (userInput != 'q'|| 'Q');
}
