#include "../headers/utils.hpp"

using namespace std;

/* void getNextFrac(pair<string,string> &x, int n) { */
/*     string tmp; */
/*     if (n < 1) return; */
/*     if (n == 1) { */
/*         tmp = x.second; */
/*         x.second = x.first; */
/*         x.first = add_string(x.second, tmp); */
/*     } else { */
/*         tmp = x.second; */
/*         x.second = x.first; */
/*         x.first = add_string(karatsuba("2", x.second), tmp); */
/*         getNextFrac(x, --n); */
/*     } */
/*     return; */
/* } */

void getNextFrac(pair<string,string> &x, int n, int &cnt) {
    if (n < 1) return;
    string tmp;
    tmp = x.second;
    x.second = add_string(x.first, x.second);
    x.first = add_string(x.first, karatsuba(tmp, "2"));
    if (x.first.size() > x.second.size()) cnt++;
    getNextFrac(x, --n, cnt);
    return;
}

int main() {
    string a = "1";
    string b = "1";
    int cnt = 0;
    /* for (int i=1; i <= 1000; i++) { */
    auto x = make_pair(a, b);
    getNextFrac(x, 1000, cnt);
        /* if (x.first.size() > x.second.size()) cnt++; */ 
    /* } */
    cout << x.first << ' ' << x.second << '\n';
    cout << cnt << '\n';
}
