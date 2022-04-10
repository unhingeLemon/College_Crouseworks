//create the program
#include<iostream>
using namespace std;

int main(){
	int x,searchItem;
	cout << "Enter size of array: ";
	cin >> x;
	int arr[x];
	
	cout << "Enter numbers: ";
	
	for(int i = 0; i < x; i++){
		cin >> arr[i];
	}
	
	cout << "Enter Search Item: ";
	cin >> searchItem;
	bool found = 0;
	for(int i = 0;i < x;i++){
		if(arr[i] == searchItem){
			found = 1;
			break;
		}
	}
	
	if(found ){
		cout << "Found!";
	} else {
		cout << "Not Found!";
	}
	
	
	
	
	
	
	
}


