#include <iostream> 
#include <cstring>
using namespace std; 

int main() 
{ 
	//making the ui
	string str;
	cout << "*************" << endl;
	cout << "STRINGS TO WORDS" <<endl;
	cout << "*************" << endl;
	cout << "Please enter a sentence: ";
    getline(cin,str);

    int i = str.length() - 1; 
    int start, end = i + 1; 
    string result = ""; 
    //string to words algo
    for(i; i >=0; i--) {
        if(str[i] == ' ') 
        { 
			start = i + 1; 
			while(start != end){
                result += str[start++]; 
            }
            //make every word go to new line
            result += " \n"; 
            end = i; 
        }     	
	}
    start = 0; 
    while(start != end){
    	result += str[start++]; 
	}    
    //outputing the result
    cout << result; 
      
    return 0; 
} 
