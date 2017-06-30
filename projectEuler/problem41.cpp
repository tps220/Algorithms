#include <iostream>
#include <time.h>
#include  <stdlib.h>
#include <string>
#include <sstream>
using namespace std;


long modularExponentation(long a, long d, long num) {
	int result = 1;
	while (d > 0) {
		if (d % 2 == 1) {
			result = (result * a) % num;
		}
		a = (a * a) % num;
		d /= 2;
	}
	return result;
}


bool millerTest(long num) {
	long a = rand() % (num - 4) + 2;

	long d = num - 1;
	while (d % 2 == 0) {
		d /= 2;
	}

	long x = modularExponentation(a, d, num);

	if (x == 1 || x == num - 1) {
		return true;
	}
	while (d != num - 1) {
		x = (x * x) % num;
		d *= 2;
		if (x == 1) {
			return false;
		}
		if (x == num -1){
			return true;
		}
	}
	return false;
}


bool isPrime(long num) {
	if (num <= 1) {
		return false;
	}
	if (num < 4) {
		return true;
	}
	if (num % 2 == 0) {
		return false;
	}

	for (int i = 0; i < 4; i++) {
		if (!millerTest(num)) {
			return false;
		}
	}
	return true;
}	


bool pandigital(long num) {
	ostringstream ss;
	ss << num;
	string digits = ss.str();
	for (int i = 0; i < digits.length() - 1; i++) {
		for (int k = i + 1; k < digits.length(); k++) {
			if (digits[i] == digits[k] || digits[k] == '0' || digits[k] == '9' ||  digits[k] == '8')  {
				return false;
			}
		}
	}
	return true;
}

int main() {
	//A number is divisible by 3 if its digits' sum is divisible by 3
	//
	//If a number is 1 to n pandigital, that means we know the sum of its digits.
	//9 pandigital = sum from 1 to 9 = n * (n + 1) / 2 = 9 * (9 + 1) / 2 = 45;
	//8 pandigital = 36
	//7 pandigital = 28 --> not divisible by 3, so has the possibility to be prime
	//6 pandigital = 21
	//5 pandigital = 15
	//4 pandigital = 10
	//3 pandigital = 6
	//2 pandigital = 3
	
	//I decided to use the miller rabin primality test because the problem
	//only requires to check, i would assume, not that many primes because
	//pandigital numbers are not a frequent occurence. 
	
	clock_t time = clock();	

	long result = 0;
	for (long i = 7654321; i > 0; i -= 2) {
		if (pandigital(i)) {
			if (isPrime(i)) {
				result = i;
				break;
			}
		}
	}					
	cout << "Answer: " << result << endl;
	cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
}





	
