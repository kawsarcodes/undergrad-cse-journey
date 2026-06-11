/*
PROBLEM 02: 0/1 Knapsack (Bottom-Up Tabulation)

The weights and values of n items are given. The items are distinct and non-divisible; you must either
take a whole item or leave it completely (0/1 choice). You have a knapsack to carry those items, whose
weight capacity is W. Due to the capacity limit of the knapsack, it might not be possible to carry all
the items at once. In that case, pick items such that the total profit is maximized.

Write a program that takes the weights and values of n items, and the capacity W of the knapsack from
the user and then finds the maximum profit by iteratively filling a 2D table using a bottom-up dynamic
programming approach.

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
using namespace std;

int knapsackBottomUp(vector<int>& weight, vector<int>& value, int W, int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int w = 0; w <= W; w++) {
        if (weight[0] <= w) {
            dp[0][w] = value[0];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int notTake = dp[i-1][w];
            int take = 0;
            if (weight[i] <= w) {
                take = value[i] + dp[i-1][w - weight[i]];
            }
            dp[i][w] = max(notTake, take);
        }
    }

    return dp[n - 1][W];
}

int main()
{
    int n, W;
    if (!(cin >> n >> W)) return 0;

    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) cin >> weight[i];
    for (int i = 0; i < n; i++) cin >> value[i];

    cout << "Maximum value = "
         << knapsackBottomUp(weight, value, W, n)
         << endl;

    return 0;
}