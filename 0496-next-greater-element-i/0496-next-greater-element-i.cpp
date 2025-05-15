class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        int nge[nums2.size()];

        for (int i = nums2.size() - 1; i >= 0; i--){
            while (!s.empty() && nums2[i] >= s.top()) s.pop();

            if (s.empty()) nge[i] = -1;
            else nge[i] = s.top();

            s.push(nums2[i]);
        }

        vector<int> res;

        for (auto el: nums1){
            int indx = find(nums2.begin(), nums2.end(), el) - nums2.begin();
            res.push_back(nge[indx]);
        }

        return res;
    }
};