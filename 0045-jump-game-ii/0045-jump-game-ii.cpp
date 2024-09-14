#include <bits/stdc++.h>
#ifdef LOCAL
#else
#define debug(...) 42
#endif

#define ll long long
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define vii vector<vector<int>>
#define FOR(x, a, b) for (int x = a; x < b; x++)
#define FORR(x, arr) for (auto& x : arr)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        FOR(i, 0, n) {
            if (dp[i] == INT_MAX) continue;

            int maxReach = min(i + nums[i], n - 1);

            FOR(j, i + 1, maxReach + 1) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[n - 1];
    }
};