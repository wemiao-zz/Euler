#include "../headers/utils.hpp"

using namespace std;

int main() {
    int size = 1001;
    int a=3;
    int b=4;
    int c;
    float tmp;
    while(a < size) {
        tmp = sqrt(a * a + b * b);
        if (std::floor(tmp) - tmp == 0) {
            c = tmp;
            if(a+b+c == 1000) {
                cout << "(" << a << ", " << b << ", " << c << ")" << '\n';
                c = a * b * c;
                cout << c << '\n';
                break;
            }
        } 
        b++;
        if (sqrt(a*a + b * b) > size) {
            a++;
            b = a + 1;
        }
    }
}
