//Thomas Salemy
//Project Euler Solutions
//Problem 39: Integer Right Triangles
//Question: For which value of p ≤ 1000, is the number of solutions maximised?

#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

int gcd(int a, int c) {
	if (c == 0) {
		return a;
	}
	return gcd(c, a % c);
}

//In a right triangle of sides a, b, and c,
//mathemtaically we can represent each number
//with two variables m and n as follows:
//(a, b, c) = (m^2 - n^2, 2mn, m^2 + n^2)
//
//Use a "pythagorean sieve" to store all the
//possible primitive combinations (which means gcd of A and C is 1) 
//and their multiples

int main() {
    clock_t time = clock();
    int pythagor[1001] = { 0 };
    int MAX = 0;
    int perimeter = 0;
    for (int n = 1; n < 50; n++ ) {
	    for (int m = n + 1; m < 50; m++) {
		    //Where the math properties described above come in handy
            int a = m * m - n * n;
		    int b = 2 * m * n;
		    int c = m * m + n * n;

		    if (gcd(a, c) == 1) {
			    int sum = a + b + c;
			    //Fill in the sieve
                for (int k = sum; k <= 1000; k += sum) {
				    pythagor[k]++;
				    if (pythagor[k] > MAX) {
					    MAX = pythagor[k];
					    perimeter = k;
				    }
			    }
		    }
	    }
    }

    cout << "Answer: " << perimeter << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

}
