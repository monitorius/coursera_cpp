#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


struct TestData {
    int a;
    int b;
    string res;
};


string run(int a, int b) {
    if (b == 0) {
        return "Impossible";
    }
    else {
        int res = a / b;
        return std::to_string(res);
    }
}

void test() {
    vector<TestData> testData = {
            {10, 2, "5"},
            {3, 5, "0"},
            {3, 2, "1"},
            {11, 0, "Impossible"},
    };

    for(auto td: testData) {
        cout << td.a << " " << td.b << " ";
        string res = run(td.a, td.b);
        cout << res << endl;
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