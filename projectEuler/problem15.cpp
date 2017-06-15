#include <iostream>
#include <time.h>

using namespace std;

//When you finally figure this problem out, it comes down to a simple recursive solution
//that uses dynamic programming.
//
//The worst thing you can do is try to count each path in the 20 x 20 grid with your program.
//That would take ages on ages.
//
//So, I first ask you to look at the grid and think... how can I store my solution for 
//every path I took previously?
//
//
//It took me a while to see it, but then I started thinking about each square in the grid as
// a point of intersection:
// When you start from the beginning position, which can only be
// intersected by one path, you move to ther right or down. For the outskirts of the grid, only
// one straight path can get you to each of the squares. Therefore, the first row down
// and to the right of a grid should be filled in with a 1 to represent the number of 
// possible intersections
//
// Now, start from the box directly diagonal from the starting position. Since the paths
// above it and to the left of it can be accessed once each, this means this box can be 
// intersected twice or the sum of their intersections. We either go through the top box
// or go through the left box to get there. 
//
// When you do this until you get to the final position, the final box's number
// represents in my model: the number of intersections possible from the beginning position
// for this box.... or the maximum number of paths for this box from the starting
// position .... aka problem solved.
//
//
// Doing this for a 20 x 20 grid would take a while, so implement a solution using an 
// array and recursively.... looking at the box from the top and to the left to determine
// the current position's value. However, make sure to initialize the first row and column
// to 1 for obvious reasons.
//
//
//When you print out the box on your computer screen, you can actually see
//pascals triangle in action. It's pretty cool. Try doing it for a 100 x 100 :)
//
//
//Also note, a 20 x 20 grid in this problem means that you are supposed to follow the lines
//so if each intersection point is a box, that box would be 21 x 21


bool intersectionFill(long map[21][21]) {
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

intersectionFill(pathMap);

cout << "Answer: " << pathMap[20][20] << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
return 1;
};
