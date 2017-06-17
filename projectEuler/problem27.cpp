#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;


//I spent a longggg time trying to find a number of optimizations for this method, however, I could only a few
//that are not proven but nonetheless make sense. They could be luck. Hopefully not as I think they are pretty
//cool
//
//
//For each of the two equations, when the max n is plugged in, they reach a value of 1601. This got me wondering.
//What values of a and b make n increase... essentially which numbers produce more primes. And just in general,
//are there any other patterns?
//
//(1) Well first, since n * n + a * n + b must equal a prime number, when we plug in 0 for n, we 
//get in the most literal equation,  b must equal a prime number. So yeah,  b = prime number.
//Therefore, implementing a prime sieve to first check whether b is prime, and then determine whether
//the function produces a prime seems like the most effective approach. To minimize memory and maximize speed,
//a boolean array is all we need. Also, we will start with n > 40 since that's our given max sequence so far and
//continue to update it so we limit the numbers we check
//
//(2)    f(n) = n^2 - 79n + 1601 is an optimization of g(n)  n^2 + n + 41. Why? Because all that f(n) does differently
//      is shift the values of g(n) over. Since both graphs are quadratic, they are symmetric across the y-axis. Therefore,
//      for every value of n the opposite side of curve, it produces the same number. g(n) reaches 1601 at the same pace, and through
//      the same numbers at two different points. at 39 and at -39. Therefore, g(n) is only accounting for half of what it can
//      since the mathematical problem at hand can only use n >= 0. this makes the origin of the second equation a lot easier to understand.
//      f(n) is simply the optimization of g(n) that accounts for its other unused numbers that are negative.
//      since we are using quadratics, f(n) was simply shifted over perfectly to follow the
//      same exact behavior as g(n), except all the unused negative numbers for g(n) that produced those unused primes become a part of the sequence.
//      As a result, they can now be used for solving when n > 0, what is the longest sequence of prime numbers the function can produce.
//      This doubles the answer from 40 to 80.
//      So, wWhat actually happens is that the numbers start high, go lower and lower, and then 
//      finally go upwards. And most importantly, the function only touches 40 unique primes.
//
//	How do we use this?
//      In a calculus sense,the deriviate of these equations are negative for a while and then becomes positive.
//      In general, the derivitive of the general equation n^2 + a * n + b is 2 * n + a. If we search for -1000 < a < 1000,
//      we will find two solutions that follow the same exact path. Therefore, to maximize whatever
//      quadratic we come up with, the value of a needs to be the more negative one that takes advatage of the left side
//      of our graph.
//
//
//Soooooooo, after these realizations I bounded a and b differently. 
//According to my observations, B had to be positive.
//For one, b has to be prime as proven. And secondly if you don't believe that, in order for the slope be negative
//and the resulting graph / prime number be positive, b has to translate the graph upwards above the x-axis. So, limit b to greater than 1.
// On top of that, make b always odd by incrementing it by two instead of one since b = 2 does not make the longest chain, and thats the only even prime
//Then, make sure to increment a by two and make it even, since an odd + odd = even, odd + even = odd, and even + even = even.
//
//Now, in order to hit the max number of primes, a should probably be negative (even though it technically doesnt have to)
//so that the graph has a longer trajectory and hit the sequence it produces twice.
//
//




void primeSieve( bool array[1000000] ) {

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

for(int a = -999; a < 0; a+=2) {
	for (int b = 3; b < 997; b += 2) {
		if ( !primes[b] ) {
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
