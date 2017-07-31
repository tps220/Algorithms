#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;



int main() {

clock_t time = clock();

int lowerBound;
int count = 0;
int n = 1;
while (lowerBound < 10) {
	lowerBound = (int) ceil(pow(10, (n - 1.0) / n));
	count += 10 - lowerBound;
	n++;
}



//Zero mathematics way, which doesnt allow the last case to be checked
//int count = 1;
//for (int i = 2; i < 10; i++) {
//	int power = 1;
//	unsigned long long number = i;
//	for (;;) {
//		if ((int)log10(number) + 1 != power) {
//			break;
//		}
//		cout << number << " " << power << endl;
//		count++;
//		number *= i;
//		power++;
//	}
//}




cout << count << endl;
cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

}

