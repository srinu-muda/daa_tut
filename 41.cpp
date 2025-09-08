#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Item {
    int value, weight;
    double ratio;
};
bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}
int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;
    vector<Item> items(n);
    cout << "Enter value and weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    sort(items.begin(), items.end(), cmp);
    double totalProfit = 0.0;
    int remainingCapacity = W;
    for (int i = 0; i < n && remainingCapacity > 0; i++) {
        if (items[i].weight <= remainingCapacity) {
            totalProfit += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            totalProfit += items[i].ratio * remainingCapacity;
            remainingCapacity = 0;
        }
    }
    cout << "Maximum profit = " << totalProfit << endl;
    return 0;
}
