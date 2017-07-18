#include "../headers/utils.hpp"

using namespace std;

bool isCurious(int x, int y) {
    bool curious = false;
    double res = x / (double)y;
    int a,b,c,d;
    a = x / 10;
    b = x % 10;
    c = y / 10;
    d = y % 10;
    if(a == c && a != 0) {
        curious |= (double)b / d == res;
    }
    if(a == d && a != 0) {
        curious |= (double)b / c == res;
    }
    if(b == c && b != 0) {
        curious |= (double)a / d == res;
    }
    if(b == d && b != 0) {
        curious |= (double)a / c == res;
    }
    return curious;
}

int main() {
    vector<pair<int,int>> curious;
    for(int i=11; i < 100; i++) {
        for(int j=i+1; j < 100; j++) {
            if(isCurious(i,j) && (double)i / j < 1) {
                curious.emplace_back(i, j); 
            }
        }
    }
    int prodA = 1;
    int prodB = 1;
    for(auto &k: curious) {
        cout << k.first << ", " << k.second << '\n';
        prodA *= k.first;
        prodB *= k.second; 
    }
    auto x = lcf(prodA, prodB);
        cout << x.first << ", " << x.second << '\n';
}
