#include <iostream>
#include <time.h>
#include <vector>
#include <sstream>
using namespace std;


//I find it very curious that both differences for the final
//answers are 3330.
//Nonetheless, all I did was try to implement
//the fastest method to go through all primes,
//and the difference between all the primes after it.
//Max difference can only be 3333 since we are
//starting at 1000. Minimum difference has to
//be 333 to be able to cycle through the same numbers.
//If you think about, adding 111 will change at least one
//digit to a digit not already in the number.
//222 will do the same. 
//
//333 is the min to have a cycle of digits. Since
//3 + 3 + 3 + 1 >= 10. Im getting the + 1 from
//carrying over one of the digits that exceeds
//its place. Such as 6147.... we get 6470 ( almost there :)  )


//Compare the mappings of two numbers' digits,
//looking at the frequency of each possible digit.
//Comapre at end to see if they are the same
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


int main() {

clock_t time = clock();

//CONSTANTS
int MAX = 10000;

//PRIME SIEVE IMPLEMENTATION
bool primeSieve[10000] = { false };
vector<int> primes;
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
for (int i = 0; primes[i] < bound; i++) {
	int num1 = primes[i];

	//Loop through all other primes,
	//when in logic statements with && statements
	//check the least time consuming process first
	int k = i + 1;
	while (k < primes.size()) {
		int num2 = primes[k];
		if (num2 - num1 >= 333 && num2 - num1 <= 3333  &&  sameDigits(primes[i], primes[k])) {
			int next = 2 * num2 - num1; // k + (k - i) --> second number + difference = third num in sequence
			if (next < MAX  &&  !primeSieve[next]  &&  sameDigits(next, primes[k])) {
				ostringstream ss;
				ss << primes[i];
				ss << primes[k];
				ss << next;
				answer = ss.str();
			}
		}
		k++;
	}
}

cout << "Answer: " << answer << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

}



