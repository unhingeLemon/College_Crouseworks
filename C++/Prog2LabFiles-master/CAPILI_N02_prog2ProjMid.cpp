#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <unistd.h>

using namespace std;

void board();
void swap();
void boardR();
void menu();
void menu2();

int coord[4][4];
int r1,c1,r2,c2;

int main() {
	int a = 0;
	int o = 0;
	char x = 'x';
	bool loop = true;
	char choice;
	
	int pairs[16] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
	
	// to shuffle the array of pairs using algoritm library.
	std::random_shuffle(pairs, pairs + 16);
	
	//putting all the shuffled pairs to the coord.
	for (int i = 0; i < 4 ; i++) {
		for(int j = 0; j < 4 ; j++){
			coord[i][j] = pairs[a++];
		}
	}
	// UI aesthetic purposes 
	cout << " __  __                                     _____                      _ \n";
	cout << "|  \\/  |                                   / ____|                    | |\n";
	cout << "| \\  / | ___ _ __ ___   ___  _ __ _   _   | |  __  __ _ _ __ ___   ___| |\n";
	cout << "| |\\/| |/ _ \\ '_ ` _ \\ / _ \\| '__| | | |  | | |_ |/ _` | '_ ` _ \\ / _ \\ |\n";
	cout << "| |  | |  __/ | | | | | (_) | |  | |_| |  | |__| | (_| | | | | | |  __/_|\n";
	cout << "|_|  |_|\\___|_| |_| |_|\\___/|_|   \\__, |   \\_____|\\__,_|_| |_| |_|\\___(_)\n";
	cout << "                                   __/ |                                \n";
	cout << "                                  |___/                \n\n";
	cout << "                                             By: Mark Angelo Capili\n\n\n";
	cout << "				[1] START\n\n";
	cout << "				[2] QUIT		:";
	cin >> a;
	if (a == 1){
		goto jmp;	
	}
	else if (a == 2){
		cout << "QUITTING...\n";
		sleep (3);
		return 0;
		}
	else {
		cout << "INCORRECT!\n";
		cout << "QUITTING... ";
		sleep (3);
		return 0;
	}
	jmp:
	menu2();
	board();
	system ("cls");
	swap();

	while(loop) {
		
		if (coord[r1-1][c1-1] == coord[r2-1][c2-1] ) {
			cout << "MATCH!\n";
			cout << "CONGRATSS! wanna try again? [y][n]";
			cin >> choice;
			if (choice == 'y'){
				loop = true;
			} else {
				return 0;
			}
		}else {
			cout << "DO NOT MATCH! TRY & TRY UNTIL YOU SUCCEED! >:-| ";
		}
		board();
		system ("cls");
		swap();
	}	
	
}

void board() {
	bool loop1 = true;
	//Displaying the board using for loop
    cout<<"\n    1 2 3 4\n   ";
    for (int i=0; i<8; i++){
        cout<<"_";
    }
    cout<<"\n";
    for (int j=0; j <4; j++){
        cout<<j+1<<" | ";
        for (int k=0; k<4; k++)
        {
            cout<<"* ";
        }
        cout<<"\n";
    }
    
    cout<<endl;
    
	//Asking for input from the user
	
	while (loop1) {
	
		cout << "Please enter the 1st card's rows and columns(seperated by space): ";
		cin >> r1 >> c1;
		cout << "Please enter the 2st card's rows and columns(seperated by space): ";
		cin >> r2 >> c2;
		// the user must not input the same rows and columns
		if (r1 == r2 && c1 == c2) {
			cout << "You can't input the same rows and columns! TRY AGAIN ! >:( \n";
			loop1 = true;
			system ("pause");
			system ("cls");
		} else {
			loop1 = false;
		}
	}
}

void swap () {
	// swaaping the * to numeric value
	cout<<"\n    1 2 3 4\n   ";
    for (int i=0; i<8; i++){
        cout<<"_";
    }
    cout<<"\n";
    for (int j=0; j <4; j++){
        cout<<j+1<<" | ";
        for (int k=0; k<4; k++)
        {
 			if ((j==r1- 1)&&(k==c1-1))
            {
                cout<<coord[j][k]<<" ";
            }
            else if((j==r2-1)&&(k==c2-1))
            {
                cout<<coord[j][k]<<" ";
            }
            else
            {
                cout<<"* ";
            }
        }
        cout<<"\n";
    }
}

void boardR(){
	//Displays the board with numbers to help the player win the game
	cout << "     1   2   3   4\n";
	cout << "_________________________\n";
	cout << "1|   " << coord[0][0] <<"   " << coord[0][1] << "   "<<coord[0][2]<<"   " << coord[0][3] << "\n\n";
	cout << "2|   " << coord[1][0] <<"   " << coord[1][1] << "   "<<coord[1][2]<<"   " << coord[1][3] << "\n\n";	
	cout << "3|   " << coord[2][0] <<"   " << coord[2][1] << "   "<<coord[2][2]<<"   " << coord[2][3] << "\n\n";	
	cout << "4|   " << coord[3][0] <<"   " << coord[3][1] << "   "<<coord[3][2]<<"   " << coord[3][3] << "\n\n";
}

void menu2(){
	// For aesthetic purposes again :)
	cout << "\n\n\n		YOU MUST FIND TWO IDENTICAL NUMBERS, THEN YOU WIN :) \n";
	sleep(5);
	system ("cls");	
	
	cout << "\n\n\n		HOW QUICK IS YOUR BRAIN? \n\n";
	sleep(4);
	system ("cls");
	cout << "\n\n\n		TRY TO MEMORIZE THIS \n";
	sleep(3);
	system ("cls");
	
	boardR();
	sleep(2);
	system ("cls");
	
	cout << "\n\n\n		TOO FAST? OH NO! TRY TO GUESS, MY FRIEND :) \n";
	sleep(4);
	system ("cls");	

}


