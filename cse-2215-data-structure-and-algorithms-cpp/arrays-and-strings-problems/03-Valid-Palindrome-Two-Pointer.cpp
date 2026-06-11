/*
PROBLEM 03. Valid Palindrome (Two Pointer Approach)

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Sample input
A man, a plan, a canal: Panama

Sample output
1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    if (!getline(cin, s)) return 0;

    int left = 0, right = s.length() - 1;
    bool is_pal = true;

    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        if (tolower(s[left]) != tolower(s[right])) {
            is_pal = false;
            break;
        }
        left++;
        right--;
    }

    cout << is_pal << "\n";
    return 0;
}