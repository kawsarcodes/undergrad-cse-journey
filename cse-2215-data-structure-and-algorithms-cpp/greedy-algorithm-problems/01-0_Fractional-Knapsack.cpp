/*
ALTERNATIVE QUESTION 01.1: Thieves in warehouse

There are n boxes of n different items in a warehouse. Each box has a label that says the name (m_i),
total weight (w_i) in kg and the total value (v_i) in taka of that item (i). All items are divisible. Suppose, k
thieves have come to steal from the warehouse, each with a knapsack of capacity W_i. Given each thief
wants to maximize his/her profit, how many thieves will be needed to empty the warehouse? Write a
code to solve this problem using a greedy algorithm.

Sample input
4
silver-dust 300 4
gold-dust 2000 8
salt 80 10
sugar 89 10
2
15 15

Sample output
Taking gold-dust: 8.0 kg 2000.0 taka
Taking silver-dust: 4.0 kg 300.0 taka
Taking sugar: 3.0 kg 26.7 taka
Thief 1 profit: 2326.7 taka
Taking sugar: 7.0 kg 62.3 taka
Taking salt: 8.0 kg 64.0 taka
Thief 2 profit: 126.3 taka
Total 2 thieves stole from the warehouse.
Still following items are left
 salt 2.0 kg 16.0 taka
*/

#include <bits/stdc++.h>
using namespace std;

struct Item {
    string name;
    double value;
    double weight;
    double ratio;
};

bool compareItems(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].name >> items[i].value >> items[i].weight;
        items[i].ratio = items[i].value / items[i].weight;
    }

    int k;
    cin >> k;
    vector<double> thieves(k);
    for (int i = 0; i < k; i++) {
        cin >> thieves[i];
    }

    sort(items.begin(), items.end(), compareItems);

    int currentItemIdx = 0;
    int thievesUsed = 0;

    for (int i = 0; i < k; i++) {
        if (currentItemIdx >= n) break;
        
        double capacityLeft = thieves[i];
        double thiefProfit = 0;
        thievesUsed++;
        
        while (capacityLeft > 0 && currentItemIdx < n) {
            Item& curr = items[currentItemIdx];
            if (curr.weight <= 0) {
                currentItemIdx++;
                continue;
            }

            double takeWeight = min(capacityLeft, curr.weight);
            double takeValue = takeWeight * curr.ratio;

            cout << "Taking " << curr.name << ": " << fixed << setprecision(1) 
                 << takeWeight << " kg " << takeValue << " taka\n";

            capacityLeft -= takeWeight;
            curr.weight -= takeWeight;
            curr.value -= takeValue;
            thiefProfit += takeValue;

            if (curr.weight <= 0) {
                currentItemIdx++;
            }
        }
        cout << "Thief " << i + 1 << " profit: " << fixed << setprecision(1) << thiefProfit << " taka\n";
    }

    cout << "Total " << thievesUsed << " thieves stole from the warehouse.\n";

    bool leftOver = false;
    for (int i = currentItemIdx; i < n; i++) {
        if (items[i].weight > 0) {
            if (!leftOver) {
                cout << "Still following items are left\n";
                leftOver = true;
            }
            cout << " " << items[i].name << " " << fixed << setprecision(1) 
                 << items[i].weight << " kg " << items[i].value << " taka\n";
        }
    }

    return 0;
}