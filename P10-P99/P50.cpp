#include "../headers/utils.hpp"

using namespace std;

int main() {
    vector<int> primes = sieveEratosthenes(1000000);
    vector<int> primesList;
    primesList.emplace_back(2);
    for(int i=3; i < primes.size(); i++) {
        if(primes[i]) primesList.emplace_back(i);
    }
    int sum = 0;
    int cnt;
    for(int i=0; i < primesList.size(); i++) {
        if(sum + primesList[i] > 1000000) {
            cnt = i;
            break;
        }
        sum += primesList[i];
    }

    cout << cnt << '\n';
    while(cnt > 1) {
        //if(primes[sum-2] != 0) {
        //    cnt--;
        //    sum-=2;
        //    break;
        //}
        if(primes[sum] != 0) break;
        //sum -= primesList[--cnt];
        //primesList.pop_back();
        sum -= primesList[0];
        cnt--;
        primesList.erase(primesList.begin());

    }
    cout << cnt << '\n';
    cout << sum << '\n';
}
