#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template<typename T>
T h2(vector<T> nums){
	T sum = 0;
	for (T x : nums){
		sum += 1/x;
	}
	return 1 / (sum / nums.size());	
}


template<typename T>
T h1(vector<T> nums){
	T sum = 0;
	for (T x : nums){
		sum += pow(x, -1);
	}
	return pow(sum / nums.size(), -1);	
}

int main() {
    int N;
    cin >> N;
    vector<float> nums;
    for (int i = 0; i < N; ++i){
    	float x;
    	cin >> x;
    	nums.push_back(x);    	
    }
    cout << h1(nums) << endl;
    return 0;    
}
