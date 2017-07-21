#include "../headers/utils.hpp"

using namespace std;

int main() {
    vector<int> primes = sieveEratosthenes(5000000);
    int cnt;
    bool found = false;
    int foundNum;
    int j = 0;
    for(int i=2; i < primes.size(); i++) {
        if(primes[i]) {
            cnt = 0;
        } else {
            cnt++;
            if(cnt >= 4) {
                for(j=i - 3; j <= i; j++) {
                    try {
                        if(primeFactorization(j).size() != 4) break;
                    } catch (const std::exception& e) {
                        cout << e.what() << '\n';
                    }
                } 
            }
        }
        if(j == i + 1) {
            foundNum = i-3;  
            break;
        }
    }
    cout << foundNum << '\n';
}
