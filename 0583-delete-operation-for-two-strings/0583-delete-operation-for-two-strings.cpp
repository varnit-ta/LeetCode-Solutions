class Solution {
public:
    int longestCommonSubseq(string& word1, string& word2){
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for (int i = 1; i <= n2; i++){
            for (int j = 1; j <= n1; j++){
                if (word1[j-1] == word2[i-1])
                    dp[j][i] = 1 + dp[j-1][i-1];
                else
                    dp[j][i] = max(dp[j-1][i], dp[j][i-1]);
            }
        } 

        return dp[n1][n2];
    }

    int minDistance(string word1, string word2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        return word1.size() + word2.size() - 2 * longestCommonSubseq(word1, word2);
    }
};