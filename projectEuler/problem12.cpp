//Thomas Salemy
//Project Euler Solutions
//Problem 12: Highly divisible triangular number
//Question: What is the value of the first triangle number to have over five hundred divisors?

#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

//Take advantage of prime factorization techniques to efficiently solve this problem

//First, imagine a triangular number. It's a pyramid with base length n, and every row up
//has length n - 1 until that value reaches zero and the triangle is formed.
//Therefore, the nth triangular number is the sum from 1 to n, or n * (n + 1) / 2.

//To find the number of factors of the triangular number, the best way to start off
//is to break up the triangular number into its two driving parts, n and n + 1, 
//and somehow mathematically combining them.

//This way, since we need to calculate the factors of a triangular number thats massive,
//we can essentially cut the time by square root time by only calculating the
//factors of n + 1 and remembering it.

//How can we do this? Well, there's a simple mathematical fact...
//Number = factor1^a * factor2^b * factor3^c and so on
//Therefore, the number of factors for that number is equal to (1 + n) * (1 + b) * (1 + r) based
//on counting principals

//Since only worried about the number of factors, not their values, this becomes very helpful  
//Thankfully n and n + 1 are coprimes by fact which means they don't share any of the same factors... so
//we can juts multiple the number of factors together because it mathematically results in the total number of factors
//of what the two coprimes multiply to :)

int factors(int number) {
	int total = 1;
	int count = 1;

	if (number % 2 == 0) {
		number /= 2;
	}
	while (number % 2 == 0) {
		number /= 2;
		count++;
	} 		
	total *= count;

	for (int i = 3; i <= number && number != 1; i += 2) {
		count = 1;
		while (number % i == 0) {
			number /= i;
			count++;
		}
		total *= count;
	}
	return total;
};

int main() {
    clock_t time = clock();
    
    //Start with triangular number three
    int first = 2;
    for (int i = 5; i < 1000000; i++) {
	    int second = factors(i + 1);
	    if (first * second > 500) {
		    long result = i * (i + 1) / 2;
		    cout << "Answer: " <<  result << ", Factors: " << first * second << endl;
		    break;
	    }
	    first = second;
    }

    cout << "Time: " << ( clock() - time ) / (double) CLOCKS_PER_SEC << endl;
    return 0;
};
