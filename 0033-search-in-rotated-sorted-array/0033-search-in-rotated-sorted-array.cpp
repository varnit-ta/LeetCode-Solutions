class Solution {
public:
    int search(vector<int>& nums, int target) {
        function<int(int, int)> check = [&](int left, int right){
            if (left <= right){
                int mid = (left + right)/2;

                if (nums[mid] == target){
                    return mid;
                }

                if (nums[left] <= nums[mid]){
                    if (target >= nums[left] && target < nums[mid]) return check(left, mid - 1);
                    else return check(mid + 1, right);
                }else{
                    if (target > nums[mid] && target <= nums[right]) return check(mid + 1, right);
                    else return check(left, mid - 1);
                }
            }

            return -1;
        };

        return check(0, nums.size() - 1);
    }
};