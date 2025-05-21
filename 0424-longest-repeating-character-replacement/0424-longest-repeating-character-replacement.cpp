class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(26, 0);
        int left = 0, maxLen = 0, maxFreq = 0;

        for (int right = 0; right < s.length(); right++){
            mp[s[right] - 'A']++;
            maxFreq = max(maxFreq, mp[s[right] - 'A']);

            if ((right - left + 1) - maxFreq <= k){
                maxLen = max(maxLen, right - left + 1);
            }else{
                mp[s[left] - 'A']--;
                left++;
            }
        }

        return maxLen;
    }
};