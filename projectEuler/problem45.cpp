#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;


long long triangle(int &num) {
	return (long)num * (num + 1) / 2;
}

bool isPentagonal(long long num) {
	num = 24 * num + 1;
	long root = sqrt(num);
	if (root * root == num && (root + 1) % 6 == 0) {
		return true;
	}
	return false;
}


bool isHexagonal(long long num) {
	num = 8 * num + 1;
	long long root = sqrt(num);
	if (root * root == num && (root + 1) % 4 == 0) {
		return true;
	}
	return false;
}


int main() {

clock_t time = clock();


//Find starting number with algebra
//
//x = n ( n + 1) / 2
//2x = n^2 + n
//8x = 4n^2 + 4n
//8x + 1 = 4n^2 + 4n + 1
//8x + 1 = (2n + 1)^2
//sqrt(8x + 1) = 2n + 1
//sqrt(8x + 1) - 1   /   2  == n
int i = (sqrt(8 * 40755 + 1) - 1) / 2;
long long triangularNumber = triangle(++i);

for (i = i + 1; triangularNumber < 100000000000; i++) {
	if ( isPentagonal(triangularNumber) && isHexagonal(triangularNumber)) {
		break;
	}
	triangularNumber = triangle(i);
}

cout << "Answer: " << triangularNumber << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

return 0;

}
