//Thomas Salemy
//Project Euler Solutions
//Problem 79

#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
using namespace std;


int main() {
    clock_t time = clock();

    ifstream file("problem79.txt");
    if (!file.is_open()) {
	    cerr << "Could not open file" << endl;
        return -1;
    }

    vector< vector<int> > board(10);
    vector<int> logins;
    int attempt;
	while (file >> attempt) {
		logins.push_back(attempt);
	}

    for (int i = 0; i < logins.size(); i++) {
	    int firstNumber = logins[i] / 100;
	    int secondNumber = (logins[i] / 10) % 10;
	    int thirdNumber = logins[i] % 10;
	    int foundSecond = -1;
	    int foundThird = -1;
	    for (int counter = 0; counter < board[firstNumber].size(); counter++) {
		    if (board[firstNumber][counter] == secondNumber) {
			    foundSecond = counter;
			    if (foundThird > -1) {
				    break;
			    }
		    }
		    else if (board[firstNumber][counter] == thirdNumber) {
			    foundThird = counter;
		    }
	    }
	
	    if (foundThird > -1 && foundSecond == -1) {
		    board[firstNumber].push_back(secondNumber);
	    }
	    else if (foundThird == -1 && foundSecond > -1) {
		    board[firstNumber].push_back(thirdNumber);
	    }
	    else if (foundThird == -1 && foundSecond == -1) {
		    board[firstNumber].push_back(secondNumber);
		    board[firstNumber].push_back(thirdNumber);
	    }

	    foundThird = -1;
	    for (int counter = 0; counter < board[secondNumber].size(); counter++) {
		    if (board[secondNumber][counter] == thirdNumber) {
			    foundThird = counter;
			    break;
		    }
	    }
	    if (foundThird == -1) {
		    board[secondNumber].push_back(thirdNumber);
	    }
    }

    int previousMAX = 11;
    int previousIndex;
    for (;;) {
	    int MAX = 0;
	    int INDEX = 0;
	    for (int i = 0; i < board.size(); i++) {
		    if (board[i].size() > MAX && board[i].size() < previousMAX) {
			    MAX = board[i].size();
			    INDEX = i;
			    previousIndex = i;
		    }
	    }
	    if (MAX == 0) {
		    cout << board[previousIndex][0] << endl;
		    break;
	    }
	    previousMAX = MAX;
	    cout << INDEX;
    }

    cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 0;
}

