#include "../headers/utils.hpp"

using namespace std;

bool isPalindrome(int x) {
    string s = to_string(x);
    for(int i=0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size()-1-i]) return false; 
    }
    return true;
}

bool isPalindrome(vector<int> x) {
    for(int i=0; i < x.size() / 2; i++) {
        if(x[i] != x[x.size()-1-i]) return false; 
    }
    return true;
}

vector<int> decToBinary(int x) {
    vector<int> out;
    while(x > 0) {
        out.emplace_back(x % 2 == 1 ? 1 : 0); x /= 2;
    }
    return out;
}

int main() {
    int sum = 0;
    for(int i=1; i < 1000000; i++) {
        if(isPalindrome(i) && isPalindrome(decToBinary(i))) {
            sum += i;
        }
    }
    cout << "sum of palindromes in decimal and binary less than 1000000: " << sum << '\n';
}
