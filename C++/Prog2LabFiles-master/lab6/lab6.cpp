#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

ifstream inFile;
ofstream outFile;


int choice;
// structure for storing all the players data
struct Person
{
    char name[50];
    int age;
    int score1;
    int score2;
    float ave;
};

//for IU
void menu(){
	cout << "*********************************\n";
	cout << "              MENU               \n";
	cout << "*********************************\n";
	cout << "1. Add Record\n";
	cout << "2. View Players Records\n";
	cout << "3. Compute For The Average\n";
	cout << "4. Show the player(s) who get the max average\n";
	cout << "5. Show the player(s) who get the min average\n";
	cout << "6. Open the File\n";
	cout << "7. Close the File\n";
	cout << "8. Exit\n";
	cout << "Enter the # of choice: ";
	cin >> choice;
	
}



// ALGORITHM FOR ALL THE REQUIREMENTS in the MENU

int main() {
	int temp1,temp2;
	int aveT = 0;
	menu();
	Person p[5];
	// setting all the members to default values
	for(int i = 0 ; i < 5 ; i++) {
		p[i].age = 0;
		p[i].score1 = 0;
		p[i].score2 = 0;
	}
	while(true){
		switch(choice) {
			//FOR STORING THE DATA INSIDE tHE STRUCT
			case 1:
					for(int i = 0 ; i < 5 ; i++) {
						cout << "PLAYER " << i + 1 << " RECORDS\n";
						cout << "Enter Name: ";
						cin >> p[i].name;
						cout << "Enter Age: ";
						cin >> p[i].age;
						cout << "Enter 1st score: ";
						cin >> p[i].score1;
						cout << "Enter 2nd score: ";
						cin >> p[i].score2;
						system ("cls");	
					}
					// FILE HANDLING
					outFile.open("data.txt");
					for(int i = 0 ; i < 5 ; i++) {
						//cout << "Enter Name: ";
						outFile << "Name: " << p[i].name << endl;
						//cout << "Enter Age: ";
						outFile << "Age: " << p[i].age << endl;
						//cout << "Enter 1st score: ";
						outFile <<"1st Score: " << p[i].score1 << endl;
					//	cout << "Enter 2nd score: ";
						outFile << "2nd Score: " << p[i].score2 << endl;
						outFile << endl << endl << endl;
					}
					
					menu();
				break;
				// FOR OUTPUTING THE AVERAGES
			case 2:
				//if age is STILL 0 then there's still no inputs
				if (p[0].age == 0) {
					cout << "NO INPUT" << endl;
					system ("pause");
					menu();

					}
					for(int i = 0 ; i < 5 ; i++) {
						
						cout << "PLAYER " << i+1 << " RECORDS: \n";
						cout << "NICKNAME: " << p[i].name << endl;
						cout << "AGE: " <<  p[i].age << endl;
						cout << "SCORE1: " << p[i].score1 << endl;
						cout << "SCORE2: " << p[i].score2 << endl << endl;
						p[i].ave = (p[i].score1 + p[i].score2) / 2;
					}
					system ("pause");
					system ("cls");
					menu();
					break;
					// TOTALLING ALL THE AVERAGES
			case 3:
				//if age is STILL 0 then there's still no inputs
				if (p[0].age == 0) {
					cout << "NO INPUT" << endl;
					system ("pause");
					menu();
				}
				for(int i = 0 ; i < 5 ; i++) {
					cout << "PLAYER " << p[i].name << " SCORE AVERAGE: " << endl;
					cout << p[i].ave << endl << endl;
				}
				// FILE HANDLING
				outFile << endl << endl << endl << endl;
				for(int i = 0 ; i < 5 ; i++) {
					outFile << "PLAYER " << p[i].name << " SCORE AVERAGE: " << endl;
					outFile << p[i].ave << endl << endl;
				}
				// outFile.close();
				cout << "TOTAL 5 PLAYERS AVERAGE: "; 
				for(int i = 0 ; i < 5 ; i++) {
					aveT = p[i].ave + aveT ;
				}
				cout << aveT / 5 << endl;
				system ("pause");
				system("cls");
				menu();
				break;
				// ALGO FOR PRODUCING THE MAX AVERAGE
			case 4:
				//if age is STILL 0 then there's still no inputs
				if (p[0].age == 0) {
					cout << "NO INPUT" << endl;
					system ("pause");
					menu();
				}
				temp1 = p[0].ave; 
				for(int i = 0 ; i < 5 ; i++) {
					if(temp1 < p[i].ave){
						temp1 = p[i].ave;
					}
				}
				cout << "THE HIGHEST AVERAGE AMONG ALL PLAYER IS : ";
				for(int i = 0 ; i < 5 ; i++) {
					if(temp1 == p[i].ave){
						cout << p[i].name << endl;
						break;
					}
				}
				// FILE HANDLING
				outFile << "THE HIGHEST AVERAGE AMONG ALL PLAYER IS : ";
				for(int i = 0 ; i < 5 ; i++) {
					if(temp1 == p[i].ave){
						outFile << p[i].name << endl;
						break;
					}
				}
				system ("pause");
				system("cls");
				menu();
				break;
				//ALGO FOR PRODUCING THE MIN AVERAGE
			case 5:
				//if age is STILL 0 then there's still no inputs
				if (p[0].age == 0) {
					cout << "NO INPUT" << endl;
					system ("pause");
					menu();
				}
				temp2 = p[0].ave; 
				for(int i = 0 ; i < 5 ; i++) {
					if(temp2 > p[i].ave){
						temp2 = p[i].ave;
					}
				}
				cout << "THE LOWER AVERAGE AMONG ALL PLAYER IS : ";
				for(int i = 0 ; i < 5 ; i++) {
					if(temp2 == p[i].ave){
						cout << p[i].name << endl;
						break;
					}
				}
				
				
				outFile << "THE LOWER AVERAGE AMONG ALL PLAYER IS : ";
				for(int i = 0 ; i < 5 ; i++) {
					if(temp2 == p[i].ave){
						outFile << p[i].name << endl;
						break;
					}
				}				
				system ("pause");
				system("cls");
				menu();	
				break;						
			case 6:
				cout << "outfile.open command was executed";
				system ("pause");
				system("cls");
				menu();
				break;
			case 7:
				cout << "outfile.close command was executed";
				outFile.close();
				system ("pause");
				system("cls");
				menu();
				break;
			case 8:
				return 0;
				break;
		}
	}
//outFile.close();
	}
	
	
	




