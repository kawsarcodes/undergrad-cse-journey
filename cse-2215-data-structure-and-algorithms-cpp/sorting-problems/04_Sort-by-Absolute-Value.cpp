//(Q:5)-----------Sort by Absolute Value-----------
/*
Problem: Sort an array by absolute value in ascending order.
Input: a = [-10, 5, -3, 7, -2]
Output: [-2, -3, 5, 7, -10]
*/

#include<iostream>
#include<vector>
#include<cmath> 
using namespace std;

void bubbleSortAbs(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            
            if(abs(arr[j]) > abs(arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    vector<int> arr = {-10, 5, -3, 7, -2};

    cout << "Original Array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    bubbleSortAbs(arr);

    cout << "Sorted by Abs:  ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}