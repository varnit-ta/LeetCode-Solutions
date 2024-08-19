class Solution {
public:
    int f(vector<int>&nums, int pos){
        if (pos >= nums.size()-1){
            return 0;
        }else if (pos + nums[pos] >= nums.size() - 1) {
            return 1;
        }else {
            int end = INT_MIN;
            int end_ind;

            cout << pos << " ";

            for (int i = pos+1; i <= pos + nums[pos] && i < nums.size(); i++) {
                if (end < i + nums[i]){
                    end = i + nums[i];
                    end_ind = i;
                }
            }

            return 1 + f(nums, end_ind);
        }
    }

    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        if (nums[0] >= nums.size() - 1) return 1;

        return f(nums, 0);
    }
};