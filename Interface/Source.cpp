/*Yemane Zewdu
10/12/17
printing a frame with Interface
*/


#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


class PrintInfo
{
public:
	virtual char getFrameChar() = 0;
	virtual char getFillChar() = 0;
	virtual int getRows() = 0;
	virtual int getCols() = 0;
};

class Frame : public PrintInfo
{
private:
	char frameChar, fillChar;
	int rows, cols;
public:
	void setFrameChar(const char fc) {
		frameChar = fc;
	}
	 char getFrameChar() {
		return frameChar;
	}
	 void setFillChar(const char fic) {
		 fillChar = fic;
	 }
	char getFillChar() {
		return fillChar;
	}
	void setRows(const int r) {
		rows = r;
	}
	 int getRows() {
		 return rows;
	}
	 void setCols(const int c) {
		 cols = c;
	 }
	 int getCols() {
		 return cols;
	 }	

};

void printFrame(PrintInfo *pi) {
	cout << "Frame char: " << pi->getFrameChar() << endl;
	cout << "Fill character: " << pi->getFillChar() << endl;
	cout << "Rows: " << pi->getRows() << endl;	
	cout << "Columns: " << pi->getCols() << endl;

	for (int r = 0; r < pi->getRows(); r++)
	{
		for (int c = 0; c < pi->getCols(); c++)
		{
			if (r > 0 && r < pi->getRows() - 1 && c > 0 && c < pi->getCols() - 1) {
				cout << setw(2) << pi->getFillChar() ;
			}
			else {
				cout << setw(2) << pi->getFrameChar();
			}
		}cout << endl;
	}
	
	
}
void main() {
	Frame obj;
	obj.setRows(5);
	obj.setCols(7);
	obj.setFrameChar('*');
	obj.setFillChar('$');

	printFrame(&obj);

	system("pause");
}