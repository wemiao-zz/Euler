// note this is also the answer to P67
#include "../headers/utils.hpp" 

using namespace std;

int main() {
    long sum = 2;
    vector<int> primes = sieveEratosthenes(2000000);
    for(int i=3; i < primes.size(); i+=2) {
        if(primes[i]) sum += i;
    }
    cout << sum << '\n';
}
