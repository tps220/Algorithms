//Thomas Salemy
//Project Euler Solutions
//Problem 2: Even Fibonacci Numbers
//Question: By considering the terms in the Fibonacci sequence
//whose values do not exceed four million, find the sum of the even-valued terms


#include <iostream>
#include "time.h"
using namespace std;

//Next even fibonacci number = 4 * current + previous
int nextNum(int &current, int &previous) {
	return current * 4 + previous;
};

int main() {

clock_t time = clock();
//Initial Values
int current = 8;
int previous = 2;
int next = 0;
long sum = 2; //starting with 8, need to add base number 2

while (current < 4000000) {
	sum += current;
	next = nextNum(current, previous);
    previous = current;
    current = next;
}

cout << "Answer: " << sum << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

return 0;
};
	
	
