#include "utils.hpp"

using namespace std;

int main() {
    unordered_map<int, int> nums;
    pair<int,int> maxNum = make_pair(3,1);
    int x;
    int y;
    int cnt;

    for(int i=1000; i >= 4; i--) {
        cnt = 0;
        x = 1;
        while(cnt < i) {
            // not actually recurring
            x *= 10;
            if(i % x == 0) {
                break;
            }
            if(nums[x]) {
                if(cnt - nums[i % x] > maxNum.second) {
                    maxNum = make_pair(i, cnt - nums[i % x]);
                } 
                break;
            }        
            cnt++;
            nums[x] = cnt;
            x = x % i;
        }
        nums.clear();
        if(maxNum.second > i) {
            break;
        }
    }
    cout << maxNum.first << ", " << maxNum.second << '\n';
}
