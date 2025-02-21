class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& arr: matrix){
            auto it = lower_bound(arr.begin(), arr.end(), target);
            if (it != arr.end() && *it == target) return true;
        }

        return false;
    }
};