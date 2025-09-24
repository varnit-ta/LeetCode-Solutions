class Solution {
public:
    vector<vector<int>> res;

    void f(vector<int>& arr, int n, int k, int sm, int lst) {
        if (arr.size() == k){
            if (n == sm) res.push_back(arr);
            return;
        }

        for (int i = lst + 1; i <= 9; i++) {
            arr.push_back(i);
            f(arr, n, k, sm + i, i);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        f(arr, n, k, 0, 0);
        return res;
    }
};