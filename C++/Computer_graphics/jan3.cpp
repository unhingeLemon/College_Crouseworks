#include<iostream>
#define SIZE 100
#define CS0045 cout

using namespace std;

int main(){
	
	int z = 200;
	int *y;
	
	const int size=100;
	
	int x[size]={1,2,3,4,5};
	int *a;
	
	y = &z;
	a = x;
	
	cout << "------------POINTERS------------------" << endl;
	cout << z << "<--->" << y << endl;
	cout << z << "<--->" << *y << endl;
	cout << &z << endl; //& - address of
	cout << *(&z) << endl;
	
	*y=500;
	cout << z << endl;
	
	//Pointers and Arrays
	cout << "------------POINTERS AND ARRAYS------------------\n";
	cout << x << " " << &x[0] << " " << *x << endl;
	cout << sizeof(int) << endl;
	cout << x+1 << " " << &x[1] << " " << *(x+1) << endl;
	
	cout << a << " " << &a[0] << " " << *a << endl;
	cout << sizeof(int) << endl;
	cout << a+1 << " " << &a[1] << " " << *(a+1) << endl;
	
	/*
	for(int i=0; i < 100; i++){
		CS0045 << x[i] << endl;
	}
	*/
	
	return 0;
}
