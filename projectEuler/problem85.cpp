#include <iostream>
#include <time.h>
#include <math.h>
#include <stdlib.h>
using namespace std;





//How many lines can fit into line of length width? length 1 goes into it w times,
//length 2 can overlap and go into it w - 1 times... length 3 can overlap and go into it w - 2 times...
//keep on going until length w goes into it one time.... so its the sum from 1 to w which is w * (w + 1) / 2
//Same logic for the height, so:
//	total combinations = width combinations * height combinations = w * (w + 1) / 2 * h * (h + 1) / 2 :)
//
//Now time to find when that combination comes closest to 2,000,000
//
//
//f(x, y) = x * (x + 1) * y * (y + 1) / 4..... 2,000,000 = x * (x + 1) * y * (y + 1) / 4
//y^2 + y = 8,000,000 / (x^2 + x)
//4y^2 + 4y = 32,000,000 / (x^2 + x)
//(2y + 1)^2 = 32,000,000 / (x^2 + x) + 4
//y = (sqrt((32,000,000 / x^2 + x) + 4) - 1) / 2


long returnArea(int& x) {
	int y = (int)((sqrt(32000000.0 / (x * x + x) + 4) - 1) / 2);
	return (long)y * (y + 1) * x * (x + 1) / 4;
}

int main() {

clock_t time = clock();

int xMAX = (int)((sqrt(32000000.0 / (5 * 5 + 5) + 4) - 1) / 2);
long smallestDifference = abs(2000000 - (long)xMAX * (xMAX + 1) * 5 * (5 + 1) / 2);
int result = 5;
for (int x = 6; x < xMAX; x++) {
	long difference = abs(2000000 - returnArea(x));
	if (abs(difference < smallestDifference)) {
		result = x;
		smallestDifference = difference;
	}
}
cout << result * (int)((sqrt(32000000.0 / (result * result + result) + 4) - 1) / 2) << endl;
cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;


}
