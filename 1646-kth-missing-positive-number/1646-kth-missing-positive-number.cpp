class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int missingNums;

        int left = 0, right = n - 1, mid;

        while (left <= right){
            mid = (left + right)/2;
            missingNums = arr[mid] - (mid + 1);

            if (missingNums < k){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return k + right + 1;;
    }
};