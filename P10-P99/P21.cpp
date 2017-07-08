#include <bits/stdc++.h>

using namespace std;

int sumOfFactors(int n) {
    int tmp = sqrt(n); 
    int sum = 1;
    for(int i=2; i <= tmp; i++) {
        int x = n % i;
        if(n % i == 0) {
            if(i * i == n) {
                sum += tmp;
            }
            else {
                sum += i;
                sum += n / i;
            }
        }
    }
    return sum;
}


int main() {
    vector<int> sums(10000);
    int totalAmicable = 0;
    int tmp;
    for(int i=1; i < 10000; i++) {
        sums[i] = sumOfFactors(i);
        //cout << "I: " << i << ", SUM: " << sums[i] << '\n';
        if (sums[i] < 10000 && i != sums[i] && i == sums[sums[i]]) {
            //cout << i << '\n';
            //cout << sums[sums[i]] << '\n';
            totalAmicable += i + sums[i];
        }
    }
    cout << "TOTAL: " << totalAmicable << '\n';
}
