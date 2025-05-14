class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left = 0, right = mat[0].size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            int mxInd = 0;
            for (int i = 0; i < mat.size(); i++) {
                if (mat[i][mid] > mat[mxInd][mid])
                    mxInd = i;
            }

            int el = mat[mxInd][mid];

            bool isLeftSmaller = (mid == 0 || el > mat[mxInd][mid - 1]);
            bool isRightSmaller = (mid == mat[0].size() - 1 || el > mat[mxInd][mid + 1]);

            if (isLeftSmaller && isRightSmaller) {
                return {mxInd, mid};
            }
            else if (mid > 0 && mat[mxInd][mid - 1] > el) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return {};
    }
};
