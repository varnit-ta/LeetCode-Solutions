class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), totalSum = 0;

        for (auto& x: nums)
            totalSum += x;

        if (totalSum % 2 == 1)
            return false;
        
        totalSum /= 2;
        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (nums[0] <= totalSum)
            dp[0][nums[0]] = true;

        for (int ind = 1; ind < n; ind++){
            for (int target = 1; target <= totalSum; target++){
                bool notTake = dp[ind - 1][target];
                
                bool take = false;
                if (nums[ind] <= target)
                    take = dp[ind - 1][target - nums[ind]];

                dp[ind][target] = take || notTake;
            }
        }

        return dp[n-1][totalSum];
    }
};