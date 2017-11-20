//Thomas Salemy
//Project Euler Solutions
//Problem 31: Coin sums
//Question: How many different ways can £2 be made using any number of coins?

#include <iostream>
#include "time.h"
using namespace std;

//Follows the generalized knapsack Problem:
//Given the weight and value of n items, store these items 
//in a "knapsack" of capcacity MAX (sometimes max weight, othertimes max value)
//to get the maximum total value in the knapsack.
//
//Use two arrays:
//values[0 ---> n], 
//in this question this be values[0, 1, 2 ---> 200]
//weight[0 ---> n], 
//the given weights in this question = {1, 2, 5, 10, 20, 50, 100, 200}
//
//Now, maximize the sum of values[i] subject to weight[i] <= 200

int main() {
    clock_t time = clock();


    //FIRST SOLUTION
    //A general knapsack solution (not optimized for this problem
    int *Vi = new int[201];
    for (int i = 0; i < 201; i++) {
	    Vi[i] = i;
    }

    //Initialize weights and their values
    int weight[9] = {0, 1, 2, 5, 10, 20, 50, 100, 200};
    //Start the map which has indexes (V(i), weight(i))
    int map[201][9] = {{}};

    //Initialize base cases
    for (int i = 0; i < 9; i++) {
	    map[0][i] = 1;
    }
    for (int i = 0; i < 201; i++) {
	    map[i][0] = i;
	    map[i][1] = 1;
    }

    //Begin Algorithm
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
    //cout << endl << endl << "Answer: " << map[200][8] << endl;
    //cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl << endl;
    delete [] Vi;


    //SECOND SOLUTION
    //This process can be done faster and with less memory
    //if stop copying over the values from column to 
    //column and instead use a single array to store our values and
    //reiterate over it
    time = clock();
    int *map2 = new int[201]();
    map2[0] = 1;
    for (int coinIterator = 1; coinIterator < 9; coinIterator++) {
	    int w = weight[coinIterator];
	    for (int i = w; i < 201; i++) {
		    map2[i] += map2[i - w];
	    }
    }		

    cout << "Answer: " << map2[200] << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

    delete [] map2;
}
