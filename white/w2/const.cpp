#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto s: source) {
        destination.push_back(s);
    }

    source.clear();
}

void testMove() {
    vector<string> a = {"1", "2"};
    vector<string> b = {"3", "4"};
    MoveStrings(a, b);

    for(auto s: a) {
        cout << s << endl;
    }

    cout << "bb" << endl;
    for(auto s: b) {
        cout << s << endl;
    }
}

void Reverse(vector<int>& v) {
    for(size_t i = 0; i < v.size() / 2; ++i) {
        int tmp = v[i];
        v[i] = v[v.size() - i - 1];
        v[v.size() - i - 1] = tmp;
    }
}


vector<int> Reversed(const vector<int>& v) {
    vector<int> res;
    for(long i = v.size() - 1; i >= 0; --i) {
        res.push_back(v[i]);
    }
    return res;
}


int main() {
    vector<int> v = {1, 2, 3};
    vector<int> v1 = Reversed(v);
    for(auto s: v1) {
        cout << s << endl;
    }

    return 0;
}