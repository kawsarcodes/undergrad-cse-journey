/*
3. Given a sorted array, return the index where a target value should be inserted to maintain the
order. Use binary search.
Input Output
a = [1, 3, 5, 6], target = 4 2
a = [1,9,15,21,36], target = 2 1
*/

#include<iostream>
#include<vector>
using namespace std;

int binarySearchTargetIndex(vector<int>& vec, int target){
    int low = 0;
    int high = vec.size() - 1;

    while (low <= high){
        int mid = low + (high - low) / 2;
        if (vec[mid] == target) return mid;
        if (vec[mid] < target) low = mid + 1;
        else high = mid - 1; 
    }
    return low;
}

int main(){
    vector<int> numbers = {1, 3, 5, 6};
    int x = 4;
    int targetIdx = binarySearchTargetIndex(numbers, x);
    cout << "Target Index: " << targetIdx;


    return 0;
}