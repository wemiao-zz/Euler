#include "../headers/utils.hpp"

using namespace std;

int main() {
    vector<int> primes = sieveEratosthenes(10000);
    vector<int> listPrimes;
    vector<int> listSquares;
    int cnt = 1;
    while(cnt * cnt <= 20000) {
        listSquares.emplace_back(cnt * cnt);
        cnt++;
    }
    
    for(int i=2;i < primes.size();i++) {
        if(primes[i]) listPrimes.emplace_back(i);
    }

    int cnt2;
    bool notFound;
    bool foundFirst = false;
    for(int i=15; i < 10000; i+=2) {
        if(primes[i]) continue;
        cnt = 0;
        notFound = true;
        while(listPrimes[cnt] < i && notFound) {
            cnt2 = 0; 
            while(((2 * listSquares[cnt2] + listPrimes[cnt])) <= i && notFound) {
                int tmp = 2 * listSquares[cnt2] + listPrimes[cnt];
                if((2 * listSquares[cnt2] + listPrimes[cnt]) == i) {
                    notFound = false;
                    break;
                }
                cnt2++;
            }
            cnt++;
        } 
        if(!notFound) {
            continue;
        } else {
            cout << i << " is a composite number not the sum of a prime plus 2 times a square" << '\n';
            foundFirst = true;
            break;
        }
        if(foundFirst) break;
    }
}
