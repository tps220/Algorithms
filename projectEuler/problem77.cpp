#include <iostream>
#include <time.h>
#include <vector>
using namespace std;



int main() {

clock_t time = clock();



//From last problem, we saw how many times 100 could be written as sum
//of numbers. This algorithm is essentially the same, its just that
//we can only use a certain set of numbers. So, since theres two primes
//for almost every 10 (conservative estimate), I'm going to make
//400 my bound for the number of primes I will use
const int MAX = 400;



//-----------Prime Sieve Implementation----------//
bool primeSieve[MAX] = { false }; //Prime Sieve
vector<int> primes; //Vector of primes

//Deal with evens
int i = 4;
primes.push_back(2);
while (i < MAX) {
	primeSieve[i] = true;
	i += 2;
}

//Deal with odds
for (i = 3; i < MAX; i += 2) {
	if ( !primeSieve[i] ) {
		primes.push_back(i);
		for (int k = i * 2; k < MAX; k += i) {
			primeSieve[k] = true;
		}
	}
}
//-----------End----------------------//


int target = 10;
int result = 5;
while (result < 5000 && target < MAX) {
	target++;
	int* map = new int[target + 1]();
	map[0] = 1;
	for (int i = 0; primes[i] <= target; i++) {
		for (int k = primes[i]; k <= target; k++) {
			map[k] += map[k - primes[i]];
		}
	}
	result = map[target];
	delete[] map;
}

cout << "Answer: " << target << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;


}



