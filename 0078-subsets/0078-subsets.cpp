class Solution {
public:
    vector<vector<int>> res;

    void f(vector<int>& nums, vector<int>& arr, int index){
        res.push_back(arr);

        for (int i = index; i < nums.size(); i++){
            arr.push_back(nums[i]);
            f(nums, arr, i + 1);
            arr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr = {};
        f(nums, arr, 0);
        return res;
    }
};