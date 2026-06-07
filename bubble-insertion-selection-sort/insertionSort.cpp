#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 1; i < n; i++)
    {
        int key = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j = j - 1;
        }

        vec[j + 1] = key;
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
    insertionSort(numbers);
    cout << "After sorting: ";
    printVector(numbers);

    return 0;
}