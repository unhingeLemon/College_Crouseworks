#include <iostream>
#include <cstring>
using namespace std;

int main() {
	//For UI
	int len,temp;
	char str1[20];
	char str2[20];
	bool isPal;
	cout << "*************" << endl;
	cout << "PALINDROME\n";
	cout << "*************" << endl;
	cout << "Enter a word: ";
	cin.getline(str1,20);
	len = strlen(str1);
	//outputting the word backwards
	cout << "The backward of the word is: ";
	for (int i = 0; i < len ;i++){
		temp = len - i - 1;
		cout << str1[temp];
	}
	
	//determining if the word is palindrome
	for(int i=0 ;i < len ;i++){
        if(str1[i] != str1[len-i-1]){
            isPal = 1;
            break;
       }
   }
	cout << endl;
	if (isPal) {
		cout << str1 << " is not palindrome";
	} else {
		cout << str1 << " is a palindrome";
	}
	return 0;
}	

