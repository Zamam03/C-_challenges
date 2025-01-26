#include <iostream>

using namespace std;

//compute the factorial of N:
long long factorial(int N){
	long long prod = 1;
	for (int i = 1; i <= N; ++i){
		prod *= i;
	}	
	return prod;
}

// compute the permutations of x and y: P(x, y)
long long P(int x, int y){
	return factorial(x) / factorial(x - y);	
}

// compute the combinations of x and y: C(x, y)
long long C(int x, int y){
	return P(x, y) / factorial(y);
}



int main(){
	
	int x, y;
	cin >> x >> y;
	cout << C(x, y) << endl;
	return 0;	
}