#ifdef LOCAL
#else
#define debug(...) 42
#endif

#define ll long long
#define pb emplace_back
#define F first
#define S second
#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORN(i, a, b) for (int i = a; i >= b; --i)
#define FORR(x, a) for (auto& x : a)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(all(nums));

        vi dp(n, 1), track(n, 0);
        int mx = 1, mxInd = 0;

        FOR(i, 0, n) track[i] = i;

        FOR(i, 1, n) {
            FOR(j, 0, i) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    track[i] = j;
                }
            }

            if (dp[i] > mx) {
                mx = dp[i];
                mxInd = i;
            }
        }

        vi arr;
        while (track[mxInd] != mxInd) {
            arr.pb(nums[mxInd]);
            mxInd = track[mxInd];
        }
        arr.pb(nums[mxInd]);

        return arr;
    }
};