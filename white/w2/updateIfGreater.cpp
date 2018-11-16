#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


struct TestData {
    int a, b;
    int res;
};


void UpdateIfGreater(const int& a, int& b) {
    if (a > b) {
        b = a;
    }
}


void test() {
    vector<TestData> testData = {
            {1, 2, 2},
            {3, 1, 3},
    };

    for(auto t: testData) {
        cout << t.a << " " << t.b << " ";
        UpdateIfGreater(t.a, t.b);
        string msg = t.b == t.res ? "OK" : "FAIL";
        cout << t.b << ", expected " << t.res << " (" << msg << ")" << endl ;
    }
}


int main() {
    test();

    return 0;
}