class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));

        for(int i = 0; i < m+1; i++)
            dp[0][i] = i;

        for(int i = 0; i < n+1; i++)
            dp[i][0] = i;

        for (int i = 1; i < n+1; i++){
            for (int j = 1; j < m+1; j++){
                int cost = ((word1[i - 1] == word2[j - 1]) ? 0 : 1);

                dp[i][j] = min(
                    dp[i- 1][j] + 1,
                    min(
                        dp[i][j - 1] + 1,
                        dp[i - 1][j - 1] + cost
                    )
                );
            }
        }

        return dp[n][m];
    }
};