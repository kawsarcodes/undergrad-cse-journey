//(Q:2)-----------Find the Median (Using Bubble Sort)-----------
/*
Problem: Find the median from an vecay.
Example 1:
Input: a = [5, 2, 1, 4, 7]
Output: 4

Example 2:
Input: a = [11, 9, 17, 15]
Output: 13
*/


#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& vec) {
    int n = vec.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(vec[j] > vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

double findMedian(vector<int>& vec) {
    bubbleSort(vec);

    int n = vec.size();

    if (n % 2 != 0) {
        return vec[n / 2];
    } else {
        int val1 = vec[(n / 2) - 1];
        int val2 = vec[n / 2];
        
        return (val1 + val2) / 2.0;
    }
}

int main() {
    vector<int> a1 = {5, 2, 1, 4, 7};
    cout << "Input: [5, 2, 1, 4, 7]" << endl;
    cout << "Output: " << findMedian(a1) << endl;

    cout << "-----------------------" << endl;

    vector<int> a2 = {11, 9, 17, 15};
    cout << "Input: [11, 9, 17, 15]" << endl;
    cout << "Output: " << findMedian(a2) << endl;

    return 0;
}