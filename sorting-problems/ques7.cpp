//(Q:7)-----------Longest Consecutive Subsequence-----------
/*
Problem: Find the Longest Consecutive Subsequence after sorting an array.
Example 1:
Input: a = [1, 9, 3, 10, 4, 20, 2]
Sorted: [1, 2, 3, 4, 9, 10, 20]
Seq: [1,2,3,4] len=4, [9,10] len=2, [20] len=1
Output: 4

Example 2:
Input: a = [3, 1]
Output: 1
*/

#include<iostream>
#include<vector>
#include<algorithm> 
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

int findLongestConsecutive(vector<int> arr) {
    int n = arr.size();
    if (n == 0) return 0;
    bubbleSort(arr);

    int longestStreak = 1;
    int currentStreak = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1] + 1) {
            currentStreak++;
        }
        else if (arr[i] == arr[i - 1]) {
            continue;
        }
        else {
            currentStreak = 1;
        }

        if (currentStreak > longestStreak) {
            longestStreak = currentStreak;
        }
    }

    return longestStreak;
}

int main() {
    vector<int> arr1 = {1, 9, 3, 3, 10, 4, 20, 2};
    cout << "Input: [1, 9, 3, 10, 4, 20, 2]" << endl;
    //1, 2, 3, 3, 4, 9, 10, 20
    cout << "Longest Subsequence: " << findLongestConsecutive(arr1) << endl;

    cout << "-----------------------" << endl;

    vector<int> arr2 = {3, 1};
    cout << "Input: [3, 1]" << endl;
    cout << "Longest Subsequence: " << findLongestConsecutive(arr2) << endl;

    return 0;
}