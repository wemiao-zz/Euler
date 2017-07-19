#include "../headers/utils.hpp"

using namespace std;

bool isPandigital(string s) {
    set<char> count;
    while(s.size() > 0) {
        if(s[0] != '0') {
            count.emplace(s[0]);
        }
        s.erase(0,1);
    }
    return count.size() == 9;
}

int main() {
    string s;
    for(int i=9000; i < 10000; i++) {
        s+= to_string(i);
        s+= to_string(i * 2);
        if(isPandigital(s)) {
            cout << s << '\n';
        }
        s = "";
    }
}
