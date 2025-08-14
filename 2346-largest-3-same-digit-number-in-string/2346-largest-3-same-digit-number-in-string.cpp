class Solution {
public:
    string largestGoodInteger(string s) {
        int n = s.size();
        string res;

        for (int i = 0; i < n-2; i++) {
            if (!res.empty() && res[0] == s[i]) continue;

            if (s[i] == s[i+1] && s[i] == s[i+2]) {
                string triplet = s.substr(i, 3);

                if (res.empty() || res < triplet)
                    res = triplet;

                i += 2;
            }
        }

        return res;
    }
};