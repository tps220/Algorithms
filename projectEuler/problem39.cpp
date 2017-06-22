#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

int gcd(int a, int c) {
	if (c == 0) {
		return a;
	}
	return gcd(c, a % c);
}


//(a, b, c) :
//m^2 - n^2, 2mn, m^2 + n^2
//
//To be primitive, gcd of a and c == 1
//
//
//Use a "pythagorean sieve" to store all the 
//possible primitive combinations and their
//multiples
int main() {
clock_t time = clock();
int pythagor[1001] = { 0 };
int MAX = 0;
int perimeter = 0;
for (int n = 1; n < 50; n++ ) {
	for (int m = n + 1; m < 50; m++) {

		int a = m * m - n * n;
		int b = 2 * m * n;
		int c = m * m + n * n;
	
		if (gcd(a, c) == 1) {
			int sum = a + b + c;
			for (int k = sum; k <= 1000; k += sum) {	
				pythagor[k]++;
				if (pythagor[k] > MAX) {
					MAX = pythagor[k];
					perimeter = k;
				}
			}
		}
	}
}

cout << "Answer: " << perimeter << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

}
