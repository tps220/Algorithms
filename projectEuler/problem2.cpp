//Project Euler Solutions
//Problem 2: Even Fibonacci Numbers
//Thomas Salemy

#include <iostream>
using namespace std;

int nextNum(int current, int previous) {
	return current * 4 + previous;
};

int main() {

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

cout << sum;
return 0;
};
	
	
