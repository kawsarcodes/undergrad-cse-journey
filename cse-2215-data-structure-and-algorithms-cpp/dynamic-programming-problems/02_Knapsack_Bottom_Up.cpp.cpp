/*
PROBLEM 01: 0/1 Knapsack (Top-Down Memoization)

The weights and values of n items are given. The items are distinct and non-divisible; you must either
take a whole item or leave it completely (0/1 choice). You have a knapsack to carry those items, whose
weight capacity is W. Due to the capacity limit of the knapsack, it might not be possible to carry all
the items at once. In that case, pick items such that the total profit is maximized.

Write a program that takes the weights and values of n items, and the capacity W of the knapsack from
the user and then finds the maximum profit using a top-down recursive strategy with memoization.

Sample Input
4 5
1 2 4 5
5 4 8 6

Sample Output
Maximum value = 13
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1001][1001];

int knapsackTopDown(int i, int w, const vector<int>& weight, const vector<int>& value) {
    if (i < 0 || w <= 0) {
        return 0;
    }

    if (dp[i][w] != -1) {
        return dp[i][w];
    }

    int notTake = knapsackTopDown(i - 1, w, weight, value);

    int take = 0;
    if (weight[i] <= w) {
        take = value[i] + knapsackTopDown(i - 1, w - weight[i], weight, value);
    }

    return dp[i][w] = max(notTake, take);
}

int main() {
    int n, W;
    if (!(cin >> n >> W)) return 0;

    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) cin >> weight[i];
    for (int i = 0; i < n; i++) cin >> value[i];

    memset(dp, -1, sizeof(dp));

    cout << "Maximum value = " 
         << knapsackTopDown(n - 1, W, weight, value) 
         << endl;

    return 0;
}