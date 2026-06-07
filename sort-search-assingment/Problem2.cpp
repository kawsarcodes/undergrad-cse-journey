/*
2. Sort odd indexed elements of an array in descending order and even indexed
elements in ascending order.
Input Output
a = [16,17,4,18,1,20,5,12] [1,20,4,18,5,17,16,12]
a = [4,3,2,1] [2,3 ,4,1]
*/

#include<iostream>
#include<vector>
using namespace std;

void sortArray(vector<int>& vec){
    vector<int> evenNumbers;
    vector<int> oddNumbers;

    int n = vec.size();
    for(int i=0; i<n; i++){
        if(i % 2 == 0) evenNumbers.push_back(vec[i]);
        else oddNumbers.push_back(vec[i]);
    }
    
    int nEven = evenNumbers.size();
    for(int i=0; i<nEven-1; i++){
        for(int j=0; j<nEven-i-1; j++){
            if(evenNumbers[j] > evenNumbers[j+1]){
                swap(evenNumbers[j], evenNumbers[j+1]);
            }
        }
    }

    int nOdd = oddNumbers.size();
    for(int i=0; i<nOdd-1; i++){
        for(int j=0; j<nOdd-i-1; j++){
            if(oddNumbers[j] < oddNumbers[j+1]){
                swap(oddNumbers[j], oddNumbers[j+1]);
            }
        }
    }

    int evenCount = 0, oddCount = 0;
    for(int i=0; i<n; i++){
        if(i % 2 == 0) vec[i] = evenNumbers[evenCount++];
        else vec[i] = oddNumbers[oddCount++];
    }
    
}

void printArray(vector<int>& vec){
    for(int elements : vec){
        cout << elements << " ";
    }
}


int main(){
    vector<int> numbers = {16,17,4,18,1,20,5,12};
    cout << "Before sorting: ";
    printArray(numbers);
    cout<< endl << "After sorting: ";
    sortArray(numbers);
    printArray(numbers);



    return 0;
}