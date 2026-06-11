/*
Problem(1.1): Thieves in warehouse

Determine how many thieves out of k are needed to empty a warehouse of divisible items.
File Name: ques1_1-THIEVES-IN-WAREHOUSE.cpp
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