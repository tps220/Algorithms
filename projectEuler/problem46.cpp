#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;




int main() {

clock_t time = clock();

//CONSTANTS
const int MAX = 1000000;
const int BOUND = 1000;

//PRIME SIEVE IMPLEMENTATION
bool primeSieve[1000000] = { false };

//DEAL WITH EVEN NUMBERS
int i = 4;
while (i < MAX) {
	primeSieve[i] = true;
	i += 2;
}

//DEAL WITH ODD NUMBERS
for (i = 3; i < BOUND; i += 2) {
	if ( !primeSieve[i]) {
		for (int k = i * 2; k < MAX; k += i) {
			primeSieve[k] = true;
		}
	}
}



for (i = 33; i < 1000000; i += 2) {
	if ( primeSieve[i] ) {
		int root = sqrt(i);
		while (root * root * 2 > i) {
			root--;
		}
		while (root > 0) {
			if ( !primeSieve[i - 2 * root * root] ) {
				break;
			}
			root--;
		}
		if (root == 0) {
			break;
		}

	}
}


cout << "Answer: " << i << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

}
