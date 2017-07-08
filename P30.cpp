#include "utils.hpp"

using namespace std;

bool isFifthPower(int x) {
    int sum = 0;
    int cur = x;
    int tmp;
    while(cur != 0) {
        sum += pow(cur % 10, 5);
        cur /= 10;
    }
    return sum == x;
}

int main() {
    int totalSum = 0;
    int x = 11;
    for(; x < 1000000; x++) {
        if(isFifthPower(x)) {
            cout << "X: " << x << '\n';
            totalSum += x;
        }
    }
    cout << "total sum of fifth powers: " << totalSum << '\n';
}
