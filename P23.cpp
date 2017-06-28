#include "utils.hpp"

using namespace std;

int main() {
    vector<int> abundantNums(28123,0);

    int nonAbundantSumTotal = 0;

    bool notAbundantSum;
    for(int i=1; i < 28124; i++) {
        notAbundantSum = true;
        if(isAbundant(i)) {
            abundantNums[i] = 1;
        }
        for(int j = 12; j <= i / 2; j++) {
            if(abundantNums[j] && abundantNums[i-j]) {
                //cout << "J: " << j << '\n';
                //cout << "I-J: " << i - j << '\n';
                notAbundantSum = false;
                break;
            }
        }
        if(notAbundantSum) nonAbundantSumTotal += i;
    }
    cout << nonAbundantSumTotal << '\n';
}
