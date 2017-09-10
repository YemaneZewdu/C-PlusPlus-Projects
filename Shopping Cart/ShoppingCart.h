#pragma once
#ifndef SHOPPINGCART_H

#define SHOPPINGCART_H
#include<vector>
class ShoppingCart : public ItemToPurchase
{
public:
	ShoppingCart();
	ShoppingCart(string purchaserName, string orderDate);
	void getCustomerName();
	void getDate();
	void AddItem(string );
	void RemoveItem(string);
	void ModifyItem(string,int,int);
	int getNumItemsInCart();
	int getCostOfCart();
	void PrintTotal();
	void PrintDescriptions();
	void PrintMenu();
private:
	string customerName;
	string currentDate;
	vector <ItemToPurchase> cartItems;
};
#endif 
