#include "../headers/utils.hpp"

using namespace std;

int expThenSum(string a, int b) {
    string product = a;
    for(int i = b; i >= 0; i--) {
        product = karatsuba(product, a); 
    }
    int sum = 0;
    for(auto&j: product) {
        sum += j - '0';
    }
    return sum;
}

int main() {
    int maxSum = 0;
    for(int b=99; b > 0; b--) {
        for(int a=99; a > 0; a--) {
            maxSum = max(maxSum, expThenSum(to_string(a), b));
        }
    }
    cout << maxSum << '\n';
}
