class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9;
        vector<vector<int>> dp(n, vector<int>(amount + 1, INF));

        // Base Case Initialization:
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0)
                dp[0][t] = t / coins[0];
        }

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                int notTake = dp[i - 1][t];
                int take = INF;
                if (coins[i] <= t)
                    take = 1 + dp[i][t - coins[i]]; // use same coin again
                dp[i][t] = min(take, notTake);
            }
        }

        return dp[n - 1][amount] == INF ? -1 : dp[n - 1][amount];
    }
};
