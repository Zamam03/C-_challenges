#include <iostream>

using namespace std;

int main(){
	
	string line;
	getline(cin, line);
	for (char c : line){
		char y = c;
		if (97 <= c && c <= 122){
			y = c - 32;
		}
		cout << y;
	}
	cout << endl;
	return 0;	
}