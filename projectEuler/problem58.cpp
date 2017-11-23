//Thomas Salemy
//Project Euler Solutions
//Problem 58

#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>
using namespace std;


//Next three methods implement the miller-rabin primality test
long long modularExponentation(long long a, long long &num, long long d) {
	long long result = 1;
	a = a % num;
	while ( d != 0) {
		//If odd power, or if about to exit loop,
		//multiply by current value of a
		if (d % 2 == 1) {
			result = (result * a) % num;
		}
		a = (a * a) % num;
		d /= 2;
	}
	return result;
}


bool millerRabinTest(long long &num, long long d) {
	long long a = rand() % (num - 4) + 2;
	long long x = modularExponentation(a, num, d);

	if (x == 1 || x == num - 1) {
		return true;
	}

	while (d != num - 1) {
		x = (x * x) % num;
		d *= 2;
		if (x == 1) {
			return false;
		}
		if (x == num - 1) {
			return true;
		}
	}
	return false;
}



//First diagonal will be 3, so don't have to deal with
//normal corner cases for numbers below 3
bool isPrime(long long &num) {
	if (num % 2 == 0) {
		return false;
	}	
	//Begin 4 iterations of miller rabin test
	long long d = num - 1;
	while (d % 2 == 0) {
		d /= 2;
	}
	for (int i = 0; i < 4; i++) {
		if (!millerRabinTest(num, d)) {
			return false;
		}
	}
	return true;
}




int main() {
    clock_t time = clock();
    
    long long number = 1; //current value to be added to the map
    int sideLength = 1; //length of the current side
    int primeCount = 0; //number of primes found
    int diagonalCount = 1;
    int percentage = 100; //percentage of primes / totalDiagonalNumbers

    while (percentage >= 10) {
	    sideLength += 2;
	    for (int i = 0; i < 4; i++) {
		    number += sideLength - 1;
		    if (isPrime(number)) {
			    primeCount++;
		    }
		    diagonalCount++;
	    }
	    percentage = primeCount * 100 / diagonalCount;
    }

    cout << "SideLength: " << sideLength << ", last diagonal was: " << number << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 0;

}
