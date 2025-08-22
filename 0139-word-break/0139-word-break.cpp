class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 0; i < s.size(); i++) {
            if (!dp[i]) continue;

            for (int j = i; j < s.size(); j++) {
                string word = s.substr(i, j - i + 1);
                
                if (st.find(word) != st.end()) {
                    dp[j + 1] = true;
                }
            }
        }

        return dp[s.size()];
    }
};
