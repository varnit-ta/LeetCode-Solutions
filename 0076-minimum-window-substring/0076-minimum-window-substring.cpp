class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> freq;
        for (char ch : t) freq[ch]++;

        int left = 0, minLen = INT_MAX, start = 0;
        int required = t.size();

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] > 0) required--;
            freq[s[right]]--;

            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;
                if (freq[s[left]] > 0) required++;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
