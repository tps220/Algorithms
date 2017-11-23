//Thomas Salemy
//Project Euler Solutions
//Problem 70

#include <iostream>
#include <time.h>
#include <vector>
using namespace std;


bool isPermutation(long num1, long num2) {
	int check1[10] = {0};
	int check2[10] = {0};
	
	while (num1 > 0 && num2 > 0) {
		check1[num1 % 10]++;
		check2[num2 % 10]++;
		num1 /= 10;
		num2 /= 10;			
	}
	for (int i = 0; i < 10; i++) {
		if (check1[i] != check2[i]) {
			return false;
		}
	}
	return true;
}


int main() {

    clock_t time = clock();
    const int MAX = 6000;

    bool* sieve = new bool[MAX];
    int i = 4;
    while (i < MAX) {
	    sieve[i] = true;
	    i += 2;
    }

    vector<int> primes;
    for (int i = 3; i < MAX; i += 2) {
	    if ( !sieve[i] ) {
		    if (i > 1500) {
			    primes.push_back(i);
		    }
		    for (int k = i * 2; k < MAX; k += i) {
			    sieve[k] = true;
		    }
        }
    }
    delete [] sieve;


    double minRatio = 100;
    long result = 0;
    for (int i = 0; primes[i] * primes[i] < 10000000; i++) {
	    for (int k = i + 1; k < primes.size(); k++) {
		    long phi = (long)(primes[i] - 1) * (primes[k] - 1);
		    long number = primes[i] * primes[k];
		    if (number > 10000000) {
			    break;
		    }
		    if (isPermutation(phi, number) && (double)number / phi < minRatio) {
			    minRatio = (double)number / phi;
			    result = number;
		    }
	    }
    }

    cout << result << endl;
    cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

}
