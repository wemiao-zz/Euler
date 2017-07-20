#include <bits/stdc++.h>

using namespace std;

bool isInteresting(string s) {
    return stoi(s.substr(1,3)) % 2 == 0 &&
        stoi(s.substr(2,3)) % 3 == 0 &&
        stoi(s.substr(3,3)) % 5 == 0 &&
        stoi(s.substr(4,3)) % 7 == 0 &&
        stoi(s.substr(5,3)) % 11 == 0 &&
        stoi(s.substr(6,3)) % 13 == 0 &&
        stoi(s.substr(7,3)) % 17 == 0;
}


int main() {
    string s = "0123456789";
    long long sum = 0;
    do {
        if(isInteresting(s)) sum += stoll(s); 
    } while(std::next_permutation(s.begin(), s.end()));   
    cout << sum << '\n';
}
