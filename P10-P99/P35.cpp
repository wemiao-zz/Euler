#include "../headers/utils.hpp"

using namespace std;

int countDigits(int i) {
    int digits = 0;
    while(i > 0) {
        digits++;
        i /= 10;
    }
    return digits;
}

int rotateNumber(int i) {
    return (i % 10) * pow(10, countDigits(i) - 1) + i / 10;
}

int main() {
    vector<int> primes = sieveEratosthenes(1000000);
    vector<int> circular;
    bool rotated;
    int x;
    for(int i=2; i < primes.size(); i++) {
        if(primes[i] == 1) {
            x = rotateNumber(i);
            rotated = true;
            while(x != i) {
                if(primes[x] == 0) {
                    rotated = false;
                    break;
                } 
                x = rotateNumber(x);
            }
            if(rotated) circular.emplace_back(i);
        }
    }
    cout << "total number of circular primes: " << circular.size() << '\n';
}
