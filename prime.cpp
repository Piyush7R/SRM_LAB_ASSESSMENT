#include <iostream>
#include <cmath>
using namespace std;

int checkPrime(int num){
    if(num < 2){
        return 0;
    }
    for(int i=2; i<=int(sqrt(num)); i++){
        if(num % i == 0){
            return 0;
            break;
        }
    }
    return 1;
}

int main() {
    int num;
    cin >> num;
    
    int res = checkPrime(num);
    (res == 1) ? cout << "Prime" : cout << "Not Prime";

    return 0;
}
