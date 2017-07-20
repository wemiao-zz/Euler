#include "../headers/utils.hpp"

using namespace std;

int main() {
    auto factors = primeFactorization(3594);
    for(auto &i: factors) {
        cout << i.first << ", " << i.second << '\n';
    }
}
