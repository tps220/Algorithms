#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;



int main() {

clock_t time = clock();
int count = 1;
int result = 0;
BigInteger numerator = new BigInteger(3);
BigInteger denominator = new BigInteger(2);
long long numerator = 3;
long long denominator = 2;

while (count <= 10000) {
	numerator = numerator + denominator * 2;
	denominator = numerator - denominator;
	if (numerator.digits() > denominator.digits()) {
		result++;
		cout << numerator << " / " << denominator << endl;
	}
	count++;
}

cout << result << endl;
cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;


}
