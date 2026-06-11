/*
Q2:  The Perfectionist 

Alif is a perfectionist about numbers. He loves to arrange things in order and sticks to his 
“Golden rule” that every set of numbers must be in ascending order.  Unfortunately, that is not 
always the case. Alif defines that when a smaller number comes after a larger number in the set 
then number of violations are required to fix the order.  
Given a set of integers, Alif needs to find out the total number of such violations. 

Input: 
⮚ The first line contains n, the number of integers. 
⮚ The second line contains n space separated integers a0 … an-1 

Output: The output is an integer indicating the total number of violations.  

Bonus:  Time Complexity should be less than or equals to O(nlogn) 

Example: 

Sample Input: 
5 
4 5 6 7 1 
Sample Output: 4
Explanation: 1 violates which requires 4 violation to be fixed as 1 4 5 6 7. 

Sample Input: 
5 
5 4 3 2 1 
Sample Output: 10
Explanation: 
violates which requires 1 violation to be fixed as 4 5 3 2 1. 
Then again 3 violates which requires 2 violation to be fixed as 3 4 5 2 1. 
Then again 2 violates which requires 3 violation to be fixed as 2 3 4 5 1. 
Then again 1 violates which requires 4 violation to be fixed as 1 2 3 4 5. 
Total violations required = 1+2+3+4 =10

*/


#include <bits/stdc++.h>
using namespace std;

int mergeAndCount(vector<int> &arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;
  int count = 0;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      count = count + (n1 - i);
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

  return count;
}

int countViolations(vector<int> &arr, int left, int right) {
  int totalCount = 0;

  if (left < right) {
    int mid = left + (right - left) / 2;

    totalCount += countViolations(arr, left, mid);
    totalCount += countViolations(arr, mid + 1, right);
    totalCount += mergeAndCount(arr, left, mid, right);
  }

  return totalCount;
}

int main() {
  int n;
  cout << "Enter number of integers: ";
  cin >> n;

  if (n <= 0)
    return 0;

  vector<int> arr(n);
  cout << "Enter the numbers: " << endl;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int result = countViolations(arr, 0, n - 1);
  cout << result << endl;

  return 0;
}