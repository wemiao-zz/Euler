#include "utils.hpp"

using namespace std;

int main() {
    vector<string> names = parseCSV("P22.txt");
    sort(names.begin(), names.end());
    string sum = "0";
    int tmp;
    for(int i=0; i < names.size(); i++) {
        tmp = 0;
        for(int j=0; j < names[i].size(); j++) {
            tmp += names[i][j] - 'A' + 1;
        }
        sum = add_string(sum,karatsuba(to_string(tmp), to_string(i+1)));
    }
    cout << sum << '\n';
}
