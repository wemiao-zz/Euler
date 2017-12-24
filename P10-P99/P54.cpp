#include "../headers/utils.hpp"

using namespace std;

bool isWin(bitset<52> h1, bitset<52> h2) {
    int bitsSet, bitsSet2;
    for(int i=0; i < 4; i++) {
        bitsSet = 0;
        bitsSet2 = 0;
        for(int j=0; j < 13; j++) {
            if(h1.test(13*i + j)) bitsSet++;
            if(h2.test(13*i + j)) bitsSet2++;
        }

        cout << bitsSet << '\n';
        cout << bitsSet2 << '\n';
    }
    return false;
}

int parse(string n) {
    unordered_map <char,int> suit;
    suit['C'] = 0;
    suit['H'] = 13;
    suit['S'] = 26;
    suit['D'] = 39;

    unordered_map <char,int> cardNum;
    cardNum['2'] = 0;
    cardNum['3'] = 1;
    cardNum['4'] = 2;
    cardNum['5'] = 3;
    cardNum['6'] = 4;
    cardNum['7'] = 5;
    cardNum['8'] = 6;
    cardNum['9'] = 7;
    cardNum['T'] = 8;
    cardNum['J'] = 9;
    cardNum['Q'] = 10;
    cardNum['K'] = 11;
    cardNum['A'] = 12;
    return cardNum[n[0]] + suit[n[1]]; 
}

int main() {
    ifstream infile("P54.txt");
    string line;
    string n;
    int cnt;
    bitset<52> cards1;
    bitset<52> cards2;
    int wins = 0;
    while(getline(infile, line)) {
        cnt = 0;
        cards1.reset();
        cards2.reset();
        istringstream iss(line);
        while(iss >> n) {
            if(cnt < 5) {
                cards1.set(parse(n)); 
            } else {
                cards2.set(parse(n)); 
            }
            cnt++;
        }
        if(isWin(cards1, cards2)) wins++;

        break; // just test for 1 hand
    }
    cout << "Total P1 wins: " << wins << '\n';
}
