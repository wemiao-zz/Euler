#include "../headers/utils.hpp"

using namespace std;

int main() {
    int i = 1;
    string s = "";
    while(s.size() <= 1000000) {
        s += to_string(i);
        i++;
    }
    int prod = (s[0] - '0') *
        (s[9] - '0') *
        (s[99] - '0') *
        (s[999] - '0') *
        (s[9999] - '0') *
        (s[99999] - '0') *
        (s[999999] - '0');
    cout << prod << '\n';
}
