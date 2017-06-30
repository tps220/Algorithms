#include <iostream>
#include <time.h>
using namespace std;




int main() {

clock_t time = clock();

//CONSTANTS
const int MAX = 400000;
const int BOUND = 700;

//PRIME SIEVE IMPLEMENTATION
int factorSieve[400000] = { 0 };

//DEAL WITH EVEN NUMBERS
int i = 4;
while (i < MAX) {
	factorSieve[i]++;
	i += 2;
}

//DEAL WITH ODD NUMBERS
for (i = 3; i < BOUND; i += 2) {
	if (factorSieve[i] == 0) {
		for (int k = i * 2; k < MAX; k += i) {
			factorSieve[k]++;
		}
	}
}


for (i = 2 * 3 * 5 * 7; i < MAX - 4; i++) {
	if (factorSieve[i + 3] < 4) {
		i += 3;
	}
	else if (factorSieve[i + 2] < 4) {
		i += 2;
	}
	else if (factorSieve[i + 1] < 4) {
		i++;
	}
	else if (factorSieve[i] >= 4) {
		break;
	}
}

cout << "Answer: " << i << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

}
