class Solution {
public:
    string makeFancyString(string s) {
        int c = 1;
        string res = s.substr(0, 1);

        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) c = 1;
            else c++;

            if (c < 3) res.push_back(s[i]);
        }

        return res;
    }
};