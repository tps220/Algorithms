#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

//We will take advantage of prime factorization techniques to efficiently solve this problem
//First, imagine a triangular number. It's a pyramid with base length n, and every row up
//has length n - 1 until that value reaches zero and the triangle is formed.
//Therefore, the nth triangular number is the sum from 1 to n, or n * (n + 1) / 2.
//
//
//To find the number of factors of the triangular number, the best way to start off
//is to break up the triangular number into its two driving parts,  n  and  n + 1, 
//and  somehow mathematically combining them.
//This way, since we need to calculate the factors of a triangular number thats massive,
//we can essentially cut the time by square root time by only calculating the
//factors of n + 1 and remembering it.
//
//How can we do this? Well, there's a simple mathematical fact...
//Number = factor1^n, factor2^b, factor3^r and so on
//Number of factors for that number is equal to (1 + n) * (1 + b) * (1 + r) or essentially
//the number of times a factor repeats itself, we add it to one, and multiply it into a 
//result. We are only worried about the number of factors, not their values, so this becomes
//very helpful. 
//
//However, if we have two different numbers that share factors it becomes very difficult
//to combine the results of our factorization into what these two numbers multiply to.
//
//One would think it would just be:
//numFactorsOfA * numFactorsOfB, which would look like : (1 + n) * (1 + b) .... * (1 + n) where n is the coefficient
//of the shared factor. But by our method, we are mutliplying the instances of a factor together and this violates
//our rule
//
//However, thankfully n and n + 1 are coprimes by fact which means they don't share any of the same factors... so
//we can juts multiple the number of factors together because it mathematically results in the total number of factors
//of what the two coprimes multiply to :)
//
//it becomes bigNum =  firstNum * secondNum = (firstNum) a ^ n * c ^ r * (secondNum) e ^ g * m * n
//all of factors of big num = (1 + n) * ( 1 + r) * (1 + g).....
//It's as simple as that.
//
//With some tweaking, we can easily implement this technique

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
return 1;
};
