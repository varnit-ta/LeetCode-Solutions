int MOD = 1000000007;

class Solution {
public:
    int f(vector<long long>& dp, string& s, int k, int i){
        if (i == s.size())
            return 1;

        if (s[i] == '0')
            return 0;

        if (dp[i] != -1)
            return dp[i];

        long long num = 0;
        dp[i] = 0;

        for (int j = i; j < s.size(); j++) {
            num = num * 10 + (s[j] - '0');

            if (num <= k) {
                dp[i] = (dp[i] + f(dp, s, k, j+1)) % MOD;
            }else{
                break;
            }
        }

        return dp[i];
    }

    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<long long> dp(n+1, 0);
        dp[n] = 1;

        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '0')
                continue;

            long long num = 0;

            for (int j = i; j < n; j++) {
                num = num * 10 + (s[j] - '0');
                if (num > k) break;

                dp[i] = (dp[i] + dp[j+1]) % MOD;
            }
        }

        return dp[0];
    }
};