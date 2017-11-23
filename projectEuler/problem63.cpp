//Thomas Salemy
//Project Euler Solutions
//Problem 63

#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;



int main() {

    clock_t time = clock();

    int lowerBound;
    int count = 0;
    int n = 1;
    while (lowerBound < 10) {
	    lowerBound = (int) ceil(pow(10, (n - 1.0) / n));
	    count += 10 - lowerBound;
	    n++;
    }

    cout << count << endl;
    cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

}

