#include "../headers/utils.hpp"

using namespace std;

int main() {
    vector<int> primes = sieveEratosthenes(1000000);
    int cnt = 1;
    for(int i=3; i < primes.size(); i++) {
        if(primes[i]) {
            cnt++;
            if(cnt == 10001) {
                cout << i << '\n';
                break;
            }
        }
    }
}
