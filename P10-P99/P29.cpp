#include "../headers/utils.hpp"

using namespace std;

int main() {
    set<string> uniques;
    for(int a=2; a <= 100; a++) {
        for(int b=2; b <= 100; b++) {
            uniques.emplace(exponentStr(to_string(a), to_string(b)));
        }
    }
    cout << uniques.size() << '\n';
}
