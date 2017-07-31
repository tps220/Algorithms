#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

 
int triangleGen(int &num) {
	return num * (num - 1) / 2;
}

int isTriangle(int &num, bool triangle[10000]) {
	if (triangle[num]) {
		return 1;
	}
	return 0;
}

int squareGen(int &num) {
	return num * num;
} 
int isSquare(int& num, bool square[10000]) {
	if (square[num]) {
		return 2;
	}
	return 0;
}

int pentagonalGen(int &num) {
	return num * (3 * num - 1) / 2;
}
int isPentagonal(int& num, bool pentagonal[10000]) {
	if (pentagonal[num]) {
		return 4;
	}
	return 0;
}
int hexagonalGen(int &num) {
	return num * (2 * num - 1);
}
int isHexagonal(int& num, bool hexagonal[10000]) {
	if (hexagonal[num]) {
		return 8;
	}
	return 0;
} 

int septagonalGen(int &num) {
	return num * (5 * num - 3) / 2;
}
int isSeptagonal(int& num, bool septagonal[10000]) {
	if (septagonal[num]) {
		return 16;
	}
	return 0;
}

int octagonalGen(int &num) {
	return num * (3 * num - 2);
} 

int switchDigits(int num) {
	return (num % 100) * 100;
}

bool checkAll(int chain[5], int &num, bool triangle[10000], bool square[10000], bool pentagonal[10000], bool hexagonal[100000], bool septagonal[10000]) {
	int result = 0;
	int count = 0;
	
	

}

int generateNumbers(int number, bool triangle[10000], bool square[10000], bool pentagonal[10000], bool hexagonal[100000], bool septagonal[10000]) {
	int chain[5] = { };
	int temp;
	int sum = 0;
	int counter;
	for (counter = 10; counter < 100; counter++) {
		temp = switchDigits(number) + counter;
		if (checkAll(chain, temp, triangle, square, pentagonal, hexagonal, septagonal)) {
			break;
		}
	}
	if (counter == 100) {
		return 0;
	}
	sum += temp;
	cout << temp << endl;
	number = temp;
	for (counter = 10; counter < 100; counter++) {
		temp = switchDigits(number) + counter;
		if (checkAll(chain, temp, triangle, square, pentagonal, hexagonal, septagonal)) {
			break;
		}
	}
	if (counter == 100) {
		return 0;
	}
	sum += temp;
	cout << temp << endl;
	number = temp;
	for (counter = 10; counter < 100; counter++) {
		temp = switchDigits(number) + counter;
		if (checkAll(chain, temp, triangle, square, pentagonal, hexagonal, septagonal)) {
			break;
		}
	}
	if (counter == 100) {
		return 0;
	}
	sum += temp;
	cout << temp << endl;
	number = temp;
	for (counter = 10; counter < 100; counter++) {
		temp = switchDigits(number) + counter;
		if (checkAll(chain, temp, triangle, square, pentagonal, hexagonal, septagonal)) {
			break;
		}
	}
	if (counter == 100) {
		return 0;
	}
	sum += temp;
	cout << temp << endl;
	return sum;
}



int main() {

const int MAX = 10000;
bool triangle[MAX] = {false };
bool square[MAX] = {false };
bool pentagonal[MAX] = {false };
bool hexagonal[MAX] = {false };
bool septagonal[MAX] = {false };
for (int i = 2; triangleGen(i) < MAX; i++) {
	triangle[triangleGen(i)] = true;
}
for (int i = 2; squareGen(i) < MAX; i++) {
	square[squareGen(i)] = true;
}
for (int i = 2; pentagonalGen(i) < MAX; i++) {
	pentagonal[pentagonalGen(i)] = pentagonal;
}
for (int i = 2; hexagonalGen(i) < MAX; i++) {
	hexagonal[hexagonalGen(i)] = true;
}
for (int i = 2; septagonalGen(i) < MAX; i++) {
	septagonal[septagonalGen(i)] = true;
}


//If the last two digits of a number come up again,
//we know that its not cyclical, so skip over it
bool duplicate[100] = { false };


//Check the number that increases the most each iteration,
//so it has the least possibilities. That would be the octagonal number.
//Before our loop, find the lower bound for the octagonal number
//
//n * (3n - 2) = number
//3n^2 - 2n = number
//9n^2 - 6n = 3 * number
//9n^2 - 6n + 1 = 3 * number + 1
//(3n - 1)^2 = 3* number + 1
//3n - 1 = sqrt(3 * number + 1)
//n = sqrt(3 * number + 1) + 1  / 3

int n = (int)((sqrt(3 * 999 + 1) + 1) / 3) + 1;  //adding one to find first four digit octagonal number
bool found = false;
int number = octagonalGen(n);
int sum = 0;
while (number < 10000) {
	while (number % 100 < 10 && !duplicate[number % 100] && number < 10000) {
		number = octagonalGen(++n);
	}
	duplicate[number % 100] = true;
	sum = generateNumbers(number, triangle, square, pentagonal, hexagonal, septagonal);
	if (sum > 0) {
		sum += number;
		break;
	}
	number = octagonalGen(++n);
}
cout << sum << endl;

}
