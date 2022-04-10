#include <iostream>
#include <cstring>
using namespace std;

int main() {
	//For UI
	char str1[256];
	char str2[256];
	cout << "*************" << endl;
	cout << "STRING COMPARE \n";
	cout << "*************" << endl;
	cout << "Enter a first word: ";
	cin.getline(str1,256);
	cout << "Enter a second word: ";
	cin.getline(str2,256);
	// algo for determining the result
	if(strcmp(str1,str2) == 0) {
		cout << "Equal";
	} else if (strcmp(str1,str2) == -1) {
		cout << "Negative";
	} else if (strcmp(str1,str2) == 1) {
		cout << "Positive";
	} 
	return 0;
}

