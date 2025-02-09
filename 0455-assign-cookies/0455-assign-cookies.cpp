class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int mx = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] >= g[mx]) mx++;
            if (mx == g.size()) break;
        }

        return mx;
    }
};