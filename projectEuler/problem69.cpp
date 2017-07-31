#include <iostream>
#include <time.h>
using namespace std;

//Intuition way:
//The totient function can be simplified into q(n) = n * (1 - 1/p) ..... continuously done for all distinct primes
//that factorize into the current number. Therefore, to maximize the number of distinct primes, we continue to multiply
//by the next prime until the number on the next turn will reach above our maximum, 1000000
//
//So all we do is:
//2 * 3 * 5 * 7 * 11 * 13 * 17 = 510510
//


//Programming way
int main() {

clock_t time = clock();


const int MAX = 1000000;
const int BOUND = 1000;
int sieve[MAX] = {0};
for (int i = 2; i < MAX; i++) {
	if (sieve[i] == 0) {
		sieve[i] = i - 1;
		for (int k = i * 2; k < MAX; k += i) {
			if (sieve[k] == 0) {
				sieve[k] = k;
			}
			sieve[k] = (int) (sieve[k] * (1.0 - 1.0 / (double)i));
		}
	}
}

double biggest = 0;
int number = 0;
for (int i = 10; i < MAX; i++) {
	
	if ((double)i / sieve[i] > biggest) {
		biggest = (double) i / sieve[i];
		number = i;
	}
}


cout << number << endl;
cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;


}
