//Project Euler Solutions
//Problem 3: Largest Prime Factor
//Thomas Salemy

#include <iostream>
#include <cmath>
#include "time.h"
using namespace std;



//If the number is divisible by a factor, continue to divide it
//until this becomes false. Since the number ends in a three,
//it will never be divisible by a factor of two. Therefore,
//begin at i and increment through all odd numbers up until the square
//root of the number

int main() {

clock_t time = clock();
long number = 600851475143;

for (int i = 3; i < sqrt(number); i+=2) {
	while (number % i == 0) {
		number /= i;
	}
    if (i > number) {
      break;
    }
}

cout << "final answer: " << number << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
return 0;
};

