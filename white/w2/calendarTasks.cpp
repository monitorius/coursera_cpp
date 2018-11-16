#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


void PrintVector(const vector<string>& v) {
    for(auto s: v) {
        cout << s << " ";
    }
}


typedef vector<string> DayJobs;
typedef vector<DayJobs> Jobs;

void PrintJobs(const Jobs& jobs) {
    for(int i=0; i < jobs.size(); ++i) {
        cout << i << ": ";
        auto dayJobs = jobs[i];
        PrintVector(dayJobs);
        cout << endl;
    }
};


void shrink(Jobs& jobs, int newSize) {
    vector<string> savedJobs;
    for(int i = newSize; i < jobs.size(); ++i) {
        for(string s: jobs[i]) {
            savedJobs.push_back(s);
        }
    }

    jobs.resize(newSize);
    if (jobs.size() > 0) {
        for (string s: savedJobs) {
            jobs[jobs.size() - 1].push_back(s);
        }
    }

}

void testShrink() {
    struct TestData {
        Jobs jobs;
        int newSize;
        Jobs expectedJobs;
    };

    vector<TestData> testsData = {
            {
                    {{"a", "b"},
                            {"c", "d"},
                            {"e"},
                            {"g", "h"},
                    },
                    2,
                    {{"a", "b"},
                            {"c", "d", "e", "g", "h"},
                    }
            },
            {
                    {   {"a", "b"},
                            {"c", "d"},
                            {"e", "f"},
                            {"h"},
                    },
                    4,
                    {   {"a", "b"},
                            {"c", "d"},
                            {"e", "f"},
                            {"h"},
                    }
            },
            {
                    {   {"a", "b"},
                            {"c", "d"},
                            {"e", "f"},
                            {"g", "h"},
                    },
                    0,
                    {}
            },
    };

    int failed = 0;
    for (auto t: testsData) {
        Jobs jobs = t.jobs;
        const Jobs& expectedJobs = t.expectedJobs;
        const int& newSize = t.newSize;

        shrink(jobs, newSize);

        bool good = jobs == expectedJobs;
        if (!good) {
            failed += 1;
            PrintJobs(t.jobs);
            cout << endl;
            PrintJobs(jobs);
            cout << endl;
            PrintJobs(expectedJobs);
            cout << "========" << endl;
        }
    }
    cout << "failed: " << failed << endl;
};


void run() {
    const vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int currentMonth = 0;
    Jobs jobs(monthDays[currentMonth]);

    int n;
    cin >> n;
    for(int j=0; j < n; ++j) {
        string cmd;
        cin >> cmd;
        if (cmd == "NEXT") {
            int nextMonth;
            if (currentMonth == monthDays.size() - 1) {
                nextMonth = 0;
            }
            else {
                nextMonth = currentMonth + 1;
            }

            if (monthDays[nextMonth] >= monthDays[currentMonth]) {
                jobs.resize(monthDays[nextMonth]);
            }
            else {
                shrink(jobs, monthDays[nextMonth]);
            }
            currentMonth = nextMonth;
        }
        else if (cmd == "ADD") {
            int i;
            string s;
            cin >> i >> s;
            i--;
            jobs[i].push_back(s);
        }
        else if (cmd == "DUMP") {
            int i;
            cin >> i;
            i--;
            cout << jobs[i].size() << " ";
            for(const auto& s: jobs[i]) {
                cout << s << " ";
            }
            cout << endl;
        }
    }
}


int main() {

    run();
//    testShrink();


    return 0;
}