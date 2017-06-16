//Project Euler Solutions
//Problem 4: Largest Palindrome Number
//Thomas Salemy

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <time.h>
using namespace std;



int modularExponentation(int n, int d, int a) {
	int finalNumber = 1;
	a = a % n;
	while (d > 0) {
		//if d is odd or d == 1
		if ( d % 2 == 1) {
			finalNumber = (finalNumber * a ) % n;
		}
		a = (a * a) % n;
		d /= 2; 
	}
	return finalNumber;
};

bool millerTest(int n, int d) {
	int a = rand() % (n - 4) + 2;
	int x = modularExponentation(n, d, a);
	if (x == 1 || x == n - 1) {
		return true;
	}
	
	while (d != n - 1) {
		x = (x * x) % n;
		d *= 2;
		if (x == 1) {
			return false;
		}
		if ( x == n - 1) {
			return true;
		}
	
	}
	return false;
};

bool isPrime(int n) {

if (n <= 1 || n == 4) return false;
if ( n <= 3) return true;

if (n % 2 == 0) {
	return false;
}

//ignore corner cases for this large number
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

bool isPalindrome(int number) {
	ostringstream ss;
	ss << number;
	string buff = ss.str();
	for (int i = 0, j = buff.length() - 1; i < buff.length(); i++, j--) {
		if (buff[i] != buff[j]) {
			return false;
		}
	}
	return true;
};
int main() {

clock_t start = clock();
const int max = 999 * 999;
for (int i = max; i > 100000; i--) {
	if (isPalindrome(i)) {
		if ( ! isPrime(i) ) {
			for (int j = 999; j > 100; j--) {
				if ( i % j  == 0 && i / j < 1000) {
					cout << j << " * " << i / j << " = "<<  i << endl;
					clock_t end = clock();
					double time = (double)(end - start);
					cout << time / CLOCKS_PER_SEC ;
					return 1;	
				}	

			}
		}
	}
}
cout << "none found";


return 1;
};
