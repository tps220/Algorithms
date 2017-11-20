//Thomas Salemy
//Project Euler Solutions
//Problem 25: 1000 Digit Fibonacci Number
//Question: What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

#include <iostream>
#include <time.h>
#include <vector>
using namespace std;


int main() {
    clock_t time = clock();

    int digitCount = 1;
    int fibonacciCount = 2;
    
    int number[1000] = {};
    number[0] = 1;
    int oldNumber[1000] = {};
    oldNumber[0] = 1;
    int tempNumber[1000] = {};

    while (digitCount < 1000) {
	    for (int i = 0; i < digitCount; i++) {
		    tempNumber[i] = number[i];
		    number[i] += oldNumber[i];
		    while (number[i] >= 10) {
			    tempNumber[i + 1] = number[i + 1];
			    if (i < digitCount - 1) {
				    number[i + 1] += oldNumber[i + 1] + 1;
				    number[i] -= 10;
			    }
			    else {
				    number[i + 1] = 1;
				    number[i] -= 10;
				    digitCount++;
			    }
			    i++;
		    }
	    }
	    for (int i = 0; i < digitCount; i++) {
		    oldNumber[i] = tempNumber[i];
	    }
	    fibonacciCount++;
    }

    cout << "Answer: " << fibonacciCount << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
};
