#include "../headers/utils.hpp"

using namespace std;

int main() {
    long sum = 0;
    const long mask = 10000000000; // to mod against
    long cur;
    for(long i=1; i <= 1000; i++) {
        cur = i; 
        for(long j=1; j < i; j++) {
            cur = (cur * i) % mask; 
        }
        sum = (sum + cur) % mask;
    }
    cout << sum << '\n';
}
