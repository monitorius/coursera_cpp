#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


struct TestData {
    int a, b;
    string res;
};


string run(int a, int b) {
    stringstream buf;

    int min = a < b ? a : b;
    for(int i = min; i > 0; --i) {
        if( (a % i == 0) && (b % i == 0)) {
            buf << i;
            return buf.str();
        }
    }
}


void test() {
    vector<TestData> testData = {
            {25, 27, "1"},
            {12, 16, "4"},
            {13, 13, "13"},
    };

    for(auto t: testData) {
        cout << t.a << " " << t.b << " ";
        string res = run(t.a, t.b);
        string msg = res == t.res ? "OK" : "FAIL";
        cout << res << ", expected " << t.res << " (" << msg << ")" << endl ;
    }
}

void consoleRun() {
    int a, b;
    cin >> a >> b;
    cout << run(a, b);
}

int main() {
//    test();
    consoleRun();

    return 0;
}