class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        auto calc = [&](int start, int end) {
            int len = end - start + 1;
            if (len == 1) return nums[start];

            vector<int> dp(len);
            dp[0] = nums[start];
            dp[1] = max(nums[start], nums[start + 1]);

            for (int i = 2; i < len; ++i) {
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
            }

            return dp[len - 1];
        };

        return max(calc(0, n - 2), calc(1, n - 1));
    }
};
