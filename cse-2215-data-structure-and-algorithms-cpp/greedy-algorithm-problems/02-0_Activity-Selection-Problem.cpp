/*
PROBLEM 02. Activity Selection Problem

Problem Description: Suppose we have a set S = {a_1, a_2, ..., a_n} of n proposed activities that wish to
use a resource, such as a lecture hall, which can serve only one activity at a time. Each activity a_i has a
start time s_i and a finish time f_i, where 0 <= s_i < f_i. If selected, activity ai takes place during the
half-open time interval [s_i, f_i). Activities a_i and a_j are compatible if the intervals [s_i, f_i) and [s_j,
f_j) do not overlap. That is, a_i and a_j are compatible if s_i >= f_j or s_j <= f_i. In the activity-selection
problem, we wish to select a maximum-size subset of mutually compatible activities.

Possible greedy strategies:
- Select the activity that starts first, next select the activity that starts first and does not conflict with the already picked activities
- Select the activity that ends first (this one gives the optimal answer)
- Select the activity that has the shortest duration first
*/

#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int id;
    int start;
    int finish;
};

bool compareActivities(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        activities[i].id = i + 1;
        cin >> activities[i].start >> activities[i].finish;
    }

    sort(activities.begin(), activities.end(), compareActivities);

    vector<int> selected;
    if (n > 0) {
        selected.push_back(activities[0].id);
        int lastFinish = activities[0].finish;
        
        for (int i = 1; i < n; i++) {
            if (activities[i].start >= lastFinish) {
                selected.push_back(activities[i].id);
                lastFinish = activities[i].finish;
            }
        }
    }

    cout << "Selected Activity IDs: ";
    for (int id : selected) {
        cout << id << " ";
    }
    cout << "\nTotal activities: " << selected.size() << "\n";

    return 0;
}