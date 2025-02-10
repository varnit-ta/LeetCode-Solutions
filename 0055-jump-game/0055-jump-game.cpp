class Solution {
public:
    bool canJump(vector<int>& nums) {
        int howFar = 0;
        int i = 0;

        while (i <= howFar && i < nums.size()){
            howFar = max(howFar, i + nums[i]);
            i++;
        }

        return (i == nums.size());
    }
};