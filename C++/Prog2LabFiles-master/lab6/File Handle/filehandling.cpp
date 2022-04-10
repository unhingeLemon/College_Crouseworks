#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream inFile;
	ofstream outFile;
	string fname;
	string lname;
	double test1,test2,test3;
	outFile.open("output.txt");
	inFile >> fname >> lname;
//	inFile.open("sample.txt");

	outFile << "First Name:" << fname << "Last Name: " << lname << endl;
	inFile >> test1 >> test2 >> test3;
	outFile << "average is " << (test1+test2+test3) / 3.0;
	
	
	
		
	inFile.close();
	outFile.close();
	system("paused>0");

	
	
	
}
