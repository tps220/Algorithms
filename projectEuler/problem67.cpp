#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;


int main() {

clock_t time = clock();
vector<int> board;

ifstream file("problem67.txt");
if ( file.is_open() ) {
	int count = 0;
	char ch;
	while (file >> ch) {
		if (count % 2 == 0) {
			board.push_back( (ch - 48) * 10);
		}
		else {
			board[count / 2] += ch - 48;
		}
		count++;
	}
	//Reverse engineered formula of n * (n + 1) / 2 for triangular numbers to find
	//the height of the triangle
	const int height = (sqrt(8 * board.size() + 1) - 1) / 2;
	
	//Deal with corner cases (first column and last column only have one path possible)
	for (int i = 1; i < height; i++) {

		//starting column represents the triangular number based upon current height
		board[i * (i + 1) / 2] += board[(i - 1) * i / 2];

		//ending column, can be calculated in a couple ways.... I did it as
		//starting column + current height
		board[i * (i + 1) / 2 + i] += board[(i - 1) * i / 2 + i - 1]; 
	}


	for (int i = 1; i < height - 1; i++) {
		for (int k = i * (i + 1) / 2; k < (i + 1) * (i + 2) / 2 - 1; k++) {
			if (board[k] > board[k + 1]) {
				board[(i + 1) * (i + 2) / 2 + k - i * (i + 1) / 2 + 1] += board[k];
			}
			else {
				board[(i + 1) * (i + 2) / 2 + k - i * (i + 1) / 2 + 1] += board[k + 1];
			}
		}
	}

	int MAX = 0;
	for (int i = (height - 1) * height / 2; i < height * (height + 1) / 2; i++) {
		if (board[i] > MAX) {
			MAX = board[i];
		}
	}
	cout << MAX << endl;
	cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
}

else {
	cout << "File could not be opened" << endl;
}

}
