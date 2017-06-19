//Project Euler Solutions
//Problem 3: Largest Prime Factor
//Thomas Salemy

#include <iostream>
#include <cmath>
#include "time.h"
using namespace std;

//Using dynamic programming, all it takes for this small number is a simple 
//algorithm where we check to see if the number is divisible by a series of factors.
//
//We start at a factor of two. If the original, big number is divisible 
// by the factor, continue to divide by it until this becomes false.
//
// Then, go through all the odd factors up until the square root of the number.
// If you reach the square root of the new, smaller 
// number, then that's the biggest prime we got! 
//
int main() {

clock_t time = clock();
long number = 600851475143;
long factor;



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

