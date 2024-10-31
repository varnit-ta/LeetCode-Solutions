class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return (n - 1);

        int ind = 0;

        function<void(int, int)> check = [&](int left, int right) {
            if (left <= right) {
                int mid = (left + right) / 2;

                if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]){
                    ind = mid;
                    return;
                }

                check(left, mid - 1);
                check(mid + 1, right);
            }

            return;
        };

        check(1, n - 2);
        return ind;
    }
};