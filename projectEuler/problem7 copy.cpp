//Project Euler Solutions
//Problem 7: 10,001st prime
//Thomas Salemy

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//There are two ways to do this:
//
//By using the miller-rabin test, the isPrime method will
//efficiently determine whether a number is prime
//
//We will then iterate over as many numbers as it takes to get
//to the 10,001st prime. However, we will iterate only odd numbers
//
//Or, by using a prime sieve in which we will use dynamic programming
//to use all the prime numbers found before and set their multiples
//to a boolean

long modularExponentation(long a, int d, int n) {
	int finalNum = 1;
	while (d > 0) {
		if (d % 2 == 1) {
			finalNum = (finalNum * a) % n;
		}
		a = (a * a) % n;
		d /= 2;
	}
	return finalNum;
};

bool millerTest(int n, int d) {
	long a = rand() % (n - 4)  + 2;

	long x = modularExponentation(a, d, n);
	if (x == 1 || x == n - 1) {
		return true;
	}
	while (d != n - 1) {
		x = (x * x) % n;
		d *= 2;
		if (x == 1) {
			return false;
		}
		if (x == n - 1) {
			return true;
		}
	}
	return false;
};

bool isPrime(int n) {

if (n <= 1 || n == 4) return false;
if ( n <= 3) return true;

//Ignore if even, only dealin with odd numbers
//if (n % 2 == 0) {
//	return false;
//}

int d = n - 1;
while (d % 2 == 0) {
	d /= 2;
}
for (int i = 0; i < 5; i++) {
	if (millerTest(n, d) == false ) {
		return false;	
	}
}
return true;
};



int main() {

clock_t time1 = clock();
//Method 1
int count = 2;
int number;
for (number = 3; count < 10000; number+= 2) {
	if ( isPrime(number) ) {
		count++;
	}
}

cout << count << ":  " <<  number - 2 << endl;		
cout << (clock() - time1 ) / (double) (CLOCKS_PER_SEC) << endl;


count = 1;
//Method 2, using 200,000 as a max estimate
clock_t time2 = clock();
int factorMap[200000] = {};
for (number = 2; number < 200000 && count < 10000; number++) {
	if (factorMap[number] == 0) {
		count++;
		for (int i = number; i < 200000; i += number) {
			factorMap[i] = 1;
		}

	}
}

cout << count << ": " << number - 1 << endl;
cout <<  (clock() - time2 ) / (double) (CLOCKS_PER_SEC);
return 1;

};



	 
