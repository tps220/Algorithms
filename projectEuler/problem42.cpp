#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;


int main() {

clock_t time = clock();
bool tri[1000] = { false };
int iterator = 1;
for (int i = 1; i < 1000; i += iterator) {
	tri[i] = true;
	iterator++;
}


int count = 0;
ifstream file("problem42.txt");
if ( file.is_open() ) {
	char ch;
	int wordValue = 0;
	while (file >> ch) {
		if (ch == ',') {
			if (tri[wordValue]) {
				count++;
			}
			wordValue = 0;
		}
		else if (ch > 64 && ch < 123) {
				wordValue += ch - 'A' + 1;
		}
	}
}
else {
	cout << "File could not be opened" << endl;
}
file.close();


cout << "Answer: " << count << endl;
cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;


}
