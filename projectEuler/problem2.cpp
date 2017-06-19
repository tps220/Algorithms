//Project Euler Solutions
//Problem 2: Even Fibonacci Numbers
//Thomas Salemy

#include <iostream>
#include "time.h"
using namespace std;

int nextNum(int current, int previous) {
	return current * 4 + previous;
};

int main() {

clock_t time = clock();
//Initial Values
int current = 8;
int previous = 2;
int next;
long sum = 10; //starting with 2 and 8

while (next < 4000000) {
	sum += next;
	next = nextNum(current, previous);
	previous = current;
	current = next;
}

cout << "Answer: " << sum << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
return 0;
};
	
	
