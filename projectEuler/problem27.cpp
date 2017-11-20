//Thomas Salemy
//Project Euler Solutions
//Problem 27: Quadratic Primes
//Question: Find the product of the coefficients, a and b, 
//for the quadratic expression that produces the maximum number 
//of primes for consecutive values of n, starting with n=0.




#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;


//To optimize solution, should use the following:
//
//(1) Since n * n + a * n + b must equal a prime number, when we plug in 0 for n, we
//get in the most literal equation, b must equal some prime number. So yeah, b = prime number.
//Therefore, implementing a prime sieve to first check whether b is prime, and then determine whether
//the function produces a prime seems like the most effective approach. To minimize memory and maximize speed,
//a boolean array is all we need. Also, we will start with n > 40 since that's our given max sequence so far and
//continue to update it so we limit the numbers we check
//
//(2) f(n) = n^2 - 79n + 1601 is simply a transformation of g(n) = n^2 + n + 41.
//Since both graphs are quadratic, they are symmetric across the y-axis. Therefore,
//for every value of n the opposite side of curve, it produces the same number. 
//g(n) reaches 1601 at the same pace, and through the same numbers at two different points, 
//at 39 and at -39. Since the problem at hand can only use n >= 0,  g(n) is only accounting for half of what it can
//Therefore, f(n) is simply a transformation of g(n) that accounts for its other unused numbers that are negative.
//It was simply shifted over perfectly to follow the
//same exact behavior as g(n), 
//This doubles the prime sequence from 40 to 80.
//
//
//How do we use this?
//If we search for -1000 < a < 1000,
//we will likely (not sure though) find two solutions that produce the same numbers. 
//Therefore, to maximize the sequence for the quadratic we come up with, 
//the value of a needs to be the more negative one that takes advatage of the left side
//of our graph.
//
//
//Overall: According to my observations, B has to be prime.
//Since B does not equal two, we know it is also odd. So, we can say that A is odd and increment it by
//two as well because only an odd + even = more odds
//And, in order to hit the max number of primes, a should probably be negative (even though it technically doesnt have to)
//so that the graph has a longer trajectory and hit the sequence it produces twice.
//




void primeSieve(bool array[1000000]) {
    for (int i = 2; i < 999; i++) {
	    if ( !array[i] ) {
		    for (int j = i * 2; j < 1000000; j+= i) {
			    array[j] = true;
		    }
	    }
    }
};

bool checkQuadraticFunction(int &n, int &a, int &b, bool array[1000000]) {
	int fx = (n) * (n) + (a) * (n) + b;
	if (fx < 2) {
		return false;
	}
	else {
		return  !array[fx];
	}
};

int main() {
    clock_t time = clock();

    bool primes[1000000] = {false};
    primeSieve(primes);

    int maxLength = 40;
    int product = 0;

    for (int a = -999; a < 0; a+=2) {
	    for (int b = 3; b < 997; b += 2) {
		    if (!primes[b]) {
                int n = 40;
			    while (checkQuadraticFunction(n, a, b, primes)) {
				    n++;
			    }
			    if (n > maxLength) {
				    maxLength = n;
				    product = a * b;
			    }
		    }
	    }
    }

    cout << "Answer: " <<  product << ", Length: " << maxLength << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 0;
};
