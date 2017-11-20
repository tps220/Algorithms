//Thomas Salemy
//Project Euler Solutions
//Problem 37: Truncatable primes
//Question: Find the sum of the only eleven 
//primes that are both truncatable from left to right and right to left

#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

//Log10 of the number
int length(int num) {
	if (num < 10) {
		return 1;
	}
	return 10 * length(num / 10);
}


//Implement a prime sieve and store all the primes inside a vector
int main() {
    clock_t time = clock();
    
    //Prime Sieve Initialization
    const int bound = 1000;
    const int MAX = 1000000;
    bool *primeSieve = new bool[1000000]();
    vector<int> primes;
    
    primeSieve[0] = true;
    primeSieve[1] = true;
    primes.push_back(2);

    //Begin Algorithm
    int i = 4;
    while (i < MAX) {
	    primeSieve[i] = true;
	    i += 2;
    }

    for (i = 3; i < MAX; i += 2) {
	    if ( !primeSieve[i] ) {
		    primes.push_back(i); //if prime add to vector
		    for (int j = i * 2; j < MAX; j += i) {
			    primeSieve[j] = true;
		    }
	    }
    }
    

    int SUM = 0;
    int count = 0;
    i = 5; //start with number > 10
    while (count < 11) {
        //If all conditions met, variable primer stays true
	    bool primer = true;
	    int number = primes[i];
	    int size = length(number);

	    //If number > 100, must have 3 and 7 at starting + ending positions
        //in order to be left and right compatible
	    //If less than 100, right digit must be occupied by 3 or 7
	    if (number < 100) {
		    while (number % 10 != 3 && number % 10 != 7) {
			    number = primes[++i];
		    }
	    }
	    else {
		    while ( (number % 10 != 3 && number % 10 != 7) || (number / size != 3 && number / size != 7) ) {
			    number = primes[++i];
			    size = length(number);
		    }
	    }
	    size = 10;
	    while (size < number) {
		    if (primeSieve[number / size] || primeSieve[number % size]) {
			    primer = false;
			    break;
		    }
		    size *= 10;
	    }
	    if (primer) {
		    SUM += number;
		    count++;
	    }
	    i++;
    }

    delete [] primeSieve;
    
    cout << "Answer: " << SUM << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 0;
}
