#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	// making the ui
 	int len;
	char str1[256];
	cout << "*************" << endl;
	cout << "CAPITALIZING EACH WORD" <<endl;
	cout << "*************" << endl;
	cout << "Please enter a sentence: ";
	cin.getline(str1, 256);
	//gettting the length
	len = strlen(str1);
	str1[0] = toupper(str1[0]);
	
	// making the letter uppercase before space
	for (int i = 1; i < len; i++)
	{
		if ( str1[i - 1] == ' ' )
			str1[i] = toupper( str1[i] );
		else
		// to lower the rest of the word
		str1[i] = tolower(str1[i]);
	}
	//outputing the results
	cout << str1 << endl;
	return 0;
}
