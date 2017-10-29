#include "../headers/utils.hpp"

using namespace std;

bool notSame(int x, int base) {
    unordered_map<int, int> test;
    unordered_map<int, int> test2;
    string s = to_string(x);
    string t = to_string(base);
    for(int i=0; i < s.size(); i++) {
        test[s[i]]++;
    } 
    for(int j=0; j < t.size(); j++) {
        test2[t[j]]++;
    } 
    for(auto &j: test) {
        if(j.second != test2[j.first]) return true;
    }
    return false;
}

int main() {
    int x = 1000000 / 6;
    int ans = -1;;
    int j;
    for(int i=100001;i < x; i++) {
        for(j=2; j<=6; j++) {
            if(notSame(i, i * j)) break;
        } 
        if(j == 7) {
            ans = i;
            break;
        }
    }
    cout << "answer is: " << ans << '\n';
    int tmp = 0;
    for(int k=2; k <= 6; k++) {
       tmp = ans * k; 
       cout << "answer times " << k << "is: " << tmp << '\n';
    }
}
