class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(256, -1);
        int maxLen = 0, start = 0;

        for (int i = 0; i < s.length(); i++) {
            if (charIndex[s[i]] >= start) {
                start = charIndex[s[i]] + 1;
            }
            charIndex[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};