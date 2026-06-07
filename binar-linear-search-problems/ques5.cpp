//(Q:5)-----------Binary Search in Descending Order Array-----------
/*
Problem: Perform binary search on a descending order sorted array to find a target value.
Example:
Input: arr = [9, 7, 5, 3, 1], target = 7
Output: 1
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
        else if(vec[mid] < target) high = mid - 1;
        else low = mid + 1; 
    }
    return -1;
}

int main(){
    vector<int> numbers = {9, 7, 5, 3, 1};
    int x = 7;
    int targetindex = binarySearch(numbers, x);
    if(targetindex == -1) cout << "Element not found!";
    else cout << "Target found at index: " << targetindex;


    return 0;
}