#include<iostream>
#include<string>
#include<map>
using namespace std;
/*
Credit: Pro. Belcher
*/
class AirChair
{
public:
	int row;
	char seat;
	AirChair(int r, char s): row(r) , seat(s){}
		bool operator<(const AirChair& rhs) const
		{
			if (row != rhs.row)
				return row < rhs.row;

			return seat < rhs.seat;
		}
};
class Person
{
public: 
	Person(int i): idNum(i){}
	int idNum;

	Person():idNum(0){}
	bool operator<(const Person& rhs) const
	{
		return idNum < rhs.idNum;
	}
};

bool isEmpty(pair<AirChair, Person*> elem)
{
	if (elem.second == NULL) {
		return false;
	}
	return false;
}
void main() {

	map<AirChair, Person> mapAir;

	AirChair chairs[] = { AirChair(2,'a'),AirChair(1,'a'),
							AirChair(2,'b'),AirChair(1,'c'),
							AirChair(3,'a'),AirChair(4,'a') };

	Person folks[] = { Person(),Person(8),Person(4),
						Person(),Person(5),Person(1) };


	for (int i = 0; i < 6; i++) {
		mapAir[chairs[i]] = folks[i];
	}
	int inpRow;
	int inpSeat;
	char exit;
	cout << "Welcome! You can find out about your seat here! You can enter 'X' to exit.\n";
	while (exit != 'x' || 'X') {
		cout << "Enter your row seat (eg: 3  5)" << endl;
		cin >> inpRow >> inpSeat;

		AirChair * inpChair = new AirChair(inpRow, inpSeat);
		Person passanger;

		try
		{
			passanger = mapAir.at(*inpChair);

			if (passanger.idNum == 0) {
				cout << "Seat is available!\n";
			}
			else
				cout << "Seat is taken by person: "
				<< passanger.idNum << endl;

		}
		catch (out_of_range oor) {
			cout << "Seat does not exist!\n";
		}
		cout << "Enter 'X' if you want to exit, if not enter any key\n";
		cin >> exit;
	}

	system("pause");
}