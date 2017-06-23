#include <iostream>
#include "time.h"
using namespace std;




//Knapsack Problem:
//Given the weight and value of n items, store these items in a "knapsack" of capcacity MAX (sometimes max Weight, othertimes max value)
//to get the maximum total value in the knapsack.
//
//Use two arrays:
//val[0 ---> n] .... val[0 ---> 200]
//weight[0 ---> n]... weight = {1, 2, 5, 10, 20, 50, 100, 200}
//
//N can be different, as in this problem
//
//Now, maximize the sum of v(i) subject to w(i) <= MAX CAPACITY (whether that's weight, max value)


int main() {

clock_t time = clock();


//The following is unnecessary, I'm just showing the general process of what
//an entire tables knapsack algorithm, only looking at combinations not optimizations, 
// would look like. This is for my own future reference. The solution right after
// is better




//all the values, fortunately they are an exact match to their index in this problem
//but they are almost always not. We will initialize vi, although we really don't
//need to. As I said though, this is an example/reference for future problems.
int Vi[201];
for (int i = 0; i < 201; i++) {
	Vi[i] = i;
}

//Initialize weights and their values
int weight[9] = {0, 1, 2, 5, 10, 20, 50, 100, 200};

//Start the map which has indexes (V(i), weight(i))
int map[201][9] = { {} }; //vi by w

for (int i = 0; i < 9; i++) {
	map[0][i] = 1;
}
for (int i = 0; i < 201; i++) {
	map[i][0] = i;
	map[i][1] = 1;
}

//Start algorithm. We set it up using a knapsack type methology, however the 
//implementaiton is different as we are not optimizing, we are just
//calculating the total amount of weight possible from combining
//all the values
for (int column = 2; column < 9; column++) {
	int w = weight[column];
	int count = 0;
	//Copy over values missed
	for (int row = 0; row < w; row++) {
		map[row][column] = map[row][column - 1];
	}
	//Start algorithm
	for (int row = w; row < 201; row++) {	
		count = map[row - w][column];
		map[row][column] = map[row][column - 1] + count;	
	}
}

//Display map to show what it looks like
for (int i = 0; i < 201; i++) {
	for (int j = 0; j < 9; j++) {
		cout << map[i][j] << "\t";
	}
	cout << endl;
}



cout << endl << endl << "Answer: " << map[200][8] << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl << endl;

//This process can be done faster and with less memory
//if we are not so redundant in copying over the values from column to 
//column and instead use a single array to store our values and
//reiterate over it.

time = clock();


int map2[201] = { };
map2[0] = 1;
for (int coinIterator = 1; coinIterator < 9; coinIterator++) {
	int w = weight[coinIterator];
	for (int i = w; i < 201; i++) {
		map2[i] += map2[i - w];
	}
}		

cout << "Answer: " << map2[200] << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;



}
