class Solution {
public:
    int findMin(vector<int>& nums) {
        function<int(int, int)> check = [&](int left, int right) {
            if (left <= right) {
                int mid = (left + right) / 2;

                if (mid == 0 || nums[mid] < nums[mid - 1]) {
                    if (mid == nums.size() - 1 || nums[mid] < nums[mid + 1]) {
                        return nums[mid];
                    }
                }

                if (nums[mid] >= nums[left] && nums[mid] > nums[right]) {
                    return check(mid + 1, right);
                } else {
                    return check(left, mid - 1);
                }
            }

            return nums[0];
        };

        return check(0, nums.size() - 1);
    }
};
