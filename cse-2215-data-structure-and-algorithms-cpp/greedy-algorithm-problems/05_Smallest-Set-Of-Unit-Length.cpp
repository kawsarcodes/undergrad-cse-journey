/*
PROBLEM 05. Determine the smallest set of unit-length closed intervals

Given a set of points on the real line, give an algorithm to determine the smallest
set of unit-length closed intervals that contains all of the points. A closed interval includes both its
endpoints.

Sample input
6
5.22 6.1 2.2 2.5 3.25 4.8

Sample output
5
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<double> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    int intervalCount = 0;
    int i = 0;

    while (i < n) {
        intervalCount++;
        double intervalEnd = points[i] + 1.0;
        
        while (i < n && points[i] <= intervalEnd) {
            i++;
        }
    }

    cout << intervalCount << "\n";
    return 0;
}