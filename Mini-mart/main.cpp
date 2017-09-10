/* Yemane Zewdu
 This is a simple mini-mart project.
 It calculattes your total and write is in a separate file in addition with your orders.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

string ItemName[5];
int ItemPrice[5];
char ItemTax[5];

void Order() {
	bool check = true;
	int UserChoice;
	double tax = 0.0;
	double Total = 0.0;

	cout << "  PLEASE ORDER HERE!  \n";
	ofstream SecondFile;
	SecondFile.open("Reciept.txt");
	while (check = true) {
		cout << endl << "Enter the ID number of the Item you want to order" << endl
			<< "or Press any Ctrl + Z to stop order\n";
		cin >> UserChoice;
		if (UserChoice > 0 && UserChoice < 5) {

			SecondFile << ItemName[UserChoice - 1] << '  ' << ItemPrice[UserChoice - 1];
			if (ItemTax[UserChoice - 1] == 'T') {
				cout << setw(7) << "Taxable Item ";
				tax += (ItemPrice[UserChoice - 1] * 0.07);
				Total = ItemPrice[UserChoice - 1] + tax;
			}
			else if (ItemTax[UserChoice - 1] == 'N') {
				cout << setw(7) << "Non-Taxable \n";
				Total += ItemPrice[UserChoice - 1];
			}
			else if (UserChoice > 5)
				cout << "Invalid ID number! Please choose your items again \n";
		}
		else {
			cout << "    Thank you! Please come again!  \n\n";
			check = true;
		}


		SecondFile << setw(10) << "\n Here is your reciept \n"
			<< ItemName[UserChoice - 1] << setw(6) << ItemPrice[UserChoice - 1]
			<< "\nThe total tax is " << setw(6) << tax << endl << "Total "
			<< setw(6) << Total;
		cout << "\nThe total tax is " << setw(6) << tax << endl << "Total "
			<< setw(6) << Total;
	}
	SecondFile.close();
}

int main() {

	ifstream theFile;
	theFile.open("MiniMart.txt");

	cout << endl << "    Here are the items available    \n";
	if (theFile.is_open()) {
		while (!theFile.eof()) {
			for (int i = 1; i = 5; i++) {
				theFile >> ItemName[i - 1]
					>> ItemPrice[i - 1]
					>> ItemTax[i - 1];
			}
		}

		theFile.close();
		for (int i = 1; i = 5; i++) {
			cout << '(' << i << ')' << ItemName[i - 1] << "  " << ItemPrice[i - 1] << endl;
		}
	}

	else {
		cout << "Input file not found!\n";
		return -1;
	}
	Order();



	return 0;
	system("pause");
}