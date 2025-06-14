class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int n = nums.size();
        vector<int> dp(nums.begin(), nums.end());
        dp[1] = max(dp[0], dp[1]);

        for (int i = 2; i < nums.size(); i++) 
            dp[i] = max(dp[i -1], dp[i-2] + nums[i]);
        
        return dp[n-1];
    }
};