//compile -> g++ linear1.cpp -o linear (cd codes)
//linear cpp
//user input data, ask the data to search, look the data
#include <iostream>
using namespace std;
int main(){
	//variables
	int a[100], i, n, x, flag=0;
	cout << "Enter n: ";
	cin >> n;
	cout <<"Enter " << n << " numbers: ";
	for (i=0;i<n;i++)
	cin >> a[i];
	cout << "Enter number to search: ";
	cin >> x;
	for (i=0;i<n;i++){
	if (a[i]==x){
	cout << "Number " << x << "is present at position " << i+1;
	flag = 1;}
	}
	if (flag==0)
		cout <<"Search unsuccessful";
	return 0;
}
