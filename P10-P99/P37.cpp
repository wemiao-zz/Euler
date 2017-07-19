#include "../headers/utils.hpp"

using namespace std;

bool truncatable(int x, const vector<int> &primes) {
    int right = x;
    while(right > 0) {
        if(!primes[right]) return false;
        right /= 10; // check right truncatable
    }
    string left = to_string(x);
    while(left.size() > 0) {
        if(!primes[stoi(left)]) return false;
        left.erase(0,1);
    }
    return true;
}

int main() {
    vector<int> primes =  sieveEratosthenes(1000000);

    int sumTruncatable = 0;
    for(int i=11;i < primes.size(); i++) {
        if(primes[i] && truncatable(i, primes)) {
            sumTruncatable += i;
        }
    }
    cout << sumTruncatable << '\n';
}
