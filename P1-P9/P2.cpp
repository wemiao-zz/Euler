#include "../headers/utils.hpp"

int main() {
    vector<int> fib(1000,0);
    fib[1] = 1;
    fib[2] = 1;
    int sum = 0;
    for(int i=3; i < fib.size(); i++) {
        fib[i] = fib[i-1] + fib[i-2]; 
        if (i % 3 == 0) {
            sum += fib[i];
        } 
        if(fib[i] >= 4000000) break;
    }
    cout << "sum of even fibonacci numbers below 4 million: " << sum << '\n';
}
