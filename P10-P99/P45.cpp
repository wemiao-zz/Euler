#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<unsigned long long> total(2000000000ull, 0);
    unsigned long long tmp;
    for(unsigned long long i=1; i < 200000000; i++) {
        tmp = (i * (i + 1)) / 2; // triangular 
        if(tmp > 2000000000) break;
        total[tmp]++;
        tmp = (i * (3*i - 1)) / 2; // pentagonal
        if(tmp < 2000000000) {
            total[tmp]++;
            tmp = (i * (2*i - 1)); // hexagonal
            if(tmp < 2000000000) {
                total[tmp]++;
            }
        }
    }
    for(long i=0; i < total.size(); i++) {
        if(total[i] == 3) {
            cout << i << '\n';
        }
    }
}
