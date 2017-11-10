//Thomas Salemy
//Project Euler Solutions
//Problem 11: Largest Product in a grid 
//Question: What is the greatest product of four adjacent 
//numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid

#include <iostream>
#include <fstream>
#include "time.h"
using namespace std;


int main() {

    clock_t time = clock();
    int MAXSIZE = 19;
    int map[20][20] = { {0} };
    ifstream file("problem11.txt");
    if (!file.is_open()) {
        cerr << "Could not open file" << endl;
    }
    char ch;
    int count = 0;
    int column = 0;
    int row = 0;
    while (file >> ch) {
        if (column == 20) {
            column = 0;
            row++;
        }
        if (count % 2 == 0) {
            map[row][column] = (ch - 48) * 10;
        }
        else {
            map[row][column] += ch - 48;
            column++;
        }
        count++;
    }    
    file.close();
    
    long maxProduct = 0;
    long product;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            
            //Check Horizontal (Only To Right)
            product = 1;
            for (int column = j; column < j + 4; column++) {
                if (column > MAXSIZE) {
                    break;
                }
                product *= map[i][column];
            }
            if (product > maxProduct) {
                maxProduct = product;
            }

            //Check Vertical (Only Down)
            product = 1;
            for (int row = i; row < i + 4; row++) {
                if (row > MAXSIZE) {
                    break;
                }
                product *= map[row][j];
            }
            if (product > maxProduct) {
                maxProduct = product;
            }

            //Check Diagonals
            //(1)
            product = 1;
            for (int row = i, column = j; row < i + 4; row++, column++) {
                if (row > MAXSIZE || column > MAXSIZE) {
                    break;
                }
                product *= map[row][column];
            }
            if (product > maxProduct) {
                maxProduct = product;
            }
            
            //(2)
            product = 1;
            for (int row = i, column = j; row > i - 4; row--, column++) {
                if (row < 0 || column > MAXSIZE) {
                    break;
                }
                product *= map[row][column];
            }
            if (product > maxProduct) {
                maxProduct = product;
            }
            
            //(3)
            product = 1;
            for (int row = i, column = j; row < i + 4; row++, column--) {
                if (row > MAXSIZE || column < 0) {
                    break;
                }
                product *= map[row][column];
            }
            if (product > maxProduct) {
                maxProduct = product;
            }
            
        }
    }
    
    cout << "Answer: " << maxProduct << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
};
