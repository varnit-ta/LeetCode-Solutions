class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int right = *max_element(nums.begin(), nums.end());
        int num = -1;

        function<int(int)> divByNum = [&](int num){
            int sum = 0;
            for (auto el: nums) sum += ceil((double)(el) / (double)(num));
            return sum;
        };

        function<void(int, int)> binarySearch = [&](int left, int right){
            if (left <= right){
                int mid = (left + right)/2;

                if (divByNum(mid) <= threshold){
                    num = mid;
                    binarySearch(left, mid - 1);
                }else{
                    binarySearch(mid + 1, right);
                }
            }
        };

        binarySearch(1, right);
        return num;
    }
};