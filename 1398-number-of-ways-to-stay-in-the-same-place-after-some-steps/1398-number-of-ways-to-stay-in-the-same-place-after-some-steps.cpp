class Solution {
public:
    const int MOD = 1000000007;

    int check(vector<vector<int>>& dp, int maxPos, int indx, int steps) {
        if (indx == 0 && steps == 0) 
            return 1;

        if (indx < 0 || indx > maxPos || steps == 0)
            return 0;

        if (dp[indx][steps] != -1)
            return dp[indx][steps];

        long long stay  = check(dp, maxPos, indx, steps - 1);
        long long left  = check(dp, maxPos, indx - 1, steps - 1);
        long long right = check(dp, maxPos, indx + 1, steps - 1);

        return dp[indx][steps] = ( (stay + left) % MOD + right ) % MOD;
    }

    int numWays(int steps, int arrLen) {
        int maxPos = min(arrLen - 1, steps);
        vector<vector<int>> dp(maxPos + 1, vector<int>(steps + 1, -1));
        return check(dp, maxPos, 0, steps);
    }
};
