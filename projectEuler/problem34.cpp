//Thomas Salemy
//Project Euler Solutions
//Problem 34: Digit Factorials 
//Question: Find the sum of all numbers which are equal to the sum
//of the factorial of their digits

#include <iostream>
#include <time.h>
using namespace std;

int factorial(int a) {
	if (a == 1) {
		return 1;
	}
	return a * factorial(a - 1);
}

int main() {
    clock_t time = clock();

    //Estimate the max where adding another factorial
    //will cause the sum to be greater than the number
    //of digits in the number or too little of the number
    //of digits in the number
    const int MAX = 1799999;

    int *factorialSieve = new int[10];
    factorialSieve[0] = 1;
    for (int i = 1; i < 10; i++) {
	    factorialSieve[i] = factorial(i);
    }

    int SUM = 0;
    int addingUp = 0;
    for (long i = 11; i < MAX; i++) {
	    SUM = 0;
	    long number = i;
	    while ( number > 0 ) {
		    SUM += factorialSieve[number % 10];
		    number /= 10;
		    if (SUM > i) {
			    break;
		    }
	    }
	    if (SUM == i) {
		    addingUp += SUM;
	    }
    }
    cout << "Answer: " << addingUp << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

    delete [] factorialSieve;
}
