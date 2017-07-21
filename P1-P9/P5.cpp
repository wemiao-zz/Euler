#include "../headers/utils.hpp"

using namespace std;

int main() {
    unordered_map<int,int> set = primeFactorization(2);
    unordered_map<int,int> next;
    for(int i=3; i <= 20; i++) {
        next = primeFactorization(i);
        for(auto &k: next) {
            if(set.find(k.first) != set.end()) {
                set[k.first] = max(k.second, set[k.first]); 
            } else {
                set[k.first] = k.second;
            }
        }
    }
    int product = 1;
    for(auto &i: set) {
        product *= pow(i.first, i.second);
        /* cout << i.first << ", " << i.second << '\n'; */
    }
    cout << "first number divisible by 1 to 20 inclusive is : " << product << '\n';
}
