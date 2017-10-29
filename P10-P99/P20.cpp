#include "../headers/utils.hpp"

using namespace std;

int main() {
    string s = factorial(100);
    int res = 0;
    for(auto &i: s) {
        res += (i - '0');
    }
    cout << res << '\n';
}
