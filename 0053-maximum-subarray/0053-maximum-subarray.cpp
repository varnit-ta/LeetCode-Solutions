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
    int maxSubArray(vi& nums) {
        int n = nums.size();
        int mx = nums[0];

        vi dp(n, INT_MIN);
        dp[0] = nums[0];

        FOR(i, 1, n){
            int dp_next = nums[i] + dp[i-1];

            if (dp_next < nums[i]) dp[i] = nums[i];
            else dp[i] = dp_next;

            mx = max(mx, dp[i]);
        }

        return mx;
    }
};