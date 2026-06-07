//(Q:3)-----------Linear Search with Condition-----------
/*
Problem: Find the first element in an array of integers that is greater than a given target. If
no such element exists, return -1.
Example:
Input: arr = [3, 5, 7, 2, 8, 10], target = 6
Output: 7
*/

#include<iostream>
#include<vector>
using namespace std;

int linearSearchWithCondition(vector<int>& vec, int target){
   for(int i=0; i<vec.size(); i++){
    if(vec[i] > target) return vec[i];
   }
   return -1;
}

int main(){
    vector<int> numbers = {3, 5, 7, 2, 8, 10};
    int x = 6;
    int targetNumber = linearSearchWithCondition(numbers, x);
    if(targetNumber == -1) cout << "Element not found!";
    else cout << "Element is: " << targetNumber;

    return 0;
}