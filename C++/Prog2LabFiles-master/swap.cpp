#include <iostream>
using namespace std;

void swap(int a, int b);

int main(){
	int n1,n2;
	n1 = 1; n2=2;
	cout << n1 << n2 <<endl;
	swap(n1,n2);
	cout << n1 <<n2;
	
}

void swap(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
	
}
