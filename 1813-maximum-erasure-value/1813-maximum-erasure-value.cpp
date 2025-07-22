class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;

        int left = 0, n = nums.size();
        long long sm = 0, maxSm = 0;

        for (int right = 0; right < n; right++) {
            int el = nums[right];
            mp[el]++;
            sm += el;

            while (mp[el] > 1) {
                sm -= nums[left];
                mp[nums[left++]]--;
            }

            maxSm = max(sm, maxSm);
        }

        return maxSm;
    }
};