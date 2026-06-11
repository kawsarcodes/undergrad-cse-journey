/*
PROBLEM 03. Greedy Coin Change

Consider the problem of making change for N cents using the fewest number of coins. Assume that each
coin's value is an integer and there are an infinite number of coins for each coin type. Write a greedy
algorithm to make change consisting of coins.

Sample input
173
4
10 1 25 5

Sample output
25 cents --- 6
10 cents --- 2
1 cents --- 3
Total 11 coins
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    int d;
    if (cin >> d) {
        vector<int> coins(d);
        for (int i = 0; i < d; i++) {
            cin >> coins[i];
        }

        sort(coins.begin(), coins.end(), greater<int>());

        int totalCoins = 0;
        for (int i = 0; i < d; i++) {
            if (n <= 0) break;
            int count = n / coins[i];
            if (count > 0) {
                cout << coins[i] << " cents --- " << count << "\n";
                totalCoins += count;
                n %= coins[i];
            }
        }
        cout << "Total " << totalCoins << " coins\n";
    }
    return 0;
}