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
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;

        for (int x: nums){
            auto it = lower_bound(all(arr), x);

            if (it == arr.end()) arr.pb(x);
            else *it = x;
        }

        return arr.size();
    }
};