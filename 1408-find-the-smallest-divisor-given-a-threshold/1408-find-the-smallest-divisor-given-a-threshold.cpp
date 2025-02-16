class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int mid, sum_div, num = -1;

        while (left <= right) {
            mid = (left + right) / 2;

            sum_div = 0;
            for (auto el : nums) {
                sum_div += (el + mid - 1) / mid; 
            }

            if (sum_div <= threshold) {
                num = mid;  
                right = mid - 1;
            } else {
                left = mid + 1;  
            }
        }

        return num;
    }
};
