#include <iostream>
#include <time.h>
using namespace std;


// 16 / 64..... 1 * 10 + 6 /  6 * 10 + 4
// a * 10 + b / b * 10 + c = a / c
// ab10 + ac = ac10 + bc
//ac9 + bc = ab10

//For the fraction to maintan < 1, a must be smaller than b



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
