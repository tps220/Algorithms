#include <iostream>
#include<time.h>
#include <math.h>
using namespace std;

bool isRoot(long long num) {
	long root = (long)sqrt(num);
	if (root * root == num) {
		return true;
	}
	return false;
}

int main() {

bool squareNumber[1000] = { false };
for (int i = 1; i * i < 1000; i++) {
	squareNumber[i * i] = true;
}

int maxX = 0;
int maxD = 2;
for (int D = 3; D < 1000; D++) {
	if (squareNumber[D]) {
		D++;
	}
	long long x;
	for (x = 2; x < 10000; x++) {
		if ( (x * x - 1) % D == 0) {
			if ( isRoot((x * x - 1) / D) ) {
				break;
			}
		}
	}
	if (x > maxX) {
		maxD = D;
		maxX = x;
	}
}


}
