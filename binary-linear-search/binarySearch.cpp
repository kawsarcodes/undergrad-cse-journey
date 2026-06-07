#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& vec, int target){
    int low = 0;
    int high = vec.size() - 1;

    while (low <= high){
        int mid = low + (high - low) / 2;
        if (vec[mid] == target) return mid;
        if (vec[mid] < target) low = mid + 1;
        else high = mid - 1; 
    }
    return -1;
}

int main(){
    vector<int> numbers = {50, 30, 10, 20, 70};
    int x = 10;
    int targetIdx = binarySearch(numbers, x);
    if(targetIdx == -1) cout << "Element not found!";
    else cout << "Element foud at Index: " << targetIdx;




    return 0;
}