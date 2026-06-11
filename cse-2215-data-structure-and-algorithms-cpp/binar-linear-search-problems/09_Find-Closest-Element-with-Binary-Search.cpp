//(Q:9)-----------Find Closest Element with Binary Search-----------
/*
Problem: Given a sorted vecay, find the element closest to a given target. 
If two elements are equally close, return the smaller one.
Example:
Input: vec = [1, 3, 8, 10, 15], target = 12
Output: 10
*/

#include<iostream>
#include<vector>
#include<cmath> 
using namespace std;

int findClosest(vector<int>& vec, int target) {
    int n = vec.size();

    if (target <= vec[0]) return vec[0];
    if (target >= vec[n - 1]) return vec[n - 1];

    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] == target) {
            return vec[mid]; 
        }

        if (target < vec[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    int val1 = vec[high];
    int val2 = vec[low];

    if (abs(target - val1) <= abs(target - val2)) {
        return val1;
    } else {
        return val2;
    }
}

int main() {
    vector<int> vec = {1, 3, 8, 10, 15};
    int target = 12;

    int closestElement = findClosest(vec, target);

    cout << "Closest element to " << target << " is: " << closestElement << endl;

    return 0;
}