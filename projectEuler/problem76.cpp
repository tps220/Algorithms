//Thomas Salemy
//Project Euler Solutions
//Problem 76

#include <iostream>
#include <math.h>
using namespace std;


int main() {
    clock_t time = clock();

    const int MAX = 101;
    long* map = new long[MAX]();
    map[0] = 1;

    for (int i = 1; i < MAX - 1; i++) {
	    for (int k = i; k < MAX; k++) {
		    map[k] += map[k - i];
	    }
    }

    cout << "Answer: " << map[100] << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

    delete [] map;
}
