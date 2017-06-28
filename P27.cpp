#include "utils.hpp"

using namespace std;

int main() {
    vector<int> primes = sieveEratosthenes(1000000);

    int b = 3;
    int n;
    int a;
    int maxPairProduct;
    pair<int,int> maxAB;
    int maxN = 0;
    int tmp;
    while(b < 1000) {
        a = -1000;
        while(a++ < 1000) {
            n = 0;
            tmp = n * n + (a * n) + b;
            while(tmp > 0 && primes[tmp] != 0) {
                n++;
                tmp = n * n + (a * n) + b;
            }
            if(n > maxN) {
                maxPairProduct = a * b;
                maxN = n;
                maxAB = make_pair(a,b);
            }
        } 

        do {
            b+= 2; 
        } while(primes[b] == 0);
    } 
    cout << "PAIR PRODUCT: " << maxPairProduct << '\n';
    cout << "(a, b): (" << maxAB.first << ", " << maxAB.second << ')' << '\n';
    cout << "prime sequence length: " << maxN << '\n';
}
