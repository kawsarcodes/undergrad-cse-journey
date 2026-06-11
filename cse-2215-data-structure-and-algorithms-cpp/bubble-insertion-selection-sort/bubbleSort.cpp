#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &vec){
   int n = vec.size();
   for (int i=0; i<n-1; i++){
    bool swapped = false;
    for (int j=0; j<n-i-1; j++){
        if(vec[j] > vec[j+1]){
            swap(vec[j], vec[j+1]);
            swapped = true;
        }
    }
    if(swapped == false){
        break;
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
    bubbleSort(numbers);
    cout << "After sorting: ";
    printVector(numbers);

    return 0;
}