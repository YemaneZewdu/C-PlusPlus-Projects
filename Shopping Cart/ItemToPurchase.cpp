
#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"


ItemToPurchase::ItemToPurchase()
{
	string itemName = "none";
	string itemDescription = "none";
	int itemPrice = 0;
	int itemQuantity = 0;
}
void ItemToPurchase::SetName(string name) {
	itemName = name;
}
void ItemToPurchase::getName() {

}
void ItemToPurchase::SetPrice(int price) {
	itemPrice = price;
}
void ItemToPurchase::getPrice() {

}
void ItemToPurchase::SetQuantity(int quantity) {
	itemQuantity = quantity;
}
void ItemToPurchase::getQuantity() {

}
void ItemToPurchase::printTotal() {
	cout << itemName << " " << itemQuantity << " @ $" << itemPrice << "=$" << itemPrice * itemQuantity << endl;

}
void ItemToPurchase::  SetDescription(string itemDescription) {
	this->itemDescription = itemDescription;
}
string ItemToPurchase:: getDescription() {
	return itemDescription;
}
void ItemToPurchase:: PrintItemDescription() {
	cout << endl << itemName << ": " << itemDescription << itemQuantity <<" @" << itemPrice << endl;
}

