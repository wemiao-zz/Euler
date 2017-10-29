#include "../headers/utils.hpp"

using namespace std;

int main() {
    vector<vector<unsigned long>> pascal;
    vector<unsigned long> tmp = vector<unsigned long>(2,1);
    pascal.emplace_back(tmp);
    int cnt = 0;
    for(int i=0; i < 99; i++) {
        tmp = vector<unsigned long>(i+3,0);
        tmp[0] = 1; // edges of pascal's triangle
        tmp[tmp.size() - 1] = 1; // edges of pascal's triangle
        for(int j=1; j < tmp.size()-1; j++) {
           tmp[j] = pascal[i][j-1] + pascal[i][j]; 
           if(tmp[j] > 1000000) cnt++;
        }
        pascal.emplace_back(tmp);

    }
    cout << "number over 1 million: " << cnt << '\n';
    /* for(auto &i: pascal) { */
    /*     cout << cnt << ": "; */
    /*     cnt++; */
    /*     for(auto &j: i) { */
    /*         cout << j << ' '; */
    /*     } */
    /*     cout << '\n'; */
    /* } */
}
