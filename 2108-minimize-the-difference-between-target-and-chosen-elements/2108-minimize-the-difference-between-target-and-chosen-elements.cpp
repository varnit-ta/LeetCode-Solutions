class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        const int MAX_SUM = 4900;

        vector<vector<int>> dp(m, vector<int>(MAX_SUM + 1, -1));

        function<int(int, int)> f = [&](int r, int currSum){
            if (currSum > MAX_SUM) return INT_MAX; // prune unbounded growth
            if (r == m) return abs(currSum - target);
            if (dp[r][currSum] != -1) return dp[r][currSum];

            int mini = INT_MAX;
            for (int i = 0; i < n; i++){
                mini = min(mini, f(r + 1, currSum + mat[r][i]));
            }

            return dp[r][currSum] = mini;
        };

        return f(0, 0);
    }
};
