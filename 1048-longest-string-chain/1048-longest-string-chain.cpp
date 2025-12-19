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
    bool checkPredecessor(string& a, string& b) {
        if (b.size() != a.size() + 1) return false;

        int i = 0, j = 0;
        while (j < b.size()) {
            if (i < a.size() && a[i] == b[j]) {
                i++; j++;
            } else {
                j++;
            }
        }

        return i == a.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(all(words), [](string a, string b){
            return a.size() < b.size();
        });

        int n = words.size();
        vi dp(n, 1);

        int mx = 1;

        FOR (i, 1, n){
            FOR (j, 0, i){
                if (checkPredecessor(words[j], words[i])){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            mx = max(mx, dp[i]);
        }

        return mx;
    }
};