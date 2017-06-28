#include "utils.hpp"

using namespace std;

int main() {
    vector<string> fib;
    fib.emplace_back("1");
    fib.emplace_back("1");
    int index = 2;
    while(fib[index-1].size() < 1000) {
        fib.emplace_back(add_string(fib[index-1], fib[index-2]));
        index++;
    }
    cout << "INDEX WITH 1000 DIGITS: " << index << '\n';
}
