class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        function<int(int, int, int)> binarySearch = [&](int left, int right, int target){
            if (left <= right){
                int mid = left + (right - left)/2;

                if (nums[mid] == target) return target;

                if (nums[mid] < target) return binarySearch(mid + 1, right, target);
                else return binarySearch(left, mid - 1, target);
            }else{
                return -1;
            }
        };

        for (int i = 0; i < n; i += 2){
            int res = binarySearch(i + 1, n - 1, nums[i]);
            if (res == -1) return nums[i];
        }

        return 0;
    }
};