//(Q:2)-----------Linear Search with Multiple Occurrences-----------
/*
Problem: Given an array, find all the indices where a target integer appears. Return an array
of indices. If the target does not appear, return an empty array.
Example:
Input: arr = [4, 2, 3, 2, 4, 2], target = 2
Output: [1, 3, 5]
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> linearSearchMultipleOccurence(vector<int>& vec, int target){
    vector<int> newVec;
    for(int i=0; i<vec.size(); i++){
        if(vec[i] == target){
            newVec.push_back(i);
        };
    }
    return newVec;
}

int main(){
    vector<int> numbers = {4, 2, 3, 2, 4, 2};
    int x = 2;
    vector<int> resultVector = linearSearchMultipleOccurence(numbers, x);
    if(resultVector.empty()){
        cout << "Element not found";
    }
    else{
        cout << "Element found in the Indexes: ";
        for(int targetIndexes: resultVector){
            cout << targetIndexes << " ";
        }
        cout << endl;

    }

    return 0;
}