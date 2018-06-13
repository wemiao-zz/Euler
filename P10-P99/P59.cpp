#include "../headers/utils.hpp"

using namespace std;

bool testValid(int code) {
    return code == 32 || code == 33 || code == 39 || code == 40 || code == 41 || code == 44 || code == 45 || code == 46 || (code >= 48 && code <= 59) || code == 63 || (code >= 65 && code <= 90) || (code >= 97 && code <= 122);
}

bool tryCode(int x, int y, int z, vector<int> text) {
    int decrypt = 0;
    for(int i = 0; i < text.size(); i++) {
        if (i % 3 == 0) {
            decrypt = text[i] ^ x;
        } else if (i % 3 == 1) {
            decrypt = text[i] ^ y;

        } else { // i % 3 == 2
            decrypt = text[i] ^ z;

        }
        if (!testValid(decrypt)) {
            return false;
        }
    }
    return true;
}

void decryptMessage(int x, int y, int z, vector<int> text) {
    char decrypt = 0;
    for(int i = 0; i < text.size(); i++) {
        if (i % 3 == 0) {
            decrypt = (char)text[i] ^ x;
        } else if (i % 3 == 1) {
            decrypt = (char)text[i] ^ y;

        } else { // i % 3 == 2
            decrypt = (char)text[i] ^ z;
        }
        cout << decrypt; 
    }
}

void sumMessage(int x, int y, int z, vector<int> text) {
    int decrypt = 0;
    int sum = 0;
    for(int i = 0; i < text.size(); i++) {
        if (i % 3 == 0) {
            decrypt = text[i] ^ x;
        } else if (i % 3 == 1) {
            decrypt = text[i] ^ y;

        } else { // i % 3 == 2
            decrypt = text[i] ^ z;
        }
        sum += decrypt;
    }
    cout << '\n' << sum;
}

int main() {
    ifstream infile("P59.txt");
    string n;
    string line;
    vector<int> text;
    while(getline(infile, line, ',')) {
        istringstream iss(line);
        while(iss >> n) {
            text.push_back(stoi(n));
        }
    }

    for (int i=97; i <= 122; i++) {
        for (int j=97; j <= 122; j++) {
            for (int k=97; k <= 122; k++) {
                if(tryCode(i, j, k, text)) {
                    decryptMessage(i, j, k, text);
                    sumMessage(i, j, k, text);
                    break;
                }
            }
        }
    }
}
