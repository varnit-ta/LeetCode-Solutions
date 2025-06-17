class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;
        int n = coins.size();

        vector<int> prev(amount + 1, INF), curr(amount + 1, INF);
        prev[0] = curr[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                int notTake = prev[j];
                int take = INF;
                if (coins[i - 1] <= j && curr[j - coins[i - 1]] != INF)
                    take = curr[j - coins[i - 1]] + 1;

                curr[j] = min(take, notTake);
            }
            prev = curr;
        }

        return (prev[amount] == INF) ? -1 : prev[amount];
    }
};
