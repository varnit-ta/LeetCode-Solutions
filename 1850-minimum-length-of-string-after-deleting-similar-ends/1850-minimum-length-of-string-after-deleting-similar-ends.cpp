class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        if (s[0] != s[n-1] || s.size() == 1) return s.size();

        int i = 0, j = n-1;
        char currEl = s[0];

        while (i <= j) {
            while (i <= j && s[i] == currEl) i++;
            while (i <= j && s[j] == currEl) j--;

            if (i != j && s[i] == s[j]) currEl = s[i];
            else break;
        }

        if (i > j) return 0;
        return j - i + 1;
    }
};