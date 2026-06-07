#include<iostream>
#include<vector>
using namespace std;

// Bubble sort
void bubbleSort(vector<int>& vec){
    int n = vec.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(vec[j] > vec[j+1]){
                swap(vec[j], vec[j+1]);
            }
        }
    }
}

// Binary search on ascending array
int binarySearch(vector<int>& vec, int target){
    int low = 0;
    int high = vec.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(vec[mid] == target) return mid;
        if(vec[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(){
    vector<int> numbers = {50, 30, 10, 20, 70};
    int x = 10;

    // Sort first
    bubbleSort(numbers);

    // Now search
    int targetIdx = binarySearch(numbers, x);

    if(targetIdx == -1) cout << "Element not found!";
    else cout << "Element found at index: " << targetIdx;

    return 0;
}
