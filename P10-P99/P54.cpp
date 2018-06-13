#include "../headers/utils.hpp"

using namespace std;

bool checkFlush(vector<int> h) {
    int suit = h[0] / 13;
    for (int i=1; i < h.size(); i++) {
        if (h[i] / 13 != suit) return false;
    }
    return true;
}

bool checkStraight(vector<int> h) {
    unordered_map <int,int> nums;
    int key;
    for(int i=0; i < h.size(); i++) {
        key = h[i] % 13;
        nums[key]++;
    }

    int minNum, maxNum;
    for(auto&i: nums) {
        if(i.second > 1) return false;    
        minNum = min(minNum, i.first);
        maxNum = max(maxNum, i.first);
    }
    return (maxNum - minNum) == 4;
}

bool checkStraightFlush(vector<int> h) {
    return checkFlush(h) && checkStraight(h);
}

bool checkRoyalFlush(vector<int> h) {
    if (!checkStraightFlush(h)) return false;
    for (int i=0; i < h.size(); i++) {
        if (h[i] % 13 < 8) return false;
    }
    return true;
}



bool checkNKind(vector<int> h, int n) {
    unordered_map <int,int> nums;
    int key;
    for(int i=0; i < h.size(); i++) {
        key = h[i] % 13;
        nums[key]++;
    }

    for(auto&i: nums) {
        if(i.second == n) return true;
    }
    return false;
}

bool checkFullHouse(vector<int> h) {
    unordered_map<int,int> nums;
    int key;
    for(int i=0; i < h.size(); i++) {
        key = h[i] % 13;
        nums[key]++;
    }

    bool checkTwo = false;
    bool checkThree = false;
    for(auto&j: nums) {
        if (j.second == 3) {
            checkThree = true; 
        } else if (j.second == 2) {
            checkTwo = true;
        }
    }
    return checkThree && checkTwo;
}

bool checkTwoPair(vector<int> h) {
    unordered_map<int,int> nums;
    int key;
    for(int i=0; i < h.size(); i++) {
        key = h[i] % 13;
        nums[key]++;
    }

    int countPairs = 0;
    for(auto&j: nums) {
        if(j.second == 2) countPairs++;
    }
    return countPairs == 2;
}

bool highCard(vector<int> h1, vector<int> h2) {
    int max1 = -1;
    int max2 = -1;
    for(int i=0; i < h1.size(); i++) {
        max1 = max(max1, h1[i] % 13);
        max2 = max(max2, h2[i] % 13);
    }
    return max1 > max2;
}

bool checkNPairHighCard(vector<int> h1, vector<int> h2, int n) {
    unordered_map <int,int> num1;
    unordered_map <int,int> num2;

    int key1, key2;
    for(int i=0; i < h1.size(); i++) {
        key1 = h1[i] % 13; 
        key2 = h2[i] % 13; 
        num1[key1]++;
        num2[key2]++;
    }
    
    int max1 = -1;
    int max2 = -1;
    for(auto&j: num1) {
        if (j.second == n) {
            max1 = max(max1, j.first);
        }
    }
    for(auto&k: num2) {
        if (k.second == n) {
            max2 = max(max2, k.first);
        }
    }
    return max1 > max2;
}

bool checkFullHighCard(vector<int> h1, vector<int> h2) {
    unordered_map <int,int> num1;
    unordered_map <int,int> num2;

    int key1, key2;
    for(int i=0; i < h1.size(); i++) {
        key1 = h1[i] % 13; 
        key2 = h2[i] % 13; 
        num1[key1]++;
        num2[key2]++;
    }
    
    // check 3 of a kind pair first
    for(auto &i: num1) {
        if(i.second == 3) {
            for(auto &j: num2) {
                if (j.second == 3) {
                    // in case 3 of a kind is a tie, need to check two of a kind;
                    if (i.first == j.first) {
                        for(auto &k: num1) {
                            if (k.second == 2) {
                                for(auto &m: num2) {
                                    if (m.second == 2) {
                                        // according to assumption, there are no draws
                                        return k.first > m.first;
                                    }
                                }
                            }
                        } 
                    } else {
                        return i.first > j.first;
                    }
                }
            }
        }
    }
    return false; // should never get here in theory 
}

bool isWin(vector<int> h1, vector<int> h2) {
    // check royal flush
    if (checkRoyalFlush(h1)) {
        cout << "RFLUSH1";
        return true;
    } else if (checkRoyalFlush(h2)) {
        cout << "RFLUSH2";
        return false;
    }

    // check straight flush
    if (checkStraightFlush(h1)) {
        /* cout << "SFLUSH1"; */
        // need to check for ties
        if (checkStraightFlush(h2)) {
            /* cout << "SFLUSHTIE"; */
            return highCard(h1, h2);
        }
        return true;
    } else if (checkStraightFlush(h2)) {
        /* cout << "SFLUSH2"; */
        return false;
    }

    // check four of a kind 
    if (checkNKind(h1, 4)) {
        /* cout << "4K1"; */
        // need to check for ties
        if (checkNKind(h2, 4)) {
            /* cout << "4K1,2"; */
            return checkNPairHighCard(h1, h2, 4);
        }
        return true;
    } else if (checkNKind(h2, 4)) {
        /* cout << "4K2"; */
        return false;
    }

    // check full house
    if (checkFullHouse(h1)) {
        /* cout << "FH1"; */
        if (checkFullHouse(h2)) {
            /* cout << "FH1,2"; */
            return checkFullHighCard(h1, h2);
        }
    } else if (checkFullHouse(h2)) {
        /* cout << "FH2"; */
        return false;
    }

    // check flush
    if (checkFlush(h1)) {
        /* cout << "FLUSH1"; */
        // need to check for ties
        if (checkFlush(h2)) {
            /* cout << "FLUSH1, 2"; */
            return highCard(h1, h2);
        }
        return true;
    } else if (checkFlush(h2)) {
        /* cout << "FLUSH2"; */
        return false;
    }

    // check straight
    if (checkStraight(h1)) {
        /* cout << "STRAIGHT1"; */
        // need to check for ties
        if (checkStraight(h2)) {
            /* cout << "STRAIGHT1,2"; */
            return highCard(h1, h2);
        }
        return true;
    } else if (checkStraight(h2)) {
        /* cout << "STRAIGHT2"; */
        return false;
    }

    // check three of a kind 
    if (checkNKind(h1, 3)) {
        /* cout << "3KIND1" << '\n'; */
        // need to check for ties
        if (checkNKind(h2, 3)) {
            /* cout << "3KIND1,2" << '\n'; */
            return checkNPairHighCard(h1, h2, 3);
        }
        return true;
    } else if (checkNKind(h2, 3)) {
        /* cout << "3KIND2" << '\n'; */
        return false;
    }

    // check two pair
    if (checkTwoPair(h1)) {
        /* cout << "TWOPAIR1"; */
        if (checkTwoPair(h2)) {
            /* cout << "TWOPAIR1,2"; */
            return checkNPairHighCard(h1, h2, 2);
        }
        return true;
    } else if (checkTwoPair(h2)) {
        /* cout << "TWOPAIR2"; */
        return false;
    }

    // check one pair
    if (checkNKind(h1, 2)) {
        /* cout << "PAIR1"; */
        if (checkNKind(h2, 2)) {
            /* cout << "PAIR1, 2"; */
            return checkNPairHighCard(h1, h2, 2);
        }
        return true;
    } else if (checkNKind(h2, 2)) {
        /* cout << "PAIR2"; */
        return false;
    }

    // check high card
    /* cout << "HCARD 1,2"; */
    return highCard(h1, h2);
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
    vector<int> cards1;
    vector<int> cards2;
    int cnt;
    int wins = 0;
    int totalCount = 0;
    while(getline(infile, line)) {
        cnt = 0;
        cards1.clear();
        cards2.clear();
        istringstream iss(line);
        while(iss >> n) {
            /* cout << n << ' '; */
            if(cnt < 5) {
                cards1.push_back(parse(n)); 
            } else {
                cards2.push_back(parse(n)); 
            }
            cnt++;
        }
        /* cout << '\n'; */
        if(isWin(cards1, cards2)) {
            /* cout << '\n' << "P1 wins" << '\n'; */
            wins++;
        }

        totalCount++;
        /* cout << '\n'; */
        /* if (totalCount > 300) break; // test first 20 hands */
    }
    cout << "Total P1 wins: " << wins << '\n';
}
