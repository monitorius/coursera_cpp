#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


struct TestData {
    double n, a, b, x, y;
    string res;
};


string discounted(double n, double a, double b, double x, double y) {
    double res;
    if (n <= a) {
        res = n;
    }
    else if (n <= b) {
        res = n * (100 - x) / 100;
    }
    else {
        res = n * (100 - y) / 100;
    }

    stringstream buf;
    buf << res;
    return buf.str();
}


void test() {
    vector<TestData> testData = {
            {100, 110, 120, 5, 10,  "100"},
            {115, 110, 120, 5, 10, "109.25"},
            {150, 110, 120, 5, 12.5, "131.25"}
    };

    for(auto t: testData) {
        cout << t.n << " " << t.a << " " << t.b << " " << t.x << " " << t.y << " ";
        string res = discounted(t.n, t.a, t.b, t.x, t.y);
        cout << res << ", expected " << t.res << endl;
    }
}

void consoleRun() {
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    cout << discounted(n, a, b, x, y);
}

int main() {
//    test();
    consoleRun();

    return 0;
}