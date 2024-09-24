class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v(1010, 0);
        vector<int> res;

        for (auto x: nums1){
            v[x]++;
        }

        for (auto x: nums2){
            if (v[x] >= 1) res.push_back(x);
            v[x]--;
        }

        return res;
    }
};