//(Q:9)-----------Merge and Sort Two Arrays-----------
/*
Problem: Merge two arrays and sort them.
Input:
a = [1, 16, 13, 14, 4]
b = [15, 12, 5, 3, 7]
Output: [1, 3, 4, 5, 7, 12, 13, 14, 15, 16]
*/

#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

vector<int> sortArray(vector<int>& vecA, vector<int>& vecB){
    vector<int> vecM;
    for(int i=0; i<vecA.size(); i++){
        vecM.push_back(vecA[i]);
    }
    for(int i=0; i<vecB.size(); i++){
        vecM.push_back(vecB[i]);
    }

    int n = vecM.size();
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (vecM[j] > vecM[j+1]) swap(vecM[j], vecM[j+1]);
        }
    }

    return vecM;
}


int main(){
    vector<int> vecA = {1,16,13,14,4};
    vector<int> vecB = {15,12,5,3,7};
    vector<int> vecMS = sortArray(vecA, vecB);
    for(int elements : vecMS) cout << elements << " ";



    return 0;
}