//Thomas Salemy
//Project Euler Solutions
//Problem 5: Smallest Multiple
//Question: What is the smallest positive number that is evenly divisible
//by all of the numbers from 1 to 20


#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return a * power(a, b - 1);
};


int main() {
    clock_t time = clock();
    vector<int> factorMap;
    //initializes the vector with 20 values, with each index representing a factor
    factorMap.assign(20, 0);

    //For each number from 1 -> 20, find out the max number of factors
    //needed to represent every number
    for (int i = 2; i <= 20; i++) {
        int number = i;
        for (int j = 2; j <= i; j++) {
            int count = 0;
            while (number % j == 0) {
                number /= j;
                count++;
            }
            if (count > factorMap[j]) {
                factorMap[j] = count;
            }
        }
    }

    int finalNumber = 1;
    for (int i = 2; i < factorMap.size(); i++) {
        finalNumber = finalNumber * power(i, factorMap[i]);
    }

    cout << "Answer: " << finalNumber << endl;
    cout << "Time: " << (double)(clock() - time)  / (double)  CLOCKS_PER_SEC << endl;
    return 0;
};
