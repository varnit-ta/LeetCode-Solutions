class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int mid, num = -1;

        function<int(int)> divByNum = [&](int num){
            int sum = 0;
            for (auto el: nums) sum += ceil((double)(el) / (double)(num));
            return sum;
        };

        while (left <= right){
            mid = (left + right)/2;

            if (divByNum(mid) <= threshold){
                num = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return num;
    }
};