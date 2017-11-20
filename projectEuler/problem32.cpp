//Thomas Salemy
//Project Euler Solutions
//Problem 32: Pandigital Products
//Find the sum of all products whose product identity
//can be written as a 1 through 9 pandigital

#include <iostream>
#include "time.h"
#include <sstream>
#include <set>
using namespace std;



//Check if its pandigital
bool pandigital(int m1, int m2, int num) {
	ostringstream ss;
	ss << m1;
	ss << m2;
	ss << num;
	string numberStream = ss.str();
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (numberStream[j] == '0') {
				return false;
			}
			if (numberStream[i] == numberStream[j]) {
				return false;
			}
		}
	}	
	return true;
}



int main() {
    clock_t time = clock();

    //Make sure there are no duplicates
    set<int> duplicates;
    int SUM = 0;
    for (int i = 1; i < 100; i++) {
	    int j;
	    if (i > 9) {
		    j = 100;
	    }
	    else {
		    j = 1000;
	    }
	    while (i * j < 9999) {
		    if (pandigital(i, j, i * j)) {
			    if (duplicates.find(i * j) == duplicates.end()) {	
				    SUM += i * j;
				    cout << i << " * " << j << " = " << i * j << endl;
				    duplicates.insert(i * j);
			    }		
		    }
		    j++;
	    }
    }
    cout << "Answer: " << SUM << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
}
