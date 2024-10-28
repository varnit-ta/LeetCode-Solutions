class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        function<int(int, int)> uppBound = [&](int left, int right) {
            if (left <= right) {
                int mid = left + (right - left) / 2;

                if (nums[mid] >= target) {
                    return uppBound(left, mid - 1);
                } else {
                    return uppBound(mid + 1, right);
                }
            } else {
                return right + 1;
            }
        };

        return uppBound(l, r);
    }
};