class Solution {
public:
    int findMin(vector<int>& nums) {
        function<int(int, int)> check = [&](int left, int right) {
            if (left <= right) {
                int mid = (left + right) / 2;

                // Check if mid is the minimum element
                if (mid == 0 || nums[mid] < nums[mid - 1]) {
                    if (mid == nums.size() - 1 || nums[mid] < nums[mid + 1]) {
                        return nums[mid];
                    }
                }

                // Decide which half to search
                if (nums[mid] >= nums[left] && nums[mid] > nums[right]) {
                    return check(mid + 1, right);  // Search right
                } else {
                    return check(left, mid - 1);  // Search left
                }
            }

            return nums[0];  // Fallback in case the array is not rotated
        };

        return check(0, nums.size() - 1);
    }
};
