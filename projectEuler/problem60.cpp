#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>
using namespace std;



long modularExponentation(long a, long num, long d) {
	long result = 1;
	a = a % num;
	while ( d >  0) {
		if (d % 2 == 1) {
			result = (result * a) % num;
		}
		a = (a * a) % num;
		d /= 2;
	}
	return result;
}


bool millerTest(long num, long d) {
	long a = rand() % (num - 4) + 2;
	long x = modularExponentation(a, num, d);
	
	if (x == 1 || x == num - 1) {
		return true;
	}
	
	while (d != num - 1) {
		x = (x * x) % num;
		if (x == 1) {
			return false;
		}
		if (x == num - 1) {
			return true;
		}
		d *= 2;
	}
	return false;
}

bool isPrime(long num) {
	if (num == 3) {
		return true;
	}
	if (num % 2 == 0) {
		return false;
	}
	long d = num - 1;
	while (d % 2 == 0) {
		d /= 2;
	}
	
	for (int i = 0; i < 3; i++) {
		if (!millerTest(num, d)) {
			return false;
		}
	}
	return true;
}

int size(long num) {
	if (num < 10) {
		return 10;
	}
	return 10 * size(num / 10);
}

bool pairPrime(long a, long b) {
	if ( isPrime(a + size(a) * b) && isPrime(size(b) * a + b) ) {
		return true;
	}
	return false;
}




int main() {

clock_t time = clock();

//---------Prime Sieve for numbers below 100000 and a vector list of those numbers-------//
const int MAX = 100000;
const int BOUND = 334;
bool primeSieve[MAX] = { false };
vector<int> primes;

//Deal with even numbers
int i = 4;
while (i < MAX) {
	primeSieve[i] = true;
	i += 2;
}

for (i = 3; i < MAX; i += 2) {
	if ( !primeSieve[i] ) {
		primes.push_back(i);
		if (i < BOUND) {
			for (int k = i * 2; k < MAX; k += i) {
				primeSieve[k] = true;
			}
		} 
	}
}

bool flag = false;
long a, b, c, d, e;
long a2, b2, c2, d2, e2;
for (int a1 = 0; a1 < 100; a1++) {
	a = primes[a1];
	for (int b1 = a1 + 1; b1 < 2000; b1++) {
		b = primes[b1];
		while (b1 < 3000 && !pairPrime(a, b)) {
			b = primes[b1];
			b1++;
		}
		for (int c1 = b1 + 1; c1 < 3000; c1++) {
			c = primes[c1];
			while (c1 < 3000 && (!pairPrime(a, c) || !pairPrime(b, c)) ) {
				c = primes[c1];
				c1++;
			}
			for (int d1 = c1 + 1; d1 < 3000; d1++) {
				d = primes[d1];
				while (d1 < 3000 && (!pairPrime(a, d) || !pairPrime(b, d) || !pairPrime(c, d)) ) {
					d = primes[d1];
					d1++;
				}
				for (int e1 = d1 + 1; e1 < 3000; e1++) {
					e = primes[e1];
					
					if (pairPrime(a, e) && pairPrime(b, e) && pairPrime(c, e) && pairPrime(d, e)) {
						
			cout << a << " + " << b << " + " << c << " + " << d << " + " << e << " = " << a + b + c + d + e << endl;

					}
				}
			}
		}
	}
	
}

cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

}
