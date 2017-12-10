/*
Yemane Zewdu
12/07/2017
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Enemy
{
public:
	string name;
	int health;
	Enemy() {
		health = 0;
		name = "";
	}
};

//Replace Enemies pointer with vector as shown below
class EnemySquad
{
	vector<Enemy*> *enemies;

public:

	EnemySquad() {				//default constructor that initializes enemies vector
		enemies = NULL;
	}

	~EnemySquad() {				//destructor which deallocates enemies vector
		if (enemies != NULL) {
			delete enemies;
		}
	}

	void addEnemy( Enemy *p) {	//addEnemy() must add enemy to the enemies vector.
		if (enemies == NULL) {
			enemies = new vector<Enemy*>;
		}
				enemies->push_back(p);		  
	} 

	int getEnemyCount() {			//getEnemyCount() will return the number of enemies in the vector
	 	return enemies->size();
	} 

	Enemy* getEnemyAtIndex(int num)  //if parameter is out of range, throw an out_of_range exception with a proper description
	{
		if (num > getEnemyCount()) {
			out_of_range oor(" You went out of range");
			throw oor;
		}	
		return enemies->at(num);
	}
};



int main()
{

	EnemySquad *badGuys = NULL;
	badGuys = new EnemySquad;		//instantiate badGuys
	Enemy *ptr = new Enemy;						//Instantiate at least 3 enemies with different names and health
	ptr->name = "bully";
	ptr->health = 10;
	ptr->name = "Megatron";
	ptr->health = 20;
	ptr->name = "Transformer";
	ptr->health = 30;	
	
	//Add the instances to badGuys using the addEnemy() method
	badGuys->addEnemy(ptr);
	badGuys->addEnemy(ptr);
	badGuys->addEnemy(ptr);

	cout << "Enemies in the squad: " << badGuys->getEnemyCount() <<endl; //properly call getEnemyCount

		Enemy *checkBadGuy;

	try
	{
		checkBadGuy = badGuys->getEnemyAtIndex(2);		//call getEnemyAtIndex passing a valid index
			cout << "An enemy is " << checkBadGuy->name << " with health of " << checkBadGuy->health << endl;

		checkBadGuy = badGuys->getEnemyAtIndex(10);		//call getEnemyAtIndex passing an INVALID index to force the exception
			cout << "**This line should not be seen**, enemy is " << checkBadGuy->name 
			<< " with health of " << checkBadGuy->health << endl;

	}

	catch (out_of_range oor) {		//properly catch exception that may be thrown

		cout << "The error is: " << oor.what() << endl;
	}

	//deallocate badGuys
	delete badGuys;

	system("pause");
	return 0;
	
}

