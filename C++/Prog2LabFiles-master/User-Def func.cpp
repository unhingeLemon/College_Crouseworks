#include <iostream>

using namespace std;

float square(float& side);


int main(){
	int choice;
	float s;
	cout << "************************\n";
	cout <<	"MENU\n";
	cout <<	"************************\n";
	cout << "[1] - Area of a square\n";
	cout << "[2] - Area of a rectangle\n";
	cout << "[3] - Area of a triangle\n";	
	cout << "[4] - Area of a circle\n";
	cout << "[5] - Exit\n";
	cout << "________________________\n";
	cout << "Enter your choice: ";
	cin >> choice;
	
	switch (choice){
		case 1:
			cout << "________________________\n";
			cout << "AREA OF SQUARE \n";
			cout << "________________________\n";
			cout << "Enter the side of the square: ";
			cin >> s;
			cout << endl << endl;
			cout << "The area is " << square(s) << "sq. units";
		
		
	}
	
	
	
	
	
	
	
	return 0;
}

float square(float& side) {
	float result;
	result = side * side;
	return result;
}





