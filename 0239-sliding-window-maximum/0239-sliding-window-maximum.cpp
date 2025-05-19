class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res(nums.size() - k + 1);

        int i = 0, j = 0;

        while (i < k){
            while (!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
            i++;
        }

        res[j++] = dq.front();

        while (i < nums.size()){
            if (nums[i - k] == dq.front()) dq.pop_front();
            while (!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);

            res[j++] = dq.front();
            i++;
        }

        return res;
    }
};