#include "../headers/utils.hpp"

using namespace std;

int main() {
    long long factor = 600851475143;
    vector<int> primes = sieveEratosthenes(sqrt(factor));
    vector<int> primesList;
    primesList.emplace_back(2);
    for(int i=3; i < primes.size(); i+=2) {
        if(primes[i]) primesList.emplace_back(i); 
    }

    unordered_map<int,int> factors;
    for(auto &i: primesList) {
        while(factor % i == 0 && factor != 1) {
            factors[i]++;
            factor /= i;
        }
        if (factor == 1) break;
    }
    if(factor != 1) factors[factor]++;
    cout << "PRIME FACTORS ARE:\n";
    for(auto &i: factors) {
        cout << i.first << ", " << i.second << " times" << '\n'; 
    }
}
