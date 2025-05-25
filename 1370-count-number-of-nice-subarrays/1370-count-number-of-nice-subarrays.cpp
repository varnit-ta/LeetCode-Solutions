class Solution {
public:
    int check(vector<int>& nums, int k){
        if (k == -1) return 0;

        int count = 0, total = 0, left = 0;

        for (int right = 0; right < nums.size(); right++){
            total += ((nums[right] % 2 == 0) ? 0 : 1);
            while (total > k) total -= ((nums[left++] % 2 == 0) ? 0 : 1);
            count += (right - left + 1);
        }

        return count;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        return check(nums, k) - check(nums, k-1);
    }
};