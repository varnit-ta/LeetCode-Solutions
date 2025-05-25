class Solution {
public:
    int helperFunction(vector<int>& nums, int goal){
        if (goal == -1) return 0;

        int count = 0, left = 0, total = 0;

        for (int right = 0; right < nums.size(); right++){
            total += nums[right];
            while (total > goal) total -= nums[left++];
            count += (right - left + 1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helperFunction(nums, goal) - helperFunction(nums, goal - 1);
    }
};