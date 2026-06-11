/*
PROBLEM 04. Finding Minimum Stops

Suppose you were to drive from A to B, which is D miles away, along a straight road. Your gas tank,
when full, holds enough gas to travel m miles, and you have a map that gives distances between gas
stations along the route. Let d1 < d2 < ... < dn be the locations of all the gas stations along the route
where di is the distance from St. Louis to the gas station. You can assume that the distance between
neighboring gas stations is at most m miles. Your goal is to make as few gas stops as possible along the
way. Give the most efficient algorithm you can to determine at which gas stations you should stop.
Write a code to solve this problem using a greedy algorithm. Keep the time complexity of your code O(n).

Sample input
20
10
8
2 4 5 8 12 14 16 19

Sample output
stop at gas station 4 ( 8 miles)
stop at gas station 7 (16 miles)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, m, n;
    if (!(cin >> d >> m >> n)) return 0;

    vector<int> stops(n);
    for (int i = 0; i < n; i++) {
        cin >> stops[i];
    }

    int currentPos = 0;
    int i = 0;
    vector<pair<int, int>> stopsMade;
    bool status = true;

    while (currentPos + m < d) {
        int lastValidStopIdx = -1;
        
        while (i < n && stops[i] <= currentPos + m) {
            lastValidStopIdx = i;
            i++;
        }

        if (lastValidStopIdx == -1 || stops[lastValidStopIdx] == currentPos) {
            status = false;
            break;
        }

        currentPos = stops[lastValidStopIdx];
        stopsMade.push_back({lastValidStopIdx + 1, currentPos});
    }

    if (!status) {
        cout << "Can't reach destination\n";
    } else {
        for (auto p : stopsMade) {
            cout << "stop at gas station " << p.first << " ( " << p.second << " miles)\n";
        }
    }

    return 0;
}