#include <iostream>
#include "time.h"
using namespace std;


int main() {

clock_t time = clock();

int power5map[10];
for (int i = 0; i < 10; i++) {
	power5map[i] = i * i * i * i * i;
}

int TOTAL_SUM = 0;
for (int i = 100; i < 354000; i++) {
	int sum = 0;
	sum += power5map[i % 10];
	sum += power5map[ (i / 10) % 10];	
	sum += power5map[ (i / 100) % 10];
	sum += power5map[ (i / 1000) % 10];
	sum += power5map[ (i / 10000) % 10];
	sum += power5map[ (i / 100000) % 10];
	if (sum == i) {
		TOTAL_SUM += i;
	}	
}

cout << "Answer: " << TOTAL_SUM << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;


}

