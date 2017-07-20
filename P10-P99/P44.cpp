#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> pentagonal(50000000, 0);
    vector<int> listPentagonal;
    int tmp;
    for(int i=1; i < 10000; i++) {
        tmp = (i * (3*i - 1)) / 2;
        if(tmp >= 50000000) break;
        pentagonal[tmp] = 1;
        if(tmp < 10000000) {
            listPentagonal.emplace_back(tmp);
        }
    }

    int minDiff = INT_MAX;
    for(int i=0; i < listPentagonal.size() - 1; i++) {
        for(int j=i + 1; j < listPentagonal.size(); j++) {
            if(pentagonal[listPentagonal[i]+listPentagonal[j]] && pentagonal[listPentagonal[j]-listPentagonal[i]]) {
                minDiff = min(minDiff, listPentagonal[j] - listPentagonal[i]);
            }
        }
    }
    cout << minDiff << '\n';
}
