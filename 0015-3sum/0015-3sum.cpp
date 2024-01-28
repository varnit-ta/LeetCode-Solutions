class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> sum;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++){
            int p = i+1;
            int q = nums.size()-1;

            while (p < q){
                int dummySum = nums[i] + nums[q] + nums[p];
                if (dummySum == 0){
                    sum.insert({nums[i], nums[p], nums[q]});
                    p++;
                    q--;
                }else if (dummySum < 0){
                    p++;
                }else{
                    q--;
                }
            }
        }

        for (auto n : sum){
            result.push_back(n);
        }

        return result;
    }
};