/*
Problem(8): Print the List Elements.
Given a list of elements, print them sequentially from first to last using recursion.
Example:
Input
4
10 20 30 40
Output
10 20 30 40 
*/

#include <bits/stdc++.h>
using namespace std;

void printList(const vector<int>& arr, int index) {
    if (index == arr.size()) return;
    cout << arr[index] << " ";
    printList(arr, index + 1);
}

int main() {
    int n;
    if (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        printList(arr, 0);
        cout << endl;
    }
    return 0;
}