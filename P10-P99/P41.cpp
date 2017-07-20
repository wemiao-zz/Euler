#include "../headers/utils.hpp"

using namespace std;

bool isPandigitalPrime(int i, const vector<int> &primes) {
    vector<int> digits;
    if(!primes[i]) return false;
    while(i > 0) {
        if(i % 10 == 0) return false;
        digits.emplace_back(i % 10);
        i /= 10;
    }
    sort(digits.begin(), digits.end());
    int count = 1;
    for(auto &j: digits) {
        if(j != count) return false;
        count++;
    }
    return true;
}

int main() {
    vector<int> primes = sieveEratosthenes(10000000);
    int maxPandigitalPrime = 2;
    for(int i=0; i < primes.size(); i++) {
        if(isPandigitalPrime(i, primes)) {
            maxPandigitalPrime = max(maxPandigitalPrime, i);
        }
    }
    cout << maxPandigitalPrime << '\n';
}
