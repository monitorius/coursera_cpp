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

typedef vector<int> Queue;

const int QUIET = 0;
const int WORRIED = 1;


void setValue(Queue& q, int i, int value) {
    q[i] = value;
}

void add(Queue& q, int k) {
    q.resize(q.size() + k, QUIET);
}

void remove(Queue& q, int k) {
    q.resize(q.size() + k);
}

int countValue(Queue& q, int value) {
    int sum = 0;
    for(auto v: q) {
        if (v == value) {
            sum++;
        }
    }
    return sum;
}


int main() {
    Queue q;

    int n;
    cin >> n;
    for(int i=0; i < n; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "WORRY_COUNT") {
            cout << countValue(q, WORRIED) << endl;
        }
        else {
            int i;
            cin >> i;

            if (cmd == "WORRY") {
                setValue(q, i, WORRIED);
            }
            else if (cmd == "QUIET") {
                setValue(q, i, QUIET);
            }
            else if (cmd == "COME") {
                if (i >= 0) {
                    add(q, i);
                }
                else {
                    remove(q, i);
                }
            }
        }
//        PrintVector(q);
//        cout << endl;
    }

    return 0;
}