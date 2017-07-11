#include "../headers/utils.hpp"

using namespace std;

void addDigits(int x, set<int> &digits) {
    while(x != 0) {
        if (x % 10 != 0) {
            digits.emplace(x % 10);
        }
        x /= 10;
    }
}

bool isPandigital(int i, int j, int k) {
    if((to_string(i).size() + to_string(j).size() + to_string(k).size()) > 9) {
        return false;
    }
    set<int> digits;
    addDigits(i, digits);
    addDigits(j, digits);
    addDigits(k, digits);
    if(digits.size() == 9) {
        cout << i << ", " << j << ", " << k << '\n';
    }
    return digits.size() == 9;
}

int main() {
    int product;
    set<int> products;
    for(int i=1; i < 100; i++) {
        for(int j=100; j < 100000; j++) {
            product = i * j;
            if(isPandigital(i,j,product)) {
                products.emplace(product);
            }
        }
    }

    //for(int i=1; i < 10; i++) {
    //    for(int j=1000; j < 10000; j++) {
    //        product = i * j;
    //        if(isPandigital(i,j,product)) {
    //            products.emplace(product);
    //        }
    //    }
    //}

    int sumProducts = 0;
    for(auto &k: products) {
        sumProducts += k;
    }

    cout << sumProducts << '\n';

    return 0;
}
