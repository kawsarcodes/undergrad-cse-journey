#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &vec)
{
   int n = vec.size();
   for (int i=0; i<n-1; i++){
    int minIdx = i;
    for (int j=i+1; j<n; j++){
        if(vec[j] < vec[minIdx]){
            minIdx = j;
        }
    }
    if (minIdx != i){
        swap(vec[i], vec[minIdx]);
    }
   }
}

void printVector(vector<int> &vec)
{
    for (int element : vec)
    {
        cout << element << " ";
    }
}

int main()
{
    vector<int> numbers = {50, 30, 10, 20, 70};
    cout << "Before sorting: ";
    printVector(numbers);
    cout << endl;
    selectionSort(numbers);
    cout << "After sorting: ";
    printVector(numbers);

    return 0;
}