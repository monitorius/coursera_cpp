#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;


vector<double> sq(double a, double b, double c) {
    vector<double> roots = {NAN, NAN};

    if (a == 0) {
        if (b != 0) {
            roots[0] = -c / b;
        }
        return roots;
    };


    double D = b*b - 4*a*c;
    if (D > 0) {
        roots[0] = (-b + sqrt(D)) / (2*a);
        roots[1] = (-b - sqrt(D)) / (2*a);
    }
    else if (D == 0) {
        roots[0] = -b / (2 * a);
    }

    return roots;
}


bool vectorsEqual(vector<double> a, vector<double> b) {
    for(int i=0; i < a.size(); ++i) {
        double av = a[i];
        if (isnan(av)) {
            if (!isnan(b[i])) {
                return false;
            }
        }
        else if (av != b[i]) {
            return false;
        }
    }

    return true;
}


void prnt(vector<double> v) {
    for(auto c: v) {
        cout << c << " ";
    }
}


void test() {
    struct TestData {
        vector<double> input;
        vector<double> expected;
    };

    vector<TestData> test_data = {
        {{2, 5, 2}, {-0.5, -2}},
        {{2, 4, 2}, {-1}},
        {{2, 1, 2}, {}},
        {{0, 4, 10}, {-2.5}},
        {{0, 0, 10}, {}},
    };

    for(TestData td: test_data) {
        double a = td.input[0];
        double b = td.input[1];
        double c = td.input[2];

        vector<double> roots = sq(a, b, c);

        if (vectorsEqual(td.expected, roots)) {
            cout << "OK   ";
        } else {
            cout << "FAIL ";
        }
        cout << a << " " << b << " " << c << "   ->   ";
        prnt(roots);
        cout << endl;
    };
}


void consoleRun(bool enableCin) {
    double a, b, c;

    if (enableCin) {
        cin >> a >> b >> c;
    } else {
        a = 0;
        b = 4;
        c = 10;
    }

    auto roots = sq(a, b, c);
    if (!isnan(roots[0])) {
        cout << roots[0] << ' ';
    }
    if (!isnan(roots[1])) {
        cout << roots[1];
    }
}


int main() {
    bool local_run = 0;
    bool runTests = 1;

    if (local_run) {
        if (runTests) {
            cout << "tests" << endl;
            test();
        } else {
            consoleRun(0);
        }
    } else {
        consoleRun(1);
    }

    return 0;
}