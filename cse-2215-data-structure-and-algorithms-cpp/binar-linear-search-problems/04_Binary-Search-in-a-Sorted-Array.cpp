//(Q:4)-----------Binary Search in a Sorted Array-----------
/*
Problem: Implement binary search in a sorted array to locate a target value. Return the
index of the target if found; otherwise, return -1.
Example:
Input: arr = [1, 3, 5, 7, 9], target = 5
Output: 2
*/

#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& vec, int target){
    int low = 0;
    int high = vec.size() - 1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(vec[mid] == target) return mid;
        else if(vec[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    vector<int> numbers = {1, 3, 5, 7, 9};
    int x = 5;
    int targetindex = binarySearch(numbers, x);
    if(targetindex == -1) cout << "Element not found!";
    else cout << "Target found at index: " << targetindex;


    return 0;
}