#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


struct TestData {
    vector<string> v;
    int l;
    vector<string> res;
};


bool IsPalindrom(string s) {
    size_t size = s.size();
    for(int i=0; i < size / 2; ++i) {
        if (s[i] != s[size - i - 1]) {
            return false;
        }
    }
    return true;
}


vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> res;
    for(auto s: words) {
        if (s.size() >= minLength && IsPalindrom(s)) {
            res.push_back(s);
        }
    }
    return res;
}


void test() {
    vector<TestData> testData = {
            {{"abacaba", "aba"}, 5, {"abacaba"}},
            {{"abacaba", "aba"}, 2, {"abacaba", "aba"}},
            {{"weew", "bro", "code"}, 4, {"weew"}},
    };

    for(auto t: testData) {
//        cout << t.v << " " << ;
        vector<string> res = PalindromFilter(t.v, t.l);
        string msg = res == t.res ? "OK" : "FAIL";
        cout << " (" << msg << ")" << endl ;
    }
}


int main() {
    test();

    return 0;
}