//(Q:8)-----------Count Occurrences with Binary Search-----------
/*
Problem: In a sorted array, count the occurrences of a target value using binary search.
Example:
Input: arr = [2, 4, 4, 4, 6, 7], target = 4
Output: 3
*/

#include<iostream>
#include<vector>
using namespace std;

int findFirst(vector<int>& vec, int target){
    int low = 0;
    int high = vec.size() - 1;
    int result = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(vec[mid] == target){
            result = mid;
            high = mid - 1; 
        }
        else if(vec[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return result;
}

// Helper: Find Last Occurrence
int findLast(vector<int>& vec, int target){
    int low = 0;
    int high = vec.size() - 1;
    int result = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(vec[mid] == target){
            result = mid;
            low = mid + 1; 
        }
        else if(vec[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return result;
}

int countOccurrences(vector<int>& arr, int target) {
    int firstIndex = findFirst(arr, target);
    
    if (firstIndex == -1) {
        return 0;
    }

    int lastIndex = findLast(arr, target);
    
    return (lastIndex - firstIndex) + 1;
}

int main(){
    vector<int> arr = {2, 4, 4, 4, 4, 6, 7};
    int target = 4;

    int count = countOccurrences(arr, target);

    cout << "Occurrences of " << target << ": " << count << endl;

    return 0;
}