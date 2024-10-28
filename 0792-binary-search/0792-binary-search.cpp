class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        function<int(int, int)> binarySearch = [&](int left, int right) -> int {
            if (left <= right) {
                int mid = left + (right - left) / 2;

                if (nums[mid] == target) return mid;

                if (nums[mid] < target) {
                    return binarySearch(mid + 1, right);
                } else {
                    return binarySearch(left, mid - 1);
                }
            } else {
                return -1;
            }
        };

        return binarySearch(l, r);
    }
};
