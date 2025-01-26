#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int y){
	//this function takes in an integer y and determines if it is prime
	//complete code here
	
  if (y < 2){
    return false;
  }
  if (y == 2){
    return true;
  }
  for (int i = 2; i < sqrt(y) + 1; i++){
    if (y % i == 0){
      return false;
    }
  }
  return true;	
}


int get_prev_prime(int x){
	//function that computes the largest prime that is less than x
	//complete code here
  while (--x){
    if (is_prime(x)){
      return x;
    }
  }	
  return 0;	
}

int get_next_prime(int x){
	//function that computes the smallest prime that is greater than x
	//complete code here
	while (++x){
    if (is_prime(x)){
      return x;
    }
  }	
  return 0;		
}

bool is_nice_prime(int x){
	//this function takes in x and determines if it is a nice prime per the definition
	//complete code here	
  if (!is_prime(x)){
    return false;
  }
  int prev = get_prev_prime(x);
  int next = get_next_prime(x);
  return x * x > prev * next;  	
}

int main(){	
	int N;
	cin >> N;
	for (int i = 0; i < N; i = i + 1){
		int x;
		cin >> x;
		if (is_nice_prime(x)){
			cout << "True" << endl;
		}
		else{
			cout << "False" << endl;
		}
	}
		
	return 0;	
}