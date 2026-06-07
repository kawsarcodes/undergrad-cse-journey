//(Q:5)-----------Sort Strings by Length-----------
/*
Problem: Sort an Array of Strings according to length.
Input: a = ["apple", "bat", "carrot", "dog"]
Output: ["bat", "dog", "apple", "carrot"]
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void sortingArray(vector<string>& vec){
    int n = vec.size();
    for (int i=0; i<n-1; i++){
        bool swapped = false;
        for (int j=0; j<n-i-1; j++){
            if(vec[j].length() > vec[j+1].length()){
                swap(vec[j], vec[j+1]);
            }
        }
        if(swapped == false) break;
    }
}

void printString (vector<string>& vec){
    for (string elements : vec){
        cout << elements << " ";
    }
}

int main(){
    vector<string> words = {"apple", "bat", "carrot", "dog"};
    cout << "Before sotring: ";
    printString(words);
    cout << endl << "After sorting: ";
    sortingArray(words);
    printString(words);
    


    return 0;
}