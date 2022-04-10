#include <iostream>
#include <cstring>
using namespace std;

int main() {
	//For UI
	char str1[256];
	char str2[256];
	cout << "*************" << endl;
	cout << "STRING COPY \n";
	cout << "*************" << endl;
	cout << "Enter a first word: ";
	cin.getline(str1,256);
	cout << "Enter a second word: ";
	cin.getline(str2,256);
	strcpy (str1,str2);
	//outputing the new value of str1
	cout << "The New String Value for str1: " << str1;
	return 0;	
}

