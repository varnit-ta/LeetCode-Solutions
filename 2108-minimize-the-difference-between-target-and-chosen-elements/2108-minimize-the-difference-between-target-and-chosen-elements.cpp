class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(5000, -1));

        function<int(int, int)> f = [&](int r, int currSum){
            if (r == m) return abs(currSum - target);
            if (dp[r][currSum] != -1) return dp[r][currSum];

            int mini = INT_MAX;

            for (int i = 0; i < n; i++){
                int sum = f(r + 1, currSum + mat[r][i]);
                mini = min(mini, sum);
            }

            return dp[r][currSum] = mini;
        };

        return f(0, 0);
    }
};