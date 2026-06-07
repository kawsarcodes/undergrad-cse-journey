//(Q:6)-----------odd descending, even ascending-----------
/*
ort odd indexed elements of an array in descending order and
even indexed elements in ascending order.

Input: a = [16,17,4,18,1,20,5,12]
Output: [1,20,4,18,5,17,16,12]
*/
#include<iostream>
#include<vector>
using namespace std;

void sortArray(vector<int>& vec){
    vector<int> evenNumbers;
    vector<int> oddNubmers;

    int n = vec.size();
    for (int i=0; i<n; i++){
        if(i % 2 == 0) evenNumbers.push_back(vec[i]);
        else oddNubmers.push_back(vec[i]);
    }

    int nEven = evenNumbers.size();
    for (int i=0; i<nEven-1; i++){
        for (int j=0; j<nEven-i-1; j++){
            if (evenNumbers[j] > evenNumbers[j+1]) swap(evenNumbers[j], evenNumbers[j+1]);
        }
    }

    int nOdd = oddNubmers.size();
    for (int i=0; i<nOdd-1; i++){
        for (int j=0; j<nOdd-i-1; j++){
            if (oddNubmers[j] < oddNubmers[j+1]) swap(oddNubmers[j], oddNubmers[j+1]);
        }
    }

    int evenCount=0, oddCount=0;
    for (int i=0; i<n; i++){
        if(i % 2 == 0) vec[i] = evenNumbers[evenCount++];
        else vec[i] = oddNubmers[oddCount++];
    }
}

void printArray(vector<int>& vec){
    for (int elements : vec) cout << elements << " ";
}

int main(){
    vector<int> numbers = {16,17,4,18,1,20,5,12};
    cout << "Before sort: ";
    printArray(numbers);
    cout << endl << "After sort: ";
    sortArray(numbers);
    printArray(numbers);




    return 0;
}