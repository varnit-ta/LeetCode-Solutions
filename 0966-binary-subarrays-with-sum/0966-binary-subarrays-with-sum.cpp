class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<long long, int> mp;
        int count = 0, sum = 0;

        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (sum == goal) count++;
            count += mp[sum - goal];
            mp[sum]++;
        }

        return count;
    }
};