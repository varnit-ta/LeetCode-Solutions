class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;

        int count = 1, el = nums[0], n = nums.size();

        for (int i = 1; i < n; i++){
            if (el == nums[i]){
                count++;
            }else{
                if (count > floor(n/3)) res.push_back(el);
                el = nums[i]; count = 1;
            }
        }
        if (count > floor(n/3)) res.push_back(el);

        return res;
    }
};