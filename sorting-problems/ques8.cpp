//(Q:8)-----------Sort by Frequency-----------
/*
Problem: Sort an array based on frequency. 
If frequencies are same, sort by value (ascending).
Input: a = [4, 3, 1, 6, 1, 3, 4, 4]
Output: [4, 4, 4, 1, 1, 3, 3, 6]
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

// A helper structure to store a number and its count
struct Element {
    int value;
    int freq;
};

void sortByFrequency(vector<int>& arr) {
    map<int, int> counts;

    for(int x : arr) {
        counts[x]++;
    }

    vector<Element> elements;
    for(auto const& [val, count] : counts) {
        elements.push_back({val, count});
    }

    int n = elements.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            
            bool swapNeeded = false;

            if(elements[j].freq < elements[j+1].freq) {
                swapNeeded = true;
            }

            else if(elements[j].freq == elements[j+1].freq) {
                if(elements[j].value > elements[j+1].value) {
                    swapNeeded = true;
                }
            }

            if(swapNeeded) {
                Element temp = elements[j];
                elements[j] = elements[j+1];
                elements[j+1] = temp;
            }
        }
    }

    int index = 0;
    for(auto e : elements) {
        for(int k = 0; k < e.freq; k++) {
            arr[index++] = e.value;
        }
    }
}

int main() {
    vector<int> arr = {4, 3, 1, 6, 1, 3, 4, 4};

    cout << "Original: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    sortByFrequency(arr);

    cout << "Sorted:   ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}