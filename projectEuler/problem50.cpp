//Thomas Salemy
//Project Euler Solutions
//Problem 50: Consecutive prime sum
//Question: Which prime, below one-million, 
//can be written as the sum of the most consecutive primes?

#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

int main() {

    clock_t time = clock();

    //Prime Sieve
    bool *primeSieve = new bool[1000000]();
    vector<int> primes;
    const int MAX = 1000000;
    //Deal with Even numbers
    int i = 4;
    while (i < MAX) {
	    primeSieve[i] = true;
	    i += 2;
    }
    primes.push_back(2);

    //Odd numbers
    for (i = 3; i < MAX; i += 2) {
	    if ( !primeSieve[i]) {
		    primes.push_back(i);
		    for (int k = i * 2; k < MAX; k += i) {
			    primeSieve[k] = true;
		    }
	    }
    }

    //Keep on updating to the previous prime sequence that holds true
    int sum = 0;
    int maxPrime = 0;
    int count = 0;
    for (i = 0; sum < MAX; i++) {
	    if ( !primeSieve[sum] ) {
		    maxPrime = sum;
		    count = i - 1;
	    }	
	    sum += primes[i];
    }

    //Possible situation: if we take off the starting prime, 
    //and keep on adding more primes, the sequence gets longer. 
    //The rest of this program will account for that
    i = count;
    sum = maxPrime;
    int back = i + 1;
    int front = 0;

    //Estimate a bound
    int difference = MAX - maxPrime;
    int bound = 1;
    while (difference > 0) {
	    difference -= primes[back++] + primes[front++];
	    bound++;
    }

    //Begin algorithm and reset back/front to starting positions
    back = i + 1;
    for (front = 0; front < bound; front++) { 
	    //Take off prime
	    sum -= primes[front];
	    if (!primeSieve[sum]) {
		    int tempCount = back - i + count - front + 1;
		    if (tempCount > count) {
			    maxPrime = sum;
		    }
	    }

	    //Continue to add primes to back until we reach max
	    while (sum + primes[back] < MAX) {
		    sum += primes[back];	
		    back++; 	
	    }

	    //Check again for exceeding count before another prime is taken off and
	    //changes the current sum
	    if (!primeSieve[sum]) {
		    int tempCount = back - i + count - front + 1;
		    if (tempCount > count) {
			    maxPrime = sum;
		    }
	    }
    }

    cout << "Answer: " << maxPrime << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    delete [] primeSieve;

    return 0;
}
