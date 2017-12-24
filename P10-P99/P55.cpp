#include "../headers/utils.hpp"

using namespace std;

bool isPalindrome(string a) {
    string b = a;
    reverse(b.begin(), b.end());
    return a == b;
}

int main() {
    int count;
    int nums = 0;
    string sum, cur, revcur;
    for(int i=9999;i > 0; i--) {
        count = 0;
        cur = to_string(i);
        while(count < 51) {
            revcur = cur;
            reverse(revcur.begin(), revcur.end());
            sum = add_string(cur, revcur);
            cur = sum;
            count++;
            if(isPalindrome(cur)) break;
        } 
        if (count == 51) {
            nums++;
        }
    }
    cout << nums << '\n';
}
