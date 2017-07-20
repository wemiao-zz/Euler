#include "../headers/utils.hpp"

using namespace std;

bool isTriangleWord(const string &word, const set<int> &triangleNums) {
    int val = 0;
    for(auto &i: word) {
        val += i - 'A' + 1; // A equals 1
    }
    return triangleNums.find(val) != triangleNums.end();
}

int main() {
    vector<string> words = parseCSV("P42.txt");
    size_t maxLength = 0;

    for(auto &word: words) {
        maxLength = max(maxLength, word.size()); 
    }

    maxLength *= 26; // maximum possible value for longest word length, i.e. "ZZZZ"
    set<int> triangleNums;
    int cnt = 1;
    while(cnt <= maxLength) { 
        triangleNums.emplace(.5 * cnt * (cnt + 1)); 
        cnt++;
    }

    /* for(auto &i: triangleNums) { */
    /*     cout << i << '\n'; */
    /* } */

    int triangleWords = 0;
    for(auto &word: words) {
        if(isTriangleWord(word, triangleNums)) {
            /* cout << word << '\n'; */
            triangleWords++;
        }
    }
    cout << triangleWords << '\n';
}
