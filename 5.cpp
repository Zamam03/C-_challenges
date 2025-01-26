#include <iostream>

using namespace std;


int sumDivisors(int x){
	int sum = 0;
	for (int i = 1; i <= x / 2; ++i){
		if (x % i == 0){
			sum += i;
		}
	}
	return sum;
}

bool isAmicable(int x, int y){
	
	int sx = sumDivisors(x);
	int sy = sumDivisors(y);
	return sx == y && sy == x;

}

int main(){	
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i){
		int x, y;
		cin >> x >> y;
		if (isAmicable(x, y)){
			cout << "Amicable" << endl;
		}
		else{
			cout << "Not amicable" << endl;
		}
	}	
	
}
