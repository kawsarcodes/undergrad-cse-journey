//(Q:3)-----------Find the Smallest Difference-----------
/*
Problem: Find the smallest difference of elements from an array.
Example 1:
Input: a = [15, 7, 2, 12, 13]
Output: 1

Example 2:
Input: a = [2, 13, 11, 19, 5]
Output: 2
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int findSmallestDifference(vector<int> arr) {
    int n = arr.size();
    if (n < 2) return 0;

    bubbleSort(arr);

    int minDiff = INT_MAX;

    for (int i = 0; i < n - 1; i++) {
        int diff = arr[i+1] - arr[i];
        
        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    return minDiff;
}

int main() {
    vector<int> a1 = {15, 7, 2, 12, 13};
    cout << "Input: [15, 7, 2, 12, 13]" << endl;
    cout << "Sorted: [2, 7, 12, 13, 15]" << endl;
    cout << "Output: " << findSmallestDifference(a1) << endl;

    cout << "-----------------------" << endl;

    vector<int> a2 = {2, 13, 11, 19, 5};
    cout << "Input: [2, 13, 11, 19, 5]" << endl;
    cout << "Output: " << findSmallestDifference(a2) << endl;

    return 0;
}