//Thomas Salemy
//Project Euler Solutions
//Problem 15: Lattic Paths
//How many routes are there in a 20x20 grid, moving down and to the right?

#include <iostream>
#include <time.h>

using namespace std;

//The inefficient approach is try to count each path in the 20 x 20 grid with your program.
//That would take ages. So let's try to think of another way

//So, I first ask you to look at the grid and think... how can I store a solution for 
//the number of paths I took previously, and step by step build onto that until I reach an end condition?

//Use a grid, with each box representing the number of paths that go through that box.
//After reaching the bottom right box, it will represent the total number of possible paths to
//get to that box, aka our answer

// For the outskirts of the grid, only one straight path can get you to each of the squares. 
// Therefore, the first row down and to the right of a grid should be filled in with a 1

// Now, start from the box directly diagonal from the starting position. Since the paths
// above it and to the left are the only ways to get to the box (can only move down and to the right), 
// this means the number of possible paths that can go through this box is the sum of
// the box above and to the left i

//Also note, a 20 x 20 grid in this problem means that you are supposed to follow the lines
//so if each intersection point is a box, that box would be 21 x 21


bool fillPaths(long map[21][21]) {
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 21; j++) {
			map[i][j] = map[i - 1][j] + map[i][j - 1];
		}
	}
	return true;
};


int main() {

    clock_t time = clock();

    long pathMap[21][21] = { };
    for (int i = 0; i < 21; i++) {
	    pathMap[0][i] = 1;
	    pathMap[i][0] = 1;
    }

    fillPaths(pathMap);

    cout << "Answer: " << pathMap[20][20] << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 1;

};
