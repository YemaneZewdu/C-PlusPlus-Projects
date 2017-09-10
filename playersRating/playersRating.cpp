// YEMANE ZEWDU  02/08/17
//This program will store roster and rating information for a team of players.

#include<iostream>
#include<vector>
using namespace std;
void displayMenu(); // function prototype
void Continue();    // function prototype
vector<int> JerseyNo(6);  
vector<int> Ratings(6);

int main() {
	int rating;
	int jerseynum;
	unsigned int i;
	for (int i = 1; i < 6; i++) {
		cout << "Enter palyer " << i << "'s jersey no: \n";
		cin >> JerseyNo.at(i);
		while (JerseyNo.at(i) >99 || JerseyNo.at(i) < 0) {

				cout << "Enter a Jersey number between 0-99:\n";
				cin >> jerseynum;
				JerseyNo.at(i) = jerseynum;			
		}

		cout << "Enter palyer " << i << "'s rating(1-9): \n";
		cin >> Ratings.at(i);

		while (Ratings.at(i)>9 || Ratings.at(i) < 0) {
				cout << "Enter the rating again:\n";
				cin >> rating;
				Ratings.at(i) = rating;			
			}
	}

	cout << "\nRoster" << endl;
	for (int i = 1; i < 6; i++) {
		cout << "Player " << i << " -- Jersey number: " << JerseyNo.at(i) << ", Rating: " << Ratings.at(i) << endl;
	}

    displayMenu();  // function call

	system("pause");
	return 0;
}
void displayMenu() {

	char userChoice=' ';
	int newJerseyNo=0;
	int newRating=0;
	unsigned int i = 1;
	


	cout << "\nMENU:\n";
	cout << "a - Add player\n";
	cout << "d - Remove player\n";
	cout << "u - Update player rating\n";
	cout << "r - Output players above a rating\n";
	cout << "o - Output roster\n";
	cout << "q - Quit\n";

	cout << "Choose an option : \n";
	cin >> userChoice;

	
		if (userChoice == 'a' || 'A') {  // Adds

			cout << "Enter a new player's jersey number:\n";
			cin >> newJerseyNo;
			while (newJerseyNo > 99 || newJerseyNo < 0) {
				cout << "Enter jersey no. between 0-99:\n";
			}
			JerseyNo.push_back(newJerseyNo);
			cout << "Enter the player's rating:\n";
			cin >> newRating;
			while (newRating > 9 || newRating < 0) {
				cout << "Enter rating between 1-9:\n";
			}
			Ratings.push_back(newRating);
			cout << endl;
			for (i = 1; i < JerseyNo.size(); i++) {
				cout << "Roster--" << endl << "Player " << i << " -- Jersey number: " << JerseyNo.at(i) << ", Rating: " << Ratings.at(i) << endl;
			}
			
		}
		else if (userChoice == 'd' || 'D') {    // deletes     
			cout << "Enter a jersey number :\n";
			cin >> newJerseyNo;
			for (i = 1; i < 6; i++) {

				if (newJerseyNo == JerseyNo.at(i)) {
					newJerseyNo = i;
				}
			}
			for (i = 1; i < 6; i++) {
				if (i >= newJerseyNo) {
					JerseyNo.at(i) = JerseyNo.at(i + 1);
					Ratings.at(i) = Ratings.at(i + 1);
				}
			}
			/*else {
				cout << "Jersey Number not registered";
			}*/

			JerseyNo.pop_back();
			Ratings.pop_back();
			cout << endl;

			for (i = 1; i < JerseyNo.size(); i++) {
				cout << "Roster--" << endl << "Player " << i << " -- Jersey number: " << JerseyNo.at(i) << ", Rating: " << Ratings.at(i) << endl;
			}
		
		}
		else if (userChoice == 'u' || 'U') { // updates
			cout << "Enter the jersey number you want to update:\n";
			cin >> newJerseyNo;
			cout << "Enter a new rating for the player:\n";
			cin >> newRating;
			for (i = 1; i < 6; i++) {
				if (JerseyNo.at(i) == newJerseyNo) {
					Ratings.at(i) = newRating;
				}
			}
			for (i = 1; i < JerseyNo.size(); i++) {
				cout << "Roster--" << endl << "Player " << i << " -- Jersey number: " << JerseyNo.at(i) << ", Rating: " << Ratings.at(i) << endl;
			}
		}
		else if (userChoice == 'r' || 'R') {  // > rating
			cout << "Enter a rating:\n";
			cin >> newRating;
			cout << "ABOVE " << newRating << endl;
			for (i = 1; i < 6; i++) {
				if (Ratings.at(i) > newRating) {
					cout << "Player " << i << " -- Jersey number:" << JerseyNo.at(i) << ", Rating: " << Ratings.at(i) << endl;
				}
			}
		}

			else if (userChoice == 'q' || 'Q') {
				cout << "Good Bye!" << endl;
				
			}

		else if (userChoice == 'o' || 'O') {  // Roster
			cout << "Roster--" << endl;
			for (i = 1; i < JerseyNo.size(); i++) {
				cout << "Player " << i << " -- Jersey number: " << JerseyNo.at(i) << ", Rating: " << Ratings.at(i) << endl;
			}
		}

		else {
			cout << "You entred a wrong choice.\n";
			
		}
		Continue(); //Function Call
		 //return;
	}


void Continue() {
	char Input;
	bool check = true;
	cout << "Do you want to continue?\n";
	cout << "y/n\n";
	cin >> Input;
	while (check = true) {
		if (Input == 'y' || 'Y') {
			//system("cls"); //clears the screen

			displayMenu(); // Function call
		}
		else if (Input == 'n' || 'N') {
			cout << "Good Bye!!\n";
			check = false;
		}
		else {
			cout << "Choose either 'y' or 'f' \n";
			check = true;
		}
	}
}