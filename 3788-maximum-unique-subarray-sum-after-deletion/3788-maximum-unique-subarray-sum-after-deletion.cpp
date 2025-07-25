class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxEl = nums[0], sm = 0;
        vector<bool> track(202, false);

        for (int i = 0; i < nums.size(); i++) {
            int el = nums[i];

            if (!track[el + 100]) {
                track[el + 100] = true;

                if (el >= 0)
                    sm += el;
            }

            maxEl = max(maxEl, el);
        }

        return sm == 0 ? maxEl : sm;
    }
};