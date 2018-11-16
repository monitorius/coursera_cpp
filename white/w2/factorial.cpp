#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


struct TestData {
    int a;
    int res;
};


int Factorial(int a) {
    if (a < 0) {
        return 1;
    }

    int res = 1;
    for(int i=a; i > 0; --i) {
        res *= i;
    }

    return res;
}


void test() {
    vector<TestData> testData = {
            {1,  1},
            {3,  6},
            {10, 3628800},
            {0,  1},
            {-5, 1},
            {-6, 1},
    };

    for(auto t: testData) {
        cout << t.a << " ";
        int res = Factorial(t.a);
        string msg = res == t.res ? "OK" : "FAIL";
        cout << res << ", expected " << t.res << " (" << msg << ")" << endl ;
    }
}


int main() {
    test();

    return 0;
}