
#pragma once
#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
class ItemToPurchase
{
public:
	ItemToPurchase();
	void SetName(string name);
	void getName();
	void SetPrice(int ItemPrice);
	void getPrice();
	void SetQuantity(int ItemQuantity);
	void getQuantity();
	void SetDescription(string itemDescription);
	string getDescription();
	void PrintItemDescription();
	void printTotal();
private:
	string itemName;
	int itemPrice;
	int itemQuantity;
	string itemDescription;
};
#endif
