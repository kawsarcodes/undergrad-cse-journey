//(Q:6)-----------Binary Search for First and Last Occurrence-----------
/*
Problem: Given a sorted array, find the first and last positions of a target value. 
If the target is not found, return (-1, -1).
Example:
Input: arr = [1, 2, 2, 2, 3, 4], target = 2
Output: (1, 3)
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
        else if(vec[mid] < target){
            low = mid + 1;   
        }
        else {
            high = mid - 1;   
        }
    }
    return result;
}

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
        else if(vec[mid] < target){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return result;
}

int main(){
    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int target = 2;
    
    int firstIndex = findFirst(arr, target);
    int lastIndex = findLast(arr, target);

    cout << "Output: (" << firstIndex << ", " << lastIndex << ")" << endl;

    return 0;
}