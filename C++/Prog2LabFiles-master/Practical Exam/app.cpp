#include <iostream>
#include <fstream> //FOR FILE HANDLING
#include <string>
#include <conio.h>
#include <stdio.h>
using namespace std;

//CLASS FOR THE DATAS OF USERS
class Data {
	public:
		int accNum;
		string lName;
		string fName;
		string bal;
};
//IO FILES
//ofstream outFile("data.txt", std::ios_base::app);
//ifstream inFile ("data.txt", std::ios_base::app);
//ofstream fileTemp ("datatemp.txt",std::ios_base::app);
//ifstream accFile("accounts.txt",std::ios_base::app);
int choice;
//FUNCTIONS
void writeRec(); // TO WRITE THE RECORD
void readRec(); // READ THE RECORD
void searchRec(); // SEARCH THE RECORDS
void editRec();// EDIT A RECORD
void delRec(); // DELETE A RECORD

int main(){
	while(1){
	
		//  it must contain account number, first name, last name and balance
		cout << "1 - Write Record\n"; 
		// read the record using the account number
		cout << "2 - Read Record\n";
		// search the record using the account number
		cout << "3 - Search Record\n";
		// search using the account number
		cout << "4 - Edit Record\n";
		// edit record using the account number
		cout << "5 - Delete Record\n";
		// delete record using account number
		cout << "6 - Exit\n\n";
		cout << "Your Choice: ";
		cin >> choice;
		system("cls");
		switch(choice){
			case 1:
				writeRec();
				system("cls");
				break;
			case 2:
				readRec();
				system("cls");
				break;
			case 3:
				searchRec();
				system("cls");
				break;
			case 4:
				editRec();
				system("cls");
				break;
			case 5:
				delRec();
				break;
			case 6:
				system("cls");
				return 0;
				break;
			default:
				cout << "Invalid key. Please Try again!:";
				system("pause");
				system("cls");
				break;
				
		}
	}
}

void writeRec(){
	ofstream outFile("data.txt", std::ios_base::app);
	ofstream outaccFile("accounts.txt",std::ios_base::app);
	Data info; // CALLING THE CLASS
	//ASKING FOR INPUTS
	cout << "Account number: ";
	cin >> info.accNum;
	outFile<< info.accNum << endl;
	outaccFile << info.accNum << endl;
	cout << "First Name: ";
	cin >> info.fName;
	outFile << info.fName << endl;
	cout << "Last Name: ";
	cin >> info.lName;
	outFile << info.lName<< endl;
	cout << "Balance: ";
	cin >> info.bal;
	outFile << info.bal<< endl;
	outFile.close();
}

void readRec(){
	ifstream inFile ("data.txt", std::ios_base::app);
	string line;
	string accNum2;
	cout << "Enter the Account Number: ";
	cin >> accNum2;
	// THIS WILL SEARCH THOURGH EVERY LINE 
	// UNTIL IT FOUNDS THE ACC NUMBER
	// AFTER 3 LINES OF ACC NUMBER,
	// IT WILL BE OUTPUTED
	while (!inFile.eof()){
		inFile >> line;
		if(accNum2 == line){
		for (int i=0;i < 3;i++){
			inFile >> line;
			if(i==0)
			cout << "First Name: " << line << endl;	
			else if (i==1)
			cout << "Last Name: " << line << endl;
			else 
			cout << "Balance: " << line << endl;
			}
			system("pause");	
		}
	}
	inFile.close();
}


void searchRec(){
	ifstream accFile("accounts.txt",std::ios_base::app);
	string accNum2;
	string search;
	cout << "Enter the Account Number: ";
	cin >> search;
	// WILL SEARCH THOURGH EVERY LINE IN THE ACCOUNT.TXT
	// THEN IT WILL CHECK FOR EQUALITY
	while (!accFile.eof()){
		accFile >> accNum2;
		if (search == accNum2){
			cout << "Record Found!\n";
			system("pause");
			break;
		} else if (accFile.eof()){
			cout << "Record Not Found!\n";
			system("pause");
			break;
		}
	}
	accFile.close();
}

void editRec(){
	ifstream inFile ("data.txt", std::ios_base::app);
	ofstream fileTemp ("datatemp.txt",std::ios_base::app);
	Data info2;
	string line1;
	string accNum3;
	string strTemp[3];
	// ASKING FOR NEW INPUTS
	cout << "Enter the Account Number: ";
	cin >> accNum3;
	string strReplace[3];
	string strNew[3];
	cout << "New First Name: ";
	cin >> info2.fName;
	strNew[0] = info2.fName;
	cout << "New Last Name: ";
	cin >> info2.lName;
	strNew[1] = info2.lName;
	cout << "New Balance: ";
	cin >> info2.bal;
	strNew[2] = info2.bal;
	// THIS WILL SEARCH THE TXT FILE
	// AND THEN WILL FIND THE ACC NUMBER
	// AND AFTER THE 3 LINES OF ACC NUM,
	// IT WILL BE EDITED AND
	// ALL THE NEW DATA WILL BE SAVED TO A NEW TXT FILE
	for(int i = 0 ; i < 3;i ++){
		strReplace[i] == strNew[i];
	}
	string line2;
	while (!inFile.eof()){
		inFile >> line2; 
	if(accNum3 == line2){
		
		fileTemp << accNum3 << endl;
		for (int i=0;i < 3;i++){
			fileTemp << strNew[i]<<endl;
			inFile >> line2;
		}
	}
	else if (accNum3 != line2){
		fileTemp << line2 << endl;	
	}	
	}
	// TO RENAME AND REMOVE THE TXT FILE
	inFile.close();
	fileTemp.close();
	system("del.\\data.txt");
	system("ren.\\datatemp.txt data.txt");
	cout << "Successfully edited the account!\n";
	system("pause");
}


void delRec() {
	//to overwrite accounts.txt
	ifstream accFile("accounts.txt",std::ios_base::app);
	ofstream outaccFile("accountstemp.txt",std::ios_base::app);
	//to also overwrite data.txt
	ifstream inFile ("data.txt", std::ios_base::app);
	ofstream fileTemp ("datatemp.txt",std::ios_base::app);
  	string line3;
  	cout << "Enter Account Number: ";
  	string accNum;
  	cin >> accNum;
  	while(!inFile.eof()){
  		inFile >> line3;
  		if(line3==accNum){
  			for(int i =0;i < 4 ;i++){
  				inFile >> line3;
			  }
		  } fileTemp << line3 << endl;
		  
	}
	//to delete accnumber in accounts.txt
	string acc;
	while (!accFile.eof()){
		accFile >> acc;
		if (acc == accNum){
			accFile >> acc;
		}
		outaccFile << acc << endl;
	}
	
	//close all files
	inFile.close();
	fileTemp.close();
	outaccFile.close();
	accFile.close();
	//to rename and delete the files to complete overwrite
	system("del.\\accounts.txt");
	system("ren.\\accountstemp.txt accounts.txt");
	system("del.\\data.txt");
	system("ren.\\datatemp.txt data.txt");
	cout << "\nSuccesfully Deleted Account: " << accNum << endl << endl;

}


