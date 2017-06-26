#include <bits/stdc++.h>

using namespace std;

int monthOffset(int month, int year) {
    switch(month) {
        case 2:
            if(year % 4 == 0) {
                return year % 100 == 0 && year % 400 != 0 ? 0 : 1;
            }
            return 0;
        case 4:
        case 6:
        case 9:
        case 11:
            return 2;
        default:
            return 3;
    }
}

int main() {
    int sundayCount = 0;
    // for 1900
    int curDay = 1;
    int year = 1900;
    int month = 1;
    while(month < 13) {
        curDay = (curDay + monthOffset(month,year)) % 7;
        month++;
    }

    while(year++ < 2000) {
        month = 1;
        while(month < 13) {
            curDay = (curDay + monthOffset(month,year)) % 7;
            if(curDay == 0) {
                sundayCount++;
            }
            month++;
        }
    }
    cout << "TOTAL SUNDAYS: " << sundayCount << '\n';
}
