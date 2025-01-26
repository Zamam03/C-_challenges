#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	double prod = 1;
	for (int i = 0; i < n; ++i){
		double y;
		cin >> y;
		prod *= y;		
	}
	cout << pow(prod, 1.0 / n) << endl;
	return 0;	
}