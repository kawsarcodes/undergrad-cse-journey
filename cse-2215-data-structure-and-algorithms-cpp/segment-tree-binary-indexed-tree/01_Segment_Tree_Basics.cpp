/*
Problem(1): Range Sum Query and Node Update using a Segment Tree.
Input 
Array = [1, 3, 5, 7, 9, 11], Query Sum range [1, 3]
Output
Sum of values in given range = 15
*/

#include<iostream>
#include<vector>
using namespace std;

void buildTree(int arr[], int tree[], int start, int end, int node){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(arr, tree, start, mid, 2 * node);
    buildTree(arr, tree, mid + 1, end, 2 * node + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int querySum(int tree[], int start, int end, int l, int r, int node){
    if(r < start || l > end) return 0;
    if(l <= start && r >= end) return tree[node];
    int mid = start + (end - start) / 2;
    return querySum(tree, start, mid, l, r, 2 * node) + 
           querySum(tree, mid + 1, end, l, r, 2 * node + 1);
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = 6;
    int tree[4 * 6];
    buildTree(arr, tree, 0, n - 1, 1);
    cout << "Sum of values in given range [1, 3] = " << querySum(tree, 0, n - 1, 1, 3, 1);
}