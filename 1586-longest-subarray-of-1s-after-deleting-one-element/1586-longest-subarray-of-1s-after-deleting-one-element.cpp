class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, d = 0;
        int maxLen = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) d++;

            while (d > 1) {
                if (nums[l] == 0) d--;
                l++;
            }

            maxLen = max(maxLen, r - l);
        }

        return maxLen;
    }
};