//Thomas Salemy
//Project Euler Solutions
//Problem 17: Number Letter Counts
//Question: If the numbers 1 to 5 are written out in words: 
//one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
//If all the numbers from 1 to 1000 (one thousand) inclusive were written 
//out in words, how many letters would be used?

#include <iostream>
#include <time.h>
using namespace std;

int main() {

    clock_t time = clock();

    //Setup the letter count for each unique number
    int namingMap[1000] = { };
    namingMap[0] = 0; //0 not included in any pronounciation
    namingMap[1] = 3;
    namingMap[2] = 3;
    namingMap[3] = 5;
    namingMap[4] = 4;
    namingMap[5] = 4;
    namingMap[6] = 3;
    namingMap[7] = 5;
    namingMap[8] = 5;
    namingMap[9] = 4;

    namingMap[10] = 3;
    namingMap[11] = 6;
    namingMap[12] = 6;
    namingMap[13] = 8;
    namingMap[14] = 8;
    namingMap[15] = 7;
    namingMap[16] = 7;
    namingMap[17] = 9;
    namingMap[18] = 8;
    namingMap[19] = 8;
    namingMap[20] = 6;
    namingMap[30] = 6;
    namingMap[40] = 5;
    namingMap[50] = 5;
    namingMap[60] = 5;
    namingMap[70] = 7;
    namingMap[80] = 6;
    namingMap[90] = 6;


    //Loop through the patterns and rules
    int SUM = 11; //corner case of one thousand
    for (int i = 1; i < 1000; i++) {
	    int currentNum = i;
	    if (currentNum % 100 == 0) {
		    SUM += 7; //Exactly hundred multiple, only 7
		    SUM += namingMap[currentNum / 100]; //what hundred is it?
	    }
	    else {
		    if (currentNum > 100) {
			    SUM += 10; //Hundred + and
			    SUM += namingMap[currentNum / 100]; //what hundred is it?
			    currentNum %= 100; //go to tens place
		    }
		    if (currentNum < 20) {
			    SUM += namingMap[currentNum];
		    }
		    else {
			    SUM += namingMap[(currentNum / 10 ) * 10]; //get only the tens place
			    currentNum %= 10; //go to ones place
			    SUM += namingMap[currentNum]; //add the ones place
		    }
	    }
    }

    cout << "Answer: " << SUM << endl;
    cout << "Time: " << (clock() - time) / (double)CLOCKS_PER_SEC << endl;

}
