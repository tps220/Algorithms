//Thomas Salemy
//Project Euler Solutions
//Problem 33: Digit Cancelling Fractions
//Find the product of the four non-trivial
//instances and give the value of the denominator
//in its lowest common terms

#include <iostream>
#include <time.h>
using namespace std;

//Find a formulaic approach to the problem,
//and then limit the bounds of what to search
// 
//My Observation:
//16 / 64 can be rewritten as 1 * 10 + 6 /  6 * 10 + 4
//More generally,
//(a * 10 + b) / (b * 10 + c) = a / c
//After cross produts, we get that:
//ab10 + ac = ac10 + bc
//ac9 + bc = ab10


//Eulers algorithm for greatest common denominator
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);	
}


int main() {
    clock_t time = clock();
    int denominator = 1;
    int numerator = 1;
    for (int b = 2; b < 10; b++) {
	    for (int a = 1; a < b; a++) {
		    for (int c = 1; c < 10; c++) {
			    if (a*c*9 + b*c == a*b*10) {
				    denominator *= c;
				    numerator *= a;
		    	}   	
	    	}
    	}			
    }
    cout << "Answer: " << denominator / gcd(denominator, numerator) << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

    return 0;
}
