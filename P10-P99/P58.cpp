#include "../headers/utils.hpp"

using namespace std;

int main() {
    vector<int> sieve = sieveEratosthenes(1000000000);
    int tot = 1;
    int upperRight = 3;
    int upperLeft = 5;
    int bottomLeft = 7;
    int numPrimes = 0;
    int sep1 = 2;
    int sep2 = 4;
    int sep3 = 6;
    int len = 1;
    do {
        len += 2;
        if (sieve[upperRight]) {
            numPrimes++;
        }
        if (sieve[upperLeft]) {
            numPrimes++;
        }
        if (sieve[bottomLeft]) {
            numPrimes++;
        }
        sep1 += 8;
        sep2 += 8;
        sep3 += 8;
        upperRight += sep1;
        upperLeft += sep2;
        bottomLeft += sep3;
        tot += 4;
    } while (bottomLeft < 999999999 && (numPrimes / (float)tot) >= .1);
    cout << numPrimes << '\n';
    cout << tot << '\n';
    cout << len << '\n';
}
