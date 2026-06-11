//(Q:10)-----------Sort Tasks by Duration-----------
/*
Problem: Sort tasks based on duration (FinishTime - StartTime).
Input: [(2, 5), (1, 2), (4, 6)]
Durations:
(2, 5) -> 5-2 = 3
(1, 2) -> 2-1 = 1
(4, 6) -> 6-4 = 2

Sorted Order: 1, 2, 3
Output: [(1, 2), (4, 6), (2, 5)]
*/

#include<iostream>
#include<vector>
using namespace std;

struct Task{
    int start;
    int finish;
};

void sortTasksByDuration(vector<Task>& vec) {
    int n = vec.size();

    // Bubble Sort
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            
            int duration1 = vec[j].finish - vec[j].start;
            int duration2 = vec[j+1].finish - vec[j+1].start;

            if(duration1 > duration2) {
                swap(vec[j], vec[j+1]);
            }

            // if((vec[j].finish-vec[j].start) > (vec[j+1].finish-vec[j+1].start))
            //     swap(vec[j], vec[j+1]);
        }
    }
}

int main() {
    vector<Task> vec = { {2, 5}, {1, 2}, {4, 6} };

    cout << "Original Tasks: ";
    for(auto t : vec) cout << "(" << t.start << ", " << t.finish << ") ";
    cout << endl;

    sortTasksByDuration(vec);

    cout << "Sorted by Duration: ";
    for(auto t : vec) cout << "(" << t.start << ", " << t.finish << ") ";
    cout << endl;

    return 0;
}