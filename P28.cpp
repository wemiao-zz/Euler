#include "utils.hpp"

using namespace std;

int main() {
    int diag = 3;
    int total = 0;
    int cur = 6;
    int incr = 13;
    int offset = 8;

    while(diag <= 1001) {
        total += cur;
        cur+=incr;
        incr+= offset; 
        diag += 2;
    }
    total *= 4;
    total++;
    cout << total << '\n';
}
