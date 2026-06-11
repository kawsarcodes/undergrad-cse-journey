/*
Problem(6): Merge Two Sorted Arrays.
Given two sorted arrays, merge them into a single sorted array.
Example:
Input
A: 1 4 6
B: 2 3 5
Output
1 2 3 4 5 6
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }
    
    while (i < n) {
        result.push_back(a[i]);
        i++;
    }
    while (j < m) {
        result.push_back(b[j]);
        j++;
    }
    
    return result;
}

int main() {
    string lineA, lineB;
    if (getline(cin, lineA) && getline(cin, lineB)) {
        vector<int> a, b;
        stringstream ssA(lineA), ssB(lineB);
        int num;
        
        while (ssA >> num) a.push_back(num);
        while (ssB >> num) b.push_back(num);
        
        vector<int> merged = mergeSortedArrays(a, b);
        for (int i = 0; i < merged.size(); i++) {
            cout << merged[i] << (i == merged.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}