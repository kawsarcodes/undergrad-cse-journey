/*
1. Sort an Array of Strings according to length. If length of the two strings are equal, sort them
alphabetically
Input Output
a = ["apple", "bat", "carrot", "dog"] ["bat", "dog", "apple", "carrot"]s
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void sortStrng(vector<string>& vec){
    int n = vec.size();
    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0; j<n-i-1; j++){
            if(vec[j].length() > vec[j+1].length()){
                swap(vec[j], vec[j+1]);
                swapped = true;
            }
            else if(vec[j].length() == vec[j+1].length()){
                if(vec[j] > vec[j+1]){
                    swap(vec[j], vec[j+1]);
                    swapped = true;
                }
            }
        }
        if(swapped == false){
            break;
        }
    }
}

void printString(vector<string>& vec){
    for(string elements : vec){
        cout << elements << " ";
    }
}


int main(){
    vector<string> words = {"apple", "bat", "carrot", "dog"};
    cout << "Before sorting: ";
    printString(words);
    cout<< endl << "After sorting: ";
    sortStrng(words);
    printString(words);




    return 0;
}