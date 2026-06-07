//(Q:2)-----------Find the kth Smallest Element (Using Bubble Sort)-----------
/*
Problem: Find the kth smallest element from an array manually using Bubble Sort.
Example 1:
Input: a = [6, 5, 1, 3, 4], k = 2
Output: 3
a
Example 2:
Input: a = [7, 9, 1, 8, 2], k = 4
Output: 8
*/

#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int findKthSmallest(vector<int> arr, int k) {
    bubbleSort(arr);

    return arr[k - 1];
}

int main() {
    vector<int> a1 = {6, 5, 1, 3, 4};
    int k1 = 2;
    cout << "Input: [6, 5, 1, 3, 4], k=2" << endl;
    cout << "Output: " << findKthSmallest(a1, k1) << endl;
    
    cout << "-----------------------" << endl;

    vector<int> a2 = {7, 9, 1, 8, 2};
    int k2 = 4;
    cout << "Input: [7, 9, 1, 8, 2], k=4" << endl;
    cout << "Output: " << findKthSmallest(a2, k2) << endl;

    return 0;
}