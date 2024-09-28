class Solution {
public:
    bool check(vector<int>& nums) {
        bool hasPivot = false;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++){
            if (nums[i] > nums[i+1] && !hasPivot){
                hasPivot = true;
            }
            else if (nums[i] > nums[i+1] && hasPivot){
                return false;
            }
        }

        if (hasPivot) return nums[0] >= nums[n - 1];
        return true;
    }
};