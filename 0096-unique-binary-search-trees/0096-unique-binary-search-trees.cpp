class Solution {
public:
    vector<int> dp = vector<int>(20, 0);

    int numTrees(int n) {
        if (n <= 1) return 1;
        if (dp[n]) return dp[n];

        for (int i = 1; i <= n; i++){
            dp[n] += numTrees(i - 1) * numTrees(n - i);
        }

        return dp[n];
    }
};