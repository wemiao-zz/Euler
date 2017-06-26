#include <bits/stdc++.h>

using namespace std;

int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();

    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1; // If len1 >= len2
}

std::string trimLeadingZeroes(std::string s) {
    while(s.length() > 1 && s[0] == '0') {
        s.erase(0,1);
    }
    return s;
}

std::string add_zeroes(std::string s, int n) {
    while(n--) {
        s += '0';
    }
    return s;
}

std::string add_string(std::string a, std::string b) {
    std::string out = "";
    bool carry = false;
    int result;
    int x = a.length();
    int y = b.length();
    while (x > 0 || y > 0) {
        result = 0;
        if(carry) {
            result++;
            carry = false;
        }
        if(x-- > 0) {
            result += a[x] - '0';
        }
        if(y-- > 0) {
            result += b[y] - '0';
        }
        if (result > 9) carry = true;
        out += std::to_string(result % 10);
    }
    
    if(carry) out += '1';

    // did the calculation in reverse
    std::reverse(out.begin(), out.end()); 

    return out;
}

std::string subtract2(std::string a, std::string b) {
    std::string out = "";
    bool reduce = false;
    int top;
    int bot;
    int x = a.length();
    int y = b.length();
    while (x-- > 0) {
        top = (a[x] - '0');
        if (reduce) top -= 1;
        reduce = false;
        bot = y-- > 0 ? b[y] - '0' : 0;
        if (bot > top) {
            reduce = true;
            top += 10;
        }
            out += std::to_string(top - bot);
    }

    // did the calculation in reverse
    std::reverse(out.begin(), out.end()); 

    return out;
}

std::string subtract_string(std::string a, std::string b, std::string c) {
    return (trimLeadingZeroes(subtract2(subtract2(a,b), c)));
}

// A utility function to multiply single bits of strings a and b
std::string multiplyiSingleBit(string a, string b) {  
    return to_string((a[0] - '0')*(b[0] - '0'));  
}

std::string karatsuba(std::string x, std::string y) {
    int n = makeEqualLength(x,y);
    cout << "x: " << x << '\n';
    cout << "y: " << y << '\n';
    cout << "n: " << n << '\n';

    // Base cases
    if (n == 0) return "0";
    if (n == 1) return multiplyiSingleBit(x, y);

    std::string a,b,c,d;
    if(x.length() % 2 == 0) {
        a = x.substr(0, n/2);
        b = x.substr(n/2);
    } else {
        a = x.substr(0, n/2+1);
        b = x.substr(n/2+1);
    }
    if(y.length() % 2 == 0) {
    c = y.substr(0, n/2);
    d = y.substr(n/2);
    } else {
    c = y.substr(0, n/2+1);
    d = y.substr(n/2+1);
    }

    /* cout << "a: " << a << '\n'; */
    /* cout << "b: " << b << '\n'; */
    /* cout << "c: " << c << '\n'; */
    /* cout << "d: " << d << '\n'; */

    if (n == 2) {
        int ac = stoi(a) * stoi(c);
        int bd = stoi(b) * stoi(d);
        /* cout << "ac: " << ac << '\n'; */
        /* cout << "bd: " << bd << '\n'; */
        int abcd = (stoi(a) + stoi(b)) * (stoi(c) + stoi(d));
        /* cout << "abcd: " << abcd << '\n'; */
        /* cout << std::to_string(ac * (int)std::pow(10,n) + (abcd - ac - bd) * (int)std::pow(10,n/2) + bd) << '\n'; */
        return std::to_string(ac * (int)std::pow(10,n) + (abcd - ac - bd) * (int)std::pow(10,n/2) + bd);
    }

    std::string ac = karatsuba(a,c);
    std::string bd = karatsuba(b,d);

    /* cout << "ac: " << ac << '\n'; */
    /* cout << "bd: " << bd << '\n'; */
    /* cout << "ab: " << add_string(a,b) << '\n'; */
    /* cout << "cd: " << add_string(c,d) << '\n'; */
    std::string abcd = karatsuba(add_string(a,b),add_string(c,d));
    /* cout << "abcd: " << bd << '\n'; */

    return add_string(add_string(add_zeroes(ac,n), add_zeroes(subtract_string(abcd, ac, bd), n/2)), bd);
}

std::string factorial(int n) {
    vector<string> dyn(n);
    dyn[0] = "1";
    int cnt = 1;
    while(cnt++ < n) {
        dyn[cnt - 1] = (karatsuba(dyn[cnt-2], to_string(cnt)));
        cout << dyn[cnt-1] << '\n';
        cout << cnt << '\n';
    }
    return dyn[n-1];
}

int main() {
    // test add_string
    /* cout << "add 1234 to 5678: " << add_string("1234", "5678") << '\n'; */
    /* cout << "add 99 to 99: " << add_string("99", "99") << '\n'; */
    /* cout << "add 88888888888888888 to 222222222222: " << add_string("88888888888888888", "222222222222") << '\n'; */

    // test subtract_string
    /* cout << "subtract 7 from 9 : " << subtract2("9", "7") << '\n'; */
    /* cout << "subtract 678 and 7 from 999: " << subtract_string("999", "678", "7") << '\n'; */
    /* cout << "subtract 99 and 99 from 200: " << subtract_string("200", "99", "99") << '\n'; */
    /* cout << "subtract 4 and 204 from 350: " << subtract_string("350", "4", "204") << '\n'; */
    // test karatsuba
    /* std::cout << "multiply 15 by 15 (225): " << karatsuba("15","15", 2) << '\n'; */
    /* std::cout << "multiply 15 by 15 (225): " << karatsuba("25","25", 2) << '\n'; */
    /* std::cout << "multiply 1234 by 5678 (7006652): " << karatsuba("5678","1234", 4) << '\n'; */
    string x = trimLeadingZeroes(karatsuba("46", "13423423"));
    std::cout << "multiply 46 by 12313423 (7006652): " << x << '\n';
    x = trimLeadingZeroes(karatsuba("432141", "333"));
    std::cout << "multiply 432141 by 333 (120000): " << x << '\n';
    /* std::cout << "multiply 11111111 by 11111111: " << karatsuba("11111111","11111111", 8) << '\n'; */
    /* std::cout << "multiply stuff: " << karatsuba("3141592653589793238462643383279502884197169399375105820974944592","2718281828459045235360287471352662497757247093699959574966967627", 64) << '\n'; */

    /* string s = factorial(10); */
    /* cout << s << '\n'; */
}
