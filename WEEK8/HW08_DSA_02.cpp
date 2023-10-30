#include<bits/stdc++.h>

using namespace std;

int knapsackDynamic(int capacity, vector<int> &weights, vector<int> &values) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int capacity = 50;

    cout << "Maximum value (Dynamic Programming): " << knapsackDynamic(capacity, weights, values) << endl;

    return 0;
}
