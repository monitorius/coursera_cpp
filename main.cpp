#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


void PrintVector(const vector<string>& v) {
    for(const auto& s: v) {
        cout << s << " ";
    }
}


void PrintMap(const map<char, vector<string>>& m) {
    cout << "Size: " << m.size() << endl;
    for(const auto& item: m) {
        cout << "\t" << item.first << ": ";
        for(const auto& w: item.second) {
            cout << w << "; ";
        }
        cout << endl;
    }
}

void PrintMap(const map<string, int>& m) {
    cout << "Size: " << m.size() << endl;
    for(const auto& item: m) {
        cout << "\t" << item.first << ": " << item.second << endl;
    }
}


//int main() {
//    vector<string> words = {"aa", "ba", "ca", "av"};
//    map<char, vector<string>> groupedWords;
//    for(const auto& w: words) {
//        PrintMap(groupedWords);
//        groupedWords[w[0]].push_back(w);
//    };
//
//    PrintMap(groupedWords);
//
//    return 0;
//}


int main() {
    map<string, int> m = {{"one", 1}};

    for(const auto& [key, val]: m) {
        cout << key << " " << val;
    }


    return 0;
}