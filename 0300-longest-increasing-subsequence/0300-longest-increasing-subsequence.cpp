class Solution {
public:
    int LongestIncreasingSubsequence(vector<int>& arr){
        vector<int> tail;

        for(auto x: arr){
            auto it = lower_bound(tail.begin(), tail.end(), x);

            if (it == tail.end()){
                tail.push_back(x);
            }else{
                *it = x;
            }
        }

        return tail.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        return LongestIncreasingSubsequence(nums);
    }
};