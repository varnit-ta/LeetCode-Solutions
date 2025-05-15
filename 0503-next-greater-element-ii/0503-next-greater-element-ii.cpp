class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge(nums.size());
        stack<int> stk;

        for (int i = nums.size() - 1; i >= 0; i--){
            while (!stk.empty() && stk.top() <= nums[i]) stk.pop();

            if (stk.empty()) nge[i] = -1;
            else nge[i] = stk.top();

            stk.push(nums[i]);
        }

        for (int i = nums.size() - 1; i >= 0; i--){
            while (!stk.empty() && stk.top() <= nums[i]) stk.pop();

            if (stk.empty()) nge[i] = -1;
            else nge[i] = stk.top();

            stk.push(nums[i]);
        }

        return nge;
    }
};