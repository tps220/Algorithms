//Thomas Salemy
//Project Euler Solutions
//Problem 35: Circular Primes 
//Question: How many circular primes are there below one million

#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

void cycle(int& num, int& size) {
	int temp = num % 10;
	num = num / 10 + temp * pow(10, size - 1);
}

int length(int num) {
	if (num == 0) {
		return 0;
	}
	return 1 + length(num / 10);
}



int main() {

    //Constants
    const int MAX = 1000000;
    clock_t time = clock();
    
    //PRIME SIEVE
    bool *primeSieve = new bool[1000000]();
    primeSieve[1] = true;

    int i = 4;
    while (i < MAX) {
	    primeSieve[i] = true;
	    i += 2;
    }

    for (i = 3; i < 1000; i += 2) {
	    if ( !primeSieve[i] ) {
		    for (int j = i * 2; j < MAX; j += i) {
			    primeSieve[j] = true;
		    }
	    }
    }

    int count = 1;
    for (i = 3; i < MAX; i += 2) {
	    if ( !primeSieve[i] ) {
		    int number = i;
		    int size = length(number);
		    bool isPrime = true;
		    for (int k = 0; k < size - 1; k++) {
			    cycle(number, size);
			    if (primeSieve[number]) {
				    isPrime = false;
				    break;
			    }
		    }
		    if (isPrime) {
			    count++;
	    	}   	
    	}
    }

    cout << "Answer: " << count << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 0;
}

