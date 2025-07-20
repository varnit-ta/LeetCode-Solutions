class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        for (auto& s: shifts) {
            int l = s[0];
            int r = s[1];
            int d = s[2] ? 1 : -1;

            diff[l] += d;
            diff[r + 1] -= d;
        }

        for (int i = 0; i < n; i++){
            if (i != 0)
                diff[i] += diff[i - 1];

            s[i] = 'a' + (((s[i] - 'a') + diff[i]) % 26 + 26) % 26;
        }

        return s;
    }
};