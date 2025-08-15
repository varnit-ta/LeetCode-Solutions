class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> nums = {1, 1};

        while (nums[nums.size() - 1] + nums[nums.size() - 2] <= k) 
            nums.push_back(nums[nums.size() - 1] + nums[nums.size() - 2]);

        int count = 0, indx = nums.size() - 1;

        while (indx >= 0 && k > 0) {
            if (nums[indx] <= k) {
                count += k/nums[indx];
                k %= nums[indx];
            }

            indx--;
        }

        return count;
    }
};