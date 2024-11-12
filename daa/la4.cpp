#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0-1 Knapsack problem using Dynamic Programming
int knapsack(int W, vector<int> &weights, vector<int> &values, int n) {
    // Create a 2D DP table to store the maximum value at each weight limit
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Maximize the value by either including or excluding the current item
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The bottom-right corner of the table contains the maximum value that can be obtained
    return dp[n][W];
}

int main() {
    int n, W;
    
    // Input number of items and knapsack capacity
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<int> weights(n), values(n);
    
    // Input the weights and values of the items
    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    cout << "Enter the values of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    // Call the knapsack function and output the result
    int max_value = knapsack(W, weights, values, n);
    cout << "The maximum value that can be obtained is: " << max_value << endl;

    return 0;
}
