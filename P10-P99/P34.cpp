#include "../headers/utils.hpp"

using namespace std;

vector<int> facVec {
    stoi(factorial(0)),    
    stoi(factorial(1)),    
    stoi(factorial(2)),    
    stoi(factorial(3)),    
    stoi(factorial(4)),    
    stoi(factorial(5)),    
    stoi(factorial(6)),    
    stoi(factorial(7)),    
    stoi(factorial(8)),    
    stoi(factorial(9))   
};

bool isCuriousNum(int a) {
    int x = a;
    int tot = 0;
    while(x > 0) {
        tot += facVec[x % 10];
        x /= 10;
    }
    return tot == a;
}

int main() {
    int maxVal = stoi(factorial(9)) * 7;

    for(int i = 11; i < maxVal; i++) {
        if(isCuriousNum(i)) {
            cout << i << '\n';
        }
    }
}
