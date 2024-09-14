#define ll long long
#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define vii vector<vector<int>>
#define FOR(x, a, b) for (int x = a; x < b; x++)
#define FORR(x, arr) for (auto& x : arr)

class Solution {
public:
    int maxSubArray(vi& nums) {
        int n = nums.size();
        int current_sum = nums[0];
        int max_sum = nums[0]; 

        FOR(i, 1, n){
            current_sum = max(nums[i], current_sum + nums[i]);
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};
