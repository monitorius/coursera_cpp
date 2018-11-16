#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


void PrintVector(const vector<int>& v) {
    for(auto s: v) {
        cout << s << " ";
    }
}

int main() {
    unsigned int n;

    cin >> n;
    vector<int> days(n);
    for(int& v: days) {
        cin >> v;
    }

//    vector<int> days = {3, 1, 2, 3, 3};

    double sum = 0;
    for (auto v: days) {
        sum += v;
    }
    double avg = sum / days.size();

    vector<int> res;
    for (int i=0; i < days.size(); ++i) {
        if (days[i] > avg) {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    PrintVector(res);

    return 0;
}