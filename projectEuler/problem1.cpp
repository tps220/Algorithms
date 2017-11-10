//Thomas Salemy
//Project Euler Solutions
//Problem 1: Multiples of 3 and 5
//Question: Find the sum of all the multiples of 3 or 5 below 1000

#include <iostream>
#include "time.h"
using namespace std;

//Returns the sum of the multiples of a number up until some bound
int sumFunction(int multiple, int MAX) {
	int n = MAX / multiple;
	return  n * (n + 1) / 2  * multiple;
};

int main() {
    clock_t time = clock();
    int sum = sumFunction(3, 999) + sumFunction(5, 999) - sumFunction(15, 999);
    cout << "Answer: " <<  sum << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
};
