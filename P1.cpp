#include "utils.hpp"

using namespace std;

int main() {
  int sum = 0;
  for(int i=3; i < 1000; i++) {
    if( i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  cout << "total sum of all numbers below 1000 which are a multiple of 3 or 5: " << sum << '\n';
}
