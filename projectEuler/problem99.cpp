//Thomas Salemy
//Project Euler Solutions
//Problem 99
#include <iostream>
#include <time.h>
#include <math.h>
#include <fstream>
using namespace std;

int main() {
    clock_t time = clock();

    ifstream file("problem99.txt");
    if (!file.is_open()) {
        cerr << "Could not open file" << endl;
        return -1;
    }
    int maxLine = 0;
    double MAX = 0;

    int base;
	char comma;
	int exponent;
	int lineNumber = 1;
	while (file >> base >> comma >> exponent) {
		double size = exponent * log10(base);
		if (size > MAX) {
			maxLine = lineNumber;
			MAX = size;
		}
		lineNumber++;
	}

    cout << maxLine << endl;
    cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 0;
}
