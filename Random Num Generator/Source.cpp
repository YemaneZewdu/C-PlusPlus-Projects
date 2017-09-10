/*Yemane Zewdu

C++ project that generates random numbers.
*/


#include <iostream> 
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int userNum;
	int randNum=0;
	int tries = 0;
	srand(time(0));
	

	
	
	randNum = rand() % 100 + 1;
		
	do 
	{
		cout << "Enter your number\n";
		cin >> userNum;
		tries++;
		if (userNum > randNum) {
			cout << "Too large! Try again\n";
			//cout << randNum;

		}
		else if (userNum < randNum) {
			cout << "Too small! Try again\n";
			
		}

		else {
			cout << "Congragulations. You figured out my number in " << tries<< " guesses!";
			
		}
	} 
	while (userNum != randNum);
	
	cin.ignore(); //ignores user Input
	cin.get(); // gets any kind of user Input
	
	
	
	
	system("pause");
	return 0;
}