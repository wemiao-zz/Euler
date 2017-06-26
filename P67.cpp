// note this is also the answer to P67
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream infile("P67.txt");
    string line;
    int n;
    vector<vector<int>> v;
    int cnt = 0;
    vector<int> row;
    while(getline(infile, line)) {
        istringstream iss(line);
        v.emplace_back(row);
        while(iss >> n) {
            v[cnt].emplace_back(n);
        }
        cnt++;
    }

    for(int i=v.size()-2; i >= 0; i--) {
        for(int j=0; j < v[i].size(); j++) {
            v[i][j] = max(v[i+1][j], v[i+1][j+1]) + v[i][j];
        }
    }
    
    cout << v[0][0] << '\n';

    // display grid
    /* for(int i=0; i < v.size(); i++) { */
    /*     for(int j=0; j < v[i].size(); j++) { */
    /*         cout << v[i][j] << ' '; */
    /*     } */
    /*     cout << '\n'; */
    /* } */
}
