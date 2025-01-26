#include <iostream>

using namespace std;

int main(){

	string address;
	getline(cin, address);
	string vowels = "AEIOUaeiou";
	int i = 0;
	for (char c : address){
		if (vowels.find(c) == string::npos || i == 0 || address[i-1] == ' '){
			cout << c;
		}	
		++i;		
	}
	cout << endl;
		
}

