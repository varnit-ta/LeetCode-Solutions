class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.size() == 0) return;

        vector<int> res(m + n, 0);
        int i = 0, j = 0, top = 0;

        while (i < m && j < n){
            if (nums1[i] == nums2[j]){
                res[top++] = nums1[i++];
                res[top++] = nums2[j++];
            }else if (nums1[i] < nums2[j]){
                res[top++] = nums1[i++];
            }else{
                res[top++] = nums2[j++];
            }
        }

        while (i < m){
            res[top++] = nums1[i++];
        }

        while (j < n){
            res[top++] = nums2[j++];
        }

        nums1 = res;
    }
};