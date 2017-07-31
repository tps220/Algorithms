#include <iostream>
#include <time.h>
using namespace std;


int main() {

clock_t time = clock();

const int MAX = 1000001;
int* sieve = new int[MAX]();

for (int i = 2; i < MAX; i++) {
	if (sieve[i] == 0) {
		sieve[i] = i - 1;
		for (int k = i * 2; k < MAX; k += i) {
			if (sieve[k] == 0) {
				sieve[k] = k;
			}
			sieve[k] = (int) (sieve[k] * (1.0 - 1.0 / i));
		}
	}
}

long long total = 0;
for (int i = 2; i < MAX; i++) {
	total += sieve[i];
}
delete [] sieve;

cout << total << endl;
cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;




}
