#include <iostream>
#include <time.h>
using namespace std;


int main() {

clock_t time = clock();

int ** board;
board = new int*[1001];
for (int i = 0; i < 1001; i++) {
	board[i] = new int[1001];
}
board[500][500] = 1;

int numberCounter = 2;
int spiralCounter = 3;
int row = 500;
int column = 500;



while (spiralCounter <= 1001) {
	int i = 0;
	column++;
	for (i = 0; i < spiralCounter - 1; i++) {
		board[row][column] = numberCounter;
		row++;		
		numberCounter++;
	}
	row--;
	for (i = 0; i < spiralCounter - 1; i++) {
		column--;
		board[row][column] = numberCounter;
		numberCounter++;
	}
	for (i = 0; i < spiralCounter - 1; i++) {
		row--;
		board[row][column] = numberCounter;
		numberCounter++;
	}
	for (i = 0; i < spiralCounter - 1; i++) {
		column++;
		board[row][column] = numberCounter;
		numberCounter++;
	}
	spiralCounter += 2;
}


long SUM = -1;
for (int i = 0, j1 = 0, j2 = 1000; i < 1001; i++, j1++, j2--) {
		SUM += board[i][j1] + board[i][j2];
}		
for (int i = 0; i < 1001; i++) {
	delete [] board[i];
}
delete [] board;

cout << "Answer: " << SUM << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;



}
