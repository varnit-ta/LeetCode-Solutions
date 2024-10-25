class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorRes = nums[0];

        for (int i = 1; i < nums.size(); i++){
            xorRes ^= nums[i];
        }

        return xorRes;
    }
};