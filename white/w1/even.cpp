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

    for(; a<=b; ++a) {
        if (a % 2 == 0) {
            buf << a << " ";
        }
    }

    return buf.str();
}

void test() {
    vector<TestData> testData = {
            {1, 10, "2 4 6 8 10"},
            {2, 3, "2"},
            {9, 11, "10"},
            {9, 12, "10 12"},
    };

    for(auto t: testData) {
        cout << t.a << " " << t.b << " ";
        string res = run(t.a, t.b);
        cout << res << ", expected " << t.res << endl;
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