#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>
using namespace std;



bool isPerfectSquare(long num) {
	num = 24 * num + 1;
	long root = sqrt(num);
	if (root * root == num) {
		if ( (root + 1) % 6 == 0) {
			return true;
		}
	}
	return false;
}

long pentagonal(int i) {
	return (long)i * (3 * i - 1 ) / 2;
}



int main() {

clock_t time = clock();
long result = 0;

for (int i = 4; i < 1000000; i++) {
	for (int k = i - 1; k > 0; k--) {
		long a = pentagonal(i);
		long b = pentagonal(k);
		if (isPerfectSquare(a + b) && isPerfectSquare(a - b)) {
			result = a - b;
		}
	}
	if (result != 0) {
		break;
	}
}


cout << "Answer: " << result << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

return 0;

}

 
