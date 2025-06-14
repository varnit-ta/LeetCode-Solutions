class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int n = nums.size();
        vector<int> dp(nums.begin(), nums.end());

        for (int i = 2; i < nums.size(); i++) 
            dp[i] += max(dp[i - 2], dp[i - 1] - nums[i - 1]);
        
        return max(dp[n -1], dp[n - 2]);
    }
};