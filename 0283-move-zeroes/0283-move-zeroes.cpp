class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);

        int top = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) res[top++] = nums[i];
        }

        nums = res;
    }
};