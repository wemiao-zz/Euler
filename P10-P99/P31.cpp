#include "../headers/utils.hpp"

using namespace std;

int computeCurrentTotal(vector<int>& nums, vector<int> &counts) {
    int total = 0;
    for(int i=0; i < 8; i++) {
        total += nums[i] * counts[i];
    }
    return total;
}

int main() {
    // very brute force, TODO make a dynamic programming solution
    int total = 0;
    for(int a=0; a <= 1; a++) {
        for(int b=0; b <= 2; b++) {
            for(int c=0; c <= 4; c++) {
                for(int d=0; d <= 10; d++) {
                    for(int e=0; e <= 20; e++) {
                        for(int f=0; f <= 40; f++) {
                            for(int g=0; g <= 100; g++) {
                                for(int h=0; h <= 200; h++) {
                                    if(a * 200 + b * 100 + c * 50 + d * 20 + e * 10 + f * 5 + g * 2 + h == 200) total++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << total << '\n';
}
