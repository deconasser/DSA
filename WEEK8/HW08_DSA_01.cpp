#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value, weight;
    double ratio;

    Item(int value, int weight) : value(value), weight(weight) {
        ratio = (double)value / weight;
    }

    bool operator<(const Item& other) const {
        return ratio > other.ratio;
    }
};

int knapsackGreedy(int capacity, vector<int> &weights, vector<int> &values) {
    int n = values.size();
    vector<Item> items;

    for (int i = 0; i < n; ++i) {
        items.emplace_back(values[i], weights[i]);
    }

    sort(items.begin(), items.end());

    int totalValue = 0;
    for (auto &item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        }
    }

    return totalValue;
}

int main() {
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int capacity = 50;

    cout << "Approximate maximum value (Greedy): " << knapsackGreedy(capacity, weights, values) << endl;

    return 0;
}
