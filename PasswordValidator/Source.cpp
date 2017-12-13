/* 
Yemane Zewdu
Final Lab
Password Validator
12/06/2017
*/

#include<iostream>
#include<string>
#include<time.h>
using namespace std;


class GeneralPWError
{

public:
	string theProblem;
	string pwTried;
	time_t timeTried;
	

	GeneralPWError() {			// default constructor

	}
	GeneralPWError(string error) {			
		theProblem = error;
	}
};

void checkPassword(const char * p)
{
	int i = 0, count = 0;
	int len = strlen(p);
	bool isUp = false,	// varibale for uppercase char
		isLow = false, // varibale for lowercase char
		isNum = false, // varibale for digits
		isCont = false,	// varibale for contiguos digits
		isSp = false; //varibale for space

	if (len > 16) {
		throw 20;
	}
	if (len < 10)
	{
		throw 10;
	}
	else {
		for (i; i < len; i++) {
			if (isalpha(p[i])) {			// making sure the char is an alphabet

				if (isupper(p[i])) {		// checking for uppercase char
					isUp = true;
				}

				if (islower(p[i])) {		// checking for lowercase char
					isLow = true;
				}
			}

			if (isdigit(p[i])) {			// checking for digits
				count = count + 1;
				isNum = true;
			}

			// checking for the non-contiguous digits
			if ((isdigit(p[i]) && isdigit(p[i + 1])) || (isdigit(p[i]) && isdigit(p[i - 1]))) {		
				isCont = true;
				 GeneralPWError e("can't have two numbers next to each other!\n");
				 throw e;
			}

			if (isspace(p[i])) {					// checking for space
					
					isSp = true;
					GeneralPWError e("must not have a space!\n");
					throw e;
				}
		}

		if (!isUp) {						// if no uppercase letter	
			GeneralPWError e("must have atleast one uppercase letter\n");
			throw e;
		}

		if (!isLow) {						// if no lowercase letter
			GeneralPWError e("must have atleast one lowerrcase  letter\n");
			throw e;
		}

		if (count < 2) {					// if the password has less than two digits
			GeneralPWError e("need to have atleast two digits!\n");
			throw e;
		}		
		
		// if the password was valid
		if (isUp && isLow && isNum && !isCont && !isSp && count >= 2) {			
				cout << "\nYour password is valid!\n";
				system("pause");
				return;		
		}

	}
}

void main() {
	
	GeneralPWError obj;			// class instance

	obj.timeTried = time(NULL);		// 
	tm* timeStruct;
	timeStruct = localtime(&obj.timeTried);

	for (int i = 0; i <= 5; i++) {
		if (i == 5) {																	// if the user tried more than 5 times, quit
			cout << "Too many attempts!\n";
			system("pause");
			return;
		}

		cout << "Enter your password: (to quit enter three dots consecutively)\n";
		
		// getting the user's password
		getline(cin, obj.pwTried);

		if ((obj.pwTried.size() == 3) && obj.pwTried[0] == '.' && obj.pwTried[1] == '.' && obj.pwTried[2] == '.') {     //  if the user enters '...', retun
			cout << "\nQuiting the program!\n";								
			system("pause");
			return;									
		}
		try {
			checkPassword(obj.pwTried.c_str());       // function call
		}

		catch (int length) {					// catching the expection thrown if the password length isn't 10-16 char.
			if (length == 10) {
				cout << "\nPassword too short! \nIt should atleast be 10 characters long.\n";
			}
			if (length == 20) {
				cout << "\nPassword too long! \nIt should not be more than 16 characters.\n";
			}
		}
		catch (GeneralPWError e)
		{
			cout << obj.pwTried << " tried at " << (timeStruct->tm_hour > 12 ? timeStruct->tm_hour - 12 : timeStruct->tm_hour)
				<< ":" << timeStruct->tm_min << ":" << timeStruct->tm_sec << " ";
			if (timeStruct->tm_hour <= 12) {
				cout << "AM";
			}
			if (timeStruct->tm_hour >= 12) {
				cout << "PM";
			}
			cout <<" " << e.theProblem <<endl;
								
		}
	}

	system("pause");	
}