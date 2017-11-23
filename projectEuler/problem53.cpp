//Thomas Salemy
//Project Euler Solutions
//Problem 53


#include <iostream>
#include <time.h>
using namespace std;


int main() {
    clock_t time = clock();

    const int limit = 102;
    int count = 0;
    int** pascal = new int*[limit];
    for (int i = 1; i < limit; i++) {
	    pascal[i] = new int[i];
	    pascal[i][0] = 1;
	    pascal[i][i - 1] = 1;
        for (int k = 1; k < i - 1; k++) {
		    pascal[i][k] = pascal[i - 1][k] + pascal[i - 1][k - 1];
		    if (pascal[i][k] >= 1000000) {
			    pascal[i][k] = 1000000;
			    count++;
		    }
	    } 
    } 

    //Cleanup memory
    for (int i = 0; i < limit; i++) {
	    delete [] pascal[i];
    }
    delete [] pascal;

    cout << "Answer: " << count << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 0;
}

