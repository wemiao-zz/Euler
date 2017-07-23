#include "../headers/utils.hpp"

using namespace std;

int main() {
    vector<int> primes = sieveEratosthenes(10000);

    string cur;
    vector<int> listPrimes;
    vector<pair<int,int>> gapSizes;
    unordered_map<int,int> gapCount; 
    for(int i=1001; i < primes.size(); i++) {
        cur = to_string(i);
        do {
            if(primes[stoi(cur)]) {
                listPrimes.emplace_back(stoi(cur));
            }
        } while (next_permutation(cur.begin(), cur.end()));
        if(listPrimes.size() > 2) {
            for(int i=2; i < listPrimes.size(); i++) {
                if(listPrimes[i] - listPrimes[i-1] == listPrimes[i-1] - listPrimes[i-2]) {
                    cout << listPrimes[i] << ' ' << listPrimes[i-1] << ' ' << listPrimes[i-2] << '\n';
                }
            }
        }
        listPrimes.clear();
    }
}
