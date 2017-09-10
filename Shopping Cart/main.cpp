/*Yemane Zewdu

This projects is on a shopping cart. It is written with separate class files attached with it.
*/

#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

int main() {
	string userName, Date;
	ShoppingCart shopObject;

	cout << "Enter your name please: " << endl;
	getline(cin, userName);
	cout << "Enter the order's date: \n";
	getline(cin, Date);
	shopObject PrintMenu();
	shopObject ShoppingCart (userName, Date);

	return 0;
}