class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, res = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (freq[nums[right]]++ == 0) k--;
            while (k < 0) {
                if (--freq[nums[left++]] == 0) k++;
            }
            res += right - left + 1;
        }

        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
