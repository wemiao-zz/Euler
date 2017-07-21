#include "../headers/utils.hpp"

using namespace std;

int main() {
    int maxProduct = 0;
    int product;
    for(int i=999; i > 100; i--) {
        for(int j=999; j > 100; j--) {
            product = i * j;
            if(isPalindrome(product)) {
                maxProduct = max(maxProduct, product);
            } 
            if (maxProduct > product) break;
        }
    }
    cout << maxProduct << '\n';
}
