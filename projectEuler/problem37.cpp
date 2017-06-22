#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

//Size of number in comparison to 10, 100, 1000 etc.
int length(int num) {
	if (num < 10) {
		return 1;
	}
	return 10 * length(num / 10);
}



//Implement a prime sieve that finds all prime numbers, and then
//add all those prime numbers to a vector so we can loop
//through the vector knowing each number is a prime. 
//
//Next, check if the prime is left and right compatible. If so,
//add to the sum
int main() {


//CONSTANTS
int MAX = 1000000;
int bound = 1000;
clock_t time = clock();


//Prime Sieve
bool primeSieve[1000000] = { false };
vector<int> primes;

//Corner Cases
primeSieve[0] = true;
primeSieve[1] = true;
primes.push_back(2);

//Begin Sieve
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
	bool primer = true; //if all conditions met, stays true
	int number = primes[i]; //iterate through primes until count == 11
	int size = length(number); //size is used to look at first number

	//If number > 100, this means to be left and right compatible,
	//can only have numbers 3 and 7 at starting/ending positions.
	//
	//If less than 100, has to have right numbers by 3 or 7
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
cout << "Answer: " << SUM << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;


}
