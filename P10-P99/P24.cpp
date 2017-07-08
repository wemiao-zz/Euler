#include "../headers/utils.hpp"

using namespace std;

int main() {
    string a = "0123456789";
    int cnt = 0;
    std::sort(a.begin(), a.end());
    while(++cnt < 1000000) {
        next_permutation(a.begin(),a.end());
    }
    cout << a << '\n';
}
