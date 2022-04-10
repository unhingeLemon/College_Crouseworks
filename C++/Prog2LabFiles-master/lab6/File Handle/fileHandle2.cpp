#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream inFile;
	ofstream outFile;
	string fname;
	string lname;
	double grade[3];
	outFile.open("output.txt");
	inFile >> fname >> lname;
	
	cout << "Your first name: ";
	cin >> fname;
	cout << "Your last name: ";
	cin >> lname;
	for (int i =0; i < 3; i++) {
		cout << "Your grade: ";
		cin >> grade[0];
	}
	outFile << "First Name:" << fname << endl << "Last Name: " << lname << endl;
	//inFile >> grade;
	outFile << "Your average is " << (grade[0] + grade[1] + grade[2]) / 3;
	
	
	
		
	inFile.close();
	outFile.close();
	//system("paused>0");

	
	
	
}
