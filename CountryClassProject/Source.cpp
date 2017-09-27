/*Yemane Zewdu
09/16/2017

This is Country Class Programming Project1

*/

#include<iostream>
#include<string>
using namespace std;

class Country {
private:
	string CountryName;
	string Greeting;// greeting in native language
	double numPopn; // number of population 
	bool isWesHem;// located in the western Hemisphere or not
public:
	Country(string name, string greet, double popNum, bool found) {
		CountryName = name;
		Greeting = greet;
		numPopn = popNum;
		isWesHem = found;
	}
	string getCoutryName() {
		return CountryName;
	}
	string getGreeting() {
		return Greeting;
	}
	double	getNumPopn() {
		return numPopn;
	}
	bool getIsWesHem() {
		return isWesHem;
	}
};


// A function that will print the hello greeting of each Country in the array
void helloToAll(Country countryArray[], int SIZE) {

	cout << "      HELLO TO ALL!!      \n";
	for (int i = 0; i < SIZE; i++) {
		cout << countryArray[i].getGreeting() << " is \"Hello\"  in " << countryArray[i].getCoutryName() << endl;
	}
}

// A function that  return the sum of total population of all Countries NOT in the western hemisphere
double sumPopEast(Country countryArray[], int size) {
	double sum = 0.0;
	for (int i = 0; i < size; i++) {
		if (!countryArray[i].getIsWesHem()) {
			sum += countryArray[i].getNumPopn();
		}

	}
	return sum;
}

// A function hat will return the greeting of the Country that contains the lowest population.
string lowPopGreeting(Country countryArray[], int size) {

	int low = 0;
	for (int i = 0; i < size; i++) {
		if (countryArray[i].getNumPopn() < countryArray[low].getNumPopn()) { //temp) {
			low = i;
		}
	}
	return countryArray[low].getGreeting();
}



int main() {
	const	int SIZE = 5;
	Country obj("Ethiopia", "Selam", 102.4, false); // calling the 4 arg. constructor

													// Instantiating the array
	Country Array[SIZE] = { Country("Ethiopia", "Selam", 102.4, false), Country("Paris", "Bonjour", 12.24, false),
		Country("Brazil", "Ola", 207.7, true), Country("Israel","Shalom", 8.54, false),
		Country("Canada", "Hello", 36.29, true) };

	helloToAll(Array, SIZE);
	cout << "\nThe sum of the countries that are not in the western hemisphere is " << sumPopEast(Array, SIZE) << endl;
	cout << "\nThe greeting of the country with the lowest population is: " << lowPopGreeting(Array, SIZE) << endl;

	system("pause");
}