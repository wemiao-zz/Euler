#include "../headers/utils.hpp"

using namespace std;

int main() {
    unordered_map<int,int> perims = pythagorean_triplets(1000);
    for(auto &i: perims) {
        cout << i.first << ", " << i.second << '\n';
    }
}
