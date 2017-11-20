//Thomas Salemy
//Project Euler Solutions
//Problem 49: Prime Permutations
//Question: What 12-digit number do you form by 
//concatenating the three terms in this sequence?
//(i) each of the three terms are prime, and, 
//(ii) each of the 4-digit numbers are permutations of one another.

#include <iostream>
#include <time.h>
#include <vector>
#include <sstream>
using namespace std;


//Good way to compare digits is to use a frequency
//mapping with an int array of size 10
bool sameDigits(int num1, int num2) {

	int digits[10] = { 0 };
	int digits2[10] = { 0 };
	while (num1 > 0) {
		digits[num1 % 10]++;
		digits2[num2 % 10]++;
		num1 /= 10;
		num2 /= 10;
	}
	for (int i = 0; i < 10; i++) {
		if (digits[i] != digits2[i]) {
			return false;
		}
	}
	return true;
}






//Some observations:
//Max difference between the primes in the sequecne
//is 3333 since we are starting at 1000. 
//Minimum difference has to be 333 to be able to cycle 
//through the same numbers.
int main() {    
    clock_t time = clock();

    //PRIME SIEVE IMPLEMENTATION
    bool *primeSieve = new bool[10000]();
    vector<int> primes;
    int MAX = 10000;
    //Deal With Even Numbers
    int i = 4;
    while (i < MAX) {
	    primeSieve[i] = true;
	    i += 2;
    }
    //Deal with Odds
    for (i = 3; i < MAX; i += 2) {
	    if ( !primeSieve[i] ) {
		    for (int k = i * 2; k < MAX; k += i) {
			    primeSieve[k] = true;
		    }
		    if (i > 1000) {
			    primes.push_back(i);
		    }
	    }	
    }

    //Algorithm
    string answer = "";
    int bound = primes[primes.size() - 1] - 333;
    int found = 0;
    for (int i = 0; primes[i] < bound; i++) {
	    int num1 = primes[i];
	    int k = i + 1;

	    while (k < primes.size()) {
		    int num2 = primes[k];
            //Check least time consuing process first
		    if (num2 - num1 >= 333 && num2 - num1 <= 3333 && sameDigits(primes[i], primes[k])) {
			    int next = 2 * num2 - num1; // k + (k - i) --> second number + difference = third num in sequence
			    if (next < MAX && !primeSieve[next] && sameDigits(next, primes[k])) {
				    ostringstream ss;
				    ss << primes[i];
				    ss << primes[k];
				    ss << next;
				    answer = ss.str();
			        found++;
                }
		    }
		    k++;
	    }
        if (found == 2) {
            break;
        }
    }
    cout << "Answer: " << answer << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
}



