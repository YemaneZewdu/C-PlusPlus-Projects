/*
Yemane Zewdu
Dijkstra Algorithm
DATA STRUCTURES

*/
#include <iostream>
#include <fstream>
using namespace std;

/*Sample input will be  6 5 1

which is node , node and the distance respectively
*/


int N;              // number of node
int a, b, w;          // used for input , w is weight b/n a and b
int am[100][100];   // matrix
int dis[100];       // distance
int visited[100];

int dij(int x) {  // dijkstra function
	visited[x] = 1;  // sets the current node as visited

	for (int i = 1; i <= N; i++) { // updating
		if ((visited[i] == 0) && (am[x][i] != -1)) {
			if ((dis[x] + am[x][i] < dis[i]) || (dis[i] == -1)) {
				dis[i] = dis[x] + am[x][i]; // updates 'i'
			}
		}
	}
	// selecting a new node
	int smaller = -1, sw = -1;
	for (int i = 0; i <= N; i++) { // checking for the next node
		if ((visited[i] == 0) && (dis[i] >= 0) && ((sw>dis[i]) || (sw == -1))) {
			sw = dis[i]; //changes the existing smaller weight
			smaller = i;
		}
	}
	if (smaller != -1) { // if not smaller, call the function
		dij(smaller);
		return 0;
	}
	return 0;
}
int main()
{
	ifstream fin("C:/Users/yeman/OneDrive/Documents/Nodes.txt"); // the input file

	fin >> N; // loading
	for (int i = 0; i <= N; i++) { // initializing the matrix
		for (int j = 0; j <= N; j++) {
			am[i][j] = -1;        // setting the values to -1, to show that there is no connection
		}
	}

	for (int i = 0; i <= N; i++) { // initializing the distance
		dis[i] = -1;
	}

	dis[1] = 0; // initializing the  root, 0 since it is our starting point
	while (!fin.eof()) { // reading from the file
		fin >> a >> b >> w;
		am[a][b] = w;   // updating the matrix
		am[b][a] = w;   // updating the matrix

	}
	dij(1);

	for (int i = 1; i <= N; i++) { // output
		cout << "The shortest path is " << dis[i] << " ";
	}
	cout << endl;

	fin.close(); // closing the file
	system("pause");
	return 0;
}
