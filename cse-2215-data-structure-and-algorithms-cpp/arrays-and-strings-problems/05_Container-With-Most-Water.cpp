/*
PROBLEM 05. Container With Most Water

Given n non-negative integers representing an array of vertical lines, find two lines that together with the x-axis forms a container that contains the most water.

Sample input
9
1 8 6 2 5 4 8 3 7

Sample output
44
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int max_water = 0;
    int left = 0, right = n - 1;

    while (left < right) {
        int width = right - left;
        int current_height = min(height[left], height[right]);
        max_water = max(max_water, width * current_height);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    cout << max_water << "\n";
    return 0;
}