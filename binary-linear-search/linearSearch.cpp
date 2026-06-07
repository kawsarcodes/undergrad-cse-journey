#include<iostream>
#include<vector>
using namespace std;

int linearSearch(vector<int>& vec, int target){
   for(int i=0; i<vec.size(); i++){
    if(vec[i] == target) return i;
   }
   return -1;
}

int main(){
    vector<int> numbers = {5, 3, 8, 1, 9};
    int x = 8;
    int targetIdx = linearSearch(numbers, x);
    if(targetIdx == -1) cout << "Element not found!";
    else cout << "Element foud at Index: " << targetIdx;

    return 0;
}