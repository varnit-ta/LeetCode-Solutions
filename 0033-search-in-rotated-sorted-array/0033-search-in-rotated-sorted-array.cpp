class Solution {
public:
    int binarySearch(int l, int r, int target, vector<int>& nums) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int chr = nums[mid];

            if (chr == target) {
                return mid;
            }

            if (chr < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int l = 0, r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        int pivot = l;

        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return binarySearch(pivot, n - 1, target, nums);
        } else {
            return binarySearch(0, pivot - 1, target, nums);
        }
    }
};
