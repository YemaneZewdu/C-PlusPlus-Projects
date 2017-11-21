/*
Yemane Zewdu
File Input Server Login Time assignment
11/12/2017

*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<ctime>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

class Files
{
public:
	string firstIn;
	string lastName;

	// '<' operator overloading returning names
	bool operator <(const Files &ptr) const
	{
		if (lastName == ptr.lastName) {
			return firstIn < ptr.firstIn;
		}
		return lastName < ptr.lastName;
	}

};
// This will print the users login time
struct TimeFunc
{
	// overloading '()' operator
	void operator() (pair<Files, long> keyPtr) {
		struct tm * ptm;
		time_t timeInSecs = keyPtr.second;
		ptm = localtime(&timeInSecs);   //formated time
		string Days[] = { "Sunday", "Monday", "Tuesday","Wednsday",
							"Thursday", "Friday", "Saturday" };

		string Months[] = { "January", "Febrary", "March","April",
								"May", "June", "July", "August",
						"September", "October", "November", "December" };

		// Printing the name of users with their login time 
		cout << "\n" << keyPtr.first.lastName << ", " << keyPtr.first.firstIn << " logged on "
			<< Days[ptm->tm_wday] << ", " << Months[ptm->tm_mon + 1] << " "
			<< ptm->tm_mday << " " << ptm->tm_year + 1900 << " at ";
			//<< ptm->tm_hour << ":"; // << ptm->tm_min << ":" << ptm->tm_sec << endl;
		if (ptm->tm_hour < 10) {
			cout << '0' << ptm->tm_hour;
		}
		else {
			cout << ptm->tm_hour;
		}

		cout << ":";

		if (ptm->tm_min < 10) {
			cout << '0' << ptm->tm_min;
		}
		else {
			cout  << ptm->tm_min;
		}

		cout << ":";

		if (ptm->tm_sec < 10) {
			cout << '0' << ptm->tm_sec << endl;
		}
		else{
				cout<< ptm->tm_sec << endl;
		}

	}
}strObj;
// This function returns the number of users who logged in before 10:00 AM
bool check(pair < Files, long> kptr)
	{
	struct tm * tptr;
	time_t timeInSecs = kptr.second;
	tptr = localtime(&timeInSecs);


	return tptr->tm_hour < 10;   // return if the hour is less than 10
}
void main()
{
	long loginTime;
	char * chPtr;
	Files obj;

	map<Files, long> mapData;
	map<Files, long>::iterator it; // itertor
	
	ifstream read;   // opening the file 
	read.open("C:/Users/yeman/OneDrive/Documents/usrlogs.txt"); // reading from the file

	while (!read.eof()) // loading the map 
	{
		pair<Files, long> myPair;
		chPtr = new char[30];

		getline(read, obj.lastName, ','); // getting the last name of the user
		getline(read, obj.firstIn, ','); // getting the first Intial of the user
		read.getline(chPtr, 30, '\n'); // getting the last login time of the user

		loginTime = atol(chPtr);      // converting the string to long

		myPair.first = obj;
		myPair.second = loginTime;


		it = mapData.find(myPair.first);	// finding for the user name if he has logged in before

		if (it == mapData.end())	// if it is the first log in of the user,  find() will return 'it'  pointing to the end of the map  
		{
			mapData.insert(myPair);			// thus insert the user name
		}

		else if (it != mapData.end() && (it->second < myPair.second))    // if 'it' isn't pointing to the end of the map, the user has logged in before
		{																	// therefore check if the time is smaller
			mapData.insert(myPair);

		}
	}

	//	delete[] chPtr;          // deleting the newly allocated memory
	read.close();			// closing the file
				
	
	
	cout << "There are " << mapData.size() <<" unique IDs.\n";

	for_each(mapData.begin(), mapData.end(), strObj); //Listing the users and their login times

	 // checking  for the # of users who logged in before 10 AM
	cout <<"\n" <<  count_if(mapData.begin(), mapData.end(), check) << "  users logged in before 10:00 AM.\n";  

	
	system("pause");
}