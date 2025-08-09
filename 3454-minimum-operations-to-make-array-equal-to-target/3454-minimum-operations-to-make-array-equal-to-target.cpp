class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long res = 0;
        int pre = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            res += max(target[i] - nums[i] - pre, 0);
            pre = target[i] - nums[i];
        }

        res += max(-pre, 0);
        return res;
    }
};