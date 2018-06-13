#include "../headers/utils.hpp"

using namespace std;
using namespace std::chrono;

int combine(int a, int b) {
    unsigned long long shift = 10;
    while (shift <= b) {
        shift *= 10;
    }
    return a * shift + b;
} 

bool checkConcatPrime(const vector<int> &primes, const vector<int> &pairCheck) {
    return primes[combine(pairCheck[0], pairCheck[1])] && primes[combine(pairCheck[1], pairCheck[0])];
}

void generateCombinations(int r, int cnt, int idx, const vector<int> &list, vector<vector<int>>& sol, vector<int> curList) {
    if (cnt >= r) {
        sol.emplace_back(curList); 
        return;
    } else {
        for(int i=idx; i < list.size(); i++) {
            curList.emplace_back(list[i]);
            generateCombinations(r, ++cnt, ++idx, list, sol, curList); 
            curList.pop_back();
            cnt--;
        }
    }
}

int main() {
    vector<int> primes = sieveEratosthenes(100000000);
    vector<int> primesList;
    for(int i=3;i < 10000; i+=2) {
        if (primes[i]) primesList.emplace_back(i);
    }
    vector<int> curList;
    vector<vector<int>> sol;

    vector<vector<int>> primePairsList;
    generateCombinations(2, 0, 0, primesList, sol, curList);

    cout << "FINISHED PROCESSING" << '\n';
    for(int i=0; i < sol.size(); i++) {
        if (checkConcatPrime(primes, sol[i])) {
            primePairsList.emplace_back(sol[i]);
        }
    }
        
}
