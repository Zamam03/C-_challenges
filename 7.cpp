#include <iostream>
#include <string>

using namespace std;

int main() {
    int product = 1;
    int counter = 1;
    int N;
    cin >> N;
    while (counter <= N){
        product = product * counter;
        counter = counter + 1;
    }
    cout << product << endl;
    return 0;
}
