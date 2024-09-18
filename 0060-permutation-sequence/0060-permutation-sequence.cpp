#include <bits/stdc++.h>
#ifdef LOCAL
#include <algo/debug.h>
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
    vector<string> res;

    void f(vector<char>& s, int k, string& str){
        if (str.size() == s.size()) {
            res.push_back(str);
            return;
        }
        if (res.size() >= k) return;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') continue;

            char chr = s[i];
            s[i] = '0';
            str += chr;
            f(s, k, str);
            s[i] = chr;
            str.pop_back();
        }
    }

    string getPermutation(int n, int k) {
        vector<char> s;
        FOR(i, 1, n+1){
            s.push_back(i + '0');
        }

        string str;
        f(s, k, str);

        return res[k - 1];
    }
};