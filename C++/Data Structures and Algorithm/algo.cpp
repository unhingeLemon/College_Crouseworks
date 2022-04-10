//#include <iostream>

//using namespace std;
//int x = 0;
//
//void sort(int a[], int b[], int n){
//	//init array count;
//	int i,t,count[x+1];
//	
//	
//	// first loop
//	for(i = 0;i<=x;i++){
//		count[i]=0;
//	}
//	
//	//2nd loop
//	//count the occurance of the element
//	for(i = 0;i<n;i++){
//		t = a[i];
//		count[t]++;
//	}
//	
//	//3rd loop
//	//update count of the array
//	for(i=1;i<=x,){
//		count[i] = count[i]+count[i-1];
//		
//	}
//	
//	//4th
//	// add and decrement the values
//	
//	for(i=0;i<n;i++){
//		t = a[i];
//		b[count[t]] = t;
//		count[t] = count[t-1];
//	}
//	
//}
//
//int main(){
//	int n,i;
//	int a[];
//	cout << "Enter the size of the array";
//	cin >> n;
//	int a[n];
//	int b[n];
//	for(i = 0;i<n;i++){
//		cin >> a[i]
//	}
//	sort(a,b,n);
//	
//	
//}


//create the program
#include<iostream>
using namespace std;
int x = 0;
void sort(int a[], int b[], int n);
int main(){
int n,i;
int a[100], b[100];
cout <<"Enter the size of the array ";
cin >> n;
for (i=0;i<n;i++){
cin >> a[i];
if (a[i]>x){
x=a[i];
}
}
sort(a,b,n);
for (i=1;i<=n;i++){
cout << b[i] << " ";
}
cout <<endl;
return 0;
}
void sort(int a[], int b[], int n)
{
int i;
int t;
//initialized the array count
//1st loop
int count[x+1];
for (i=0;i<=x;i++){
count[i]=0;
}
//count the occurance of the elements
for (i=0;i<n;i++)
{
t = a[i];
count[t]++;
}
//update count of the array
for (i=1;i<=x;i++){
count[i] = count[i]+count[i-1];
}
//Add and decrement the values
for (i=0;i<n;i++){
t=a[i];
b[count[t]] = t;
count[t]=count[t]-1;
}
}
