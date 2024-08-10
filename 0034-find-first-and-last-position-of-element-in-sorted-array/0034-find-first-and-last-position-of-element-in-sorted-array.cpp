class Solution {
public:
    int bSearch(vector<int>& nums, int l, int r, int target) {
        if (l <= r) {
            int mid = l + (r - l) / 2; 

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] > target) {
                return bSearch(nums, l, mid - 1, target);
            }

            return bSearch(nums, mid + 1, r, target);
        }

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};

        int i = bSearch(nums, 0, nums.size() - 1, target);

        if (i == -1) {
            return res;
        }

        int start = i, end = i;

        while (start > 0 && nums[start - 1] == target) {
            start--; 
        }

        while (end < nums.size() - 1 && nums[end + 1] == target) {
            end++; 
        }

        res = {start, end};
        return res;
    }
};
