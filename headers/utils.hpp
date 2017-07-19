#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

pair<int, int> lcf(int a, int b) {
    return make_pair(a / gcd(a,b), b / gcd(a,b));
}

string karatsuba(string x, string y);

string exponentStr(string a, string b) {
    string out = "1";
    for(int i=0; i < stoi(b); i++) {
        out = karatsuba(out, a);
    }
    return out;
}

int fib(int n) {
    vector<int> fib(n,0);
    fib[0] = 1;
    fib[1] = 1;
    for(int i=2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2]; 
    }
    return fib[fib.size()-1];
}

vector<int> sieveEratosthenes(int size) {
    vector<int> out(size, 1);
    out[0] = 0;
    out[1] = 0;
    int nextPrime = 2;
    for(int i = nextPrime * 2; i <= size; i += nextPrime) {
        out[i] = 0; 
    }
    nextPrime++;
    while(nextPrime <= size) {
        for(int i = nextPrime * 2; i <= size; i += nextPrime) {
            out[i] = 0; 
        } 
        do {
            nextPrime += 2;
        } while(nextPrime <= size && out[nextPrime] == 0);
    }
    return out;
}

int countDigits(int i) {
    int digits = 0;
    while(i > 0) {
        digits++;
        i /= 10;
    }
    return digits;
}

int rotateNumber(int i) {
    return (i % 10) * pow(10, countDigits(i) - 1) + i / 10;
}

bool isPalindrome(int x) {
    string s = to_string(x);
    for(int i=0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size()-1-i]) return false; 
    }
    return true;
}

bool isPalindrome(vector<int> x) {
    for(int i=0; i < x.size() / 2; i++) {
        if(x[i] != x[x.size()-1-i]) return false; 
    }
    return true;
}

vector<int> decToBinary(int x) {
    vector<int> out;
    while(x > 0) {
        out.emplace_back(x % 2 == 1 ? 1 : 0);
        x /= 2;
    }
    return out;
}

int sumOfProperFactors(int n) {
    int tmp = sqrt(n); 
    int sum = 1;
    for(int i=2; i <= tmp; i++) {
        int x = n % i;
        if(n % i == 0) {
            if(i * i == n) {
                sum += tmp;
            }
            else {
                sum += i;
                sum += n / i;
            }
        }
    }
    return sum;
}

bool isAbundant(int n) {
    return sumOfProperFactors(n) > n;
}

vector<string> parseCSV(string filename) {
    ifstream infile(filename);
    string line;
    int n;
    vector<string> out;
    while(getline(infile, line, ',')) {
        // for CSV with quotes around the string
        //out.emplace_back(line);
        out.emplace_back(line.substr(1, line.size()-2));
    }
    return out;
}

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

    if (n == 2) {
        int ac = stoi(a) * stoi(c);
        int bd = stoi(b) * stoi(d);
        int abcd = (stoi(a) + stoi(b)) * (stoi(c) + stoi(d));
        return std::to_string(ac * (int)std::pow(10,n) + (abcd - ac - bd) * (int)std::pow(10,n/2) + bd);
    }

    std::string ac = karatsuba(a,c);
    std::string bd = karatsuba(b,d);

    std::string abcd = karatsuba(add_string(a,b),add_string(c,d));

    int tmp = n / 2;
    return trimLeadingZeroes(add_string(add_string(add_zeroes(ac,2 * tmp), add_zeroes(subtract_string(abcd, ac, bd), tmp)), bd));
}

std::string factorial(int n) {
    if(n == 0) return "1"; // 0! = 1
    vector<string> dyn(n);
    dyn[0] = "1";
    int cnt = 1;
    while(cnt++ < n) {
        dyn[cnt - 1] = trimLeadingZeroes((karatsuba(dyn[cnt-2], to_string(cnt)))); }
    return dyn[n-1];
}
