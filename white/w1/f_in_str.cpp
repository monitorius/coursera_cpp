#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


struct TestData {
    string s;
    string res;
};


string run(string s) {
    stringstream buf;

    int s_num = 0;
    for(int i = 0; i < s.size(); ++i) {
        if (s[i] == 'f') {
            s_num += 1;
            if (s_num == 2) {
                buf << i;
                return buf.str();
            }
        }
    }

    if (s_num == 1) {
        buf << -1;
    }
    else {
        buf << -2;
    }

    return buf.str();

}

void test() {
    vector<TestData> testData = {
            {"comfort", "-1"},
            {"coffee", "3"},
            {"car", "-2"},
            {"", "-2"},
    };

    for(auto t: testData) {
        cout << t.s << " ";
        string res = run(t.s);
        cout << res << ", expected " << t.res << endl;
    }
}

void consoleRun() {
    string s;
    cin >> s;
    cout << run(s);
}

int main() {
//    test();
    consoleRun();

    return 0;
}