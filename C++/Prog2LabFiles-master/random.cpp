#include <iostream>
#include <cstdlib> //for random
#include <time.h> // for *time
using namespace std;

int main() {

	int rNum[10];
	srand(time(NULL)); // to give random value everytime the program runs
	for (int i = 0; i < 10; i++) {
		rNum[i] = rand() % 21; // to give 0-20 r value
	}
	cout << "The random numbers are: ";

	for (int i = 0; i < 10; i++) {
		cout << rNum[i] << " "; // printing all the random values
	}

}
