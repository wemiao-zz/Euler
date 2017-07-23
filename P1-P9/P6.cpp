#include "../headers/utils.hpp"

using namespace std;

int main() {
    long x = pow(((100 * 101) / 2),2);
    long sum = 1;
    for(int i=2; i <= 100; i++) {
        sum += i * i;
    }
    x -= sum;
    cout << x << '\n';
}
