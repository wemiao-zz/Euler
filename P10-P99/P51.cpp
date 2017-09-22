#include "../headers/utils.hpp"

using namespace std;

int tryOthers(string prime, int x, int y, int z, char exclude, int maxFamily, vector<int> &primes, vector<int> &members) {
    vector<char> tests = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(auto &i: tests) {
        if(i == exclude) continue;
        prime[x] = i;
        prime[y] = i;
        prime[z] = i;
        if(primes[stoi(prime)]) {
            members.emplace_back(i - '0');
            maxFamily++;
        }
    }
    return maxFamily;
}

int main() {
    vector<int> primes = sieveEratosthenes(1000000);
    vector<int> primesList;
    for(int i=100001; i < primes.size(); i+=2) {
        if(primes[i]) primesList.emplace_back(i);
    }
    int maxFamily = 0;
    string prime = "";
    int tmp; 
    int primeResult;
    int maxIndex1 = 0;
    int maxIndex2 = 0;
    int maxIndex3 = 0;
    vector<int> members;
    vector<int> maxMembers;
    vector<char> testers = { '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(auto&c: testers) {
        for(int x=0; x < 3; x++) {
            for(int y = x + 1; y < 4; y++) {
                for(int z = y + 1; z < 5; z++) {
                    for(auto &j: primesList) {
                        prime = to_string(j);
                        if(prime[x] == c && prime[y] == c && prime[z] == c) {
                            members.clear();
                            members.emplace_back(c - '0'); 
                            tmp = 1;
                            tmp = tryOthers(prime, x, y,z, c, tmp, primes, members);
                            if(tmp == 8) {
                                cout << "number in family: " << tmp << '\n';
                                cout << "index1: " << x << '\n';
                                cout << "index2: " << y << '\n';
                                cout << "index3: " << z << '\n';
                                cout << "prime: " << prime << '\n';
                                cout << "members: ";
                                for(auto &k: members) {
                                    cout << k << ' ';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
