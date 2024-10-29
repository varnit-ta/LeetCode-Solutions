class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        if (r == 0) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[r] != nums[r - 1]) return nums[r];

        function<int(int, int)> check = [&](int left, int right){
            if (left <= right){
                int mid = (left + right) / 2;

                if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]){
                    return nums[mid];
                }

                return check(left, mid - 1) + check(mid + 1, right);
            }

            return 0;
        };

        return check(l, r);
    }
};