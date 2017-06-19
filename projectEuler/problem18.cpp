#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

//This problem with my solution takes 0.0001 seconds to run. It should not take longer.



//In this problem, it's really helpful if you've done the problem that asks to find the max
//number of paths from the top left of a cube to the bottom right. I would suggest
//doing that problem first, or at the very least, reading my solution of that and then
//trying that problem before you look at this solution. It will expose you to
//my thought process that can be complicated.


//If we are to find the path that creates the max sum, and we are instructed to report that sum...
//we could care less about the actual path. Instead of implementing the brute force method
//that checks each of the 16000 paths seperately, we need to apply some sort of dynamic
//programming algorithm where we can memorize our results as we continue through a loop.
//This is what my solution will do.


//First and foremost, I would suggest copy and pasting the triangle into any text editor
//and deleting the preceeding spaces to make a right triangle. By doing this, you will see
//that the data in front of us is just a staircase of numbers, and that in the original triangle,
//by going diagonally to the left, we are really just going down one row. By going diagonally to the
//right, our only other option, we are going down one row and one column to the right.

//That said, if we put these numbers into a ragged array, each index represents the intersection
//that some path flows through. That said, thankfully a path only has two options,
//either go down or go down and to the right one when looking at the right triangle.
//If each index represents an intersection of all the paths before it, we should
//set an algorithm up where each index before the current one represents the max path sum.
//We would do this by looking at which number diagonal to it (above or above and to the left)
//is greater, and adding it to the current one. We can do this since every path only has
//two options as I continue to say.


//Lets loop through this idea.
//If we continue to add the bigger value of the two diagonal indexes before,
//we will continue to represent each index as the maximum possible sum of the
//paths that intersect it that point,
//By the time we get to the bottom, our algorithm has created a row of the path that creates
//the maximum sum for each of those points.
//When we calculate the biggest number in that row, we will have found the max
//sum that can be created from going top to bottom.

//If you don't understand, please try to draw it out. I guarentee you will see what I'm saying.
//It comes down to implementing a simple algorithm that makes a choice of which
//diagonal should be added for the number underneath



int main() {

    clock_t time = clock();
    int MAX = 0;

    //Open text file
    ifstream file("problem18.txt");
    if (file.is_open()) {

        //If file is succesfully opened, read in the values and
        //dynamically create a ragged array
        //that represents the triangle as a staircase of numbers.
        int** numberMap;
        numberMap = new int*[15];
        for (int i = 0, count = 1; i < 15; i++, count++) {
            numberMap[i] = new int[count];
        }

        //Variables for row of triangle and column of the
        //triangle will be dynamically calculated based
        //on the current count.
        //The first character of a number
        //represents the tens place, and the second represents
        //the ones place. Use this to make a simple I/O algorithm
        //that properly reads the data of the text file.
        int row = 0;
        int column = 0;
        int count = 0;
        char ch;
        while (file >> ch) {
            if (count == (row + 1) * 2) {   //row changes how many numbers its stores every increment
                row++;
                column = 0;
                count = 0;
            }
            if (count % 2 == 0) {
                numberMap[row][column] = (ch - 48) * 10;
            }
            else {
                numberMap[row][column] += (ch - 48);
                column++;
            }
            count++;
        }


        //Start our algorithm
        for (int i = 1; i < 15; i++) {
            for (int k = 0; k < i + 1; k++) {
                if (k == 0) {
                    numberMap[i][k] += numberMap[i - 1][k];
                }
                else if (k < i) {
                    if (numberMap[i - 1][k - 1] > numberMap[i - 1][k]) {
                        numberMap[i][k] += numberMap[i - 1][k - 1];
                    }
                    else {
                        numberMap[i][k] += numberMap[i - 1][k];
                    }
                }
                else {
                    numberMap[i][k] += numberMap[i - 1][k - 1];
                }
            }
        }

        //Find max number in the last row, our answer
        for (int i = 0; i < 15; i++) {
            if (numberMap[14][i] > MAX) {
                MAX = numberMap[14][i];
            }
        }

        //Delete numberMap
        for (int i = 0; i < 15; i++) {
          delete [] numberMap[i];
        }
        delete [] numberMap;
    }
    else {
        cout << "File could not be opened" << endl;
    }

    cout << "Answer: " << MAX << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;

};
