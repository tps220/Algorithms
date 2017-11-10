//Thomas Salemy
//Project Euler Solutions
//Problem 10: Summation of Primes 
//Question: Find the sum of all the primes below two million

#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

//Implement a prime sieve and find the sum of all primes under the bound
int main() {    
    clock_t time = clock();
    
    int MAX = 2000000;
    bool *sieve = new bool[MAX](); 
    int factorBound = sqrt(MAX) + 1;
    long sum = 0;
    
    for (int i = 2; i < factorBound; i++) {
        if (!sieve[i]) {
            sum += i;
            for (int j = i * 2; j < MAX; j += i) {
                sieve[j] = true;
            }
        }
    }

    for (int i = factorBound; i < MAX; i++) {
        if (!sieve[i]) {
           sum += i;
        }
    }

    cout << "Answer: " << sum << endl << "Time: " << (clock() - time ) / (double) CLOCKS_PER_SEC << endl;
    
    delete [] sieve;
    return 0;
};
