class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int l = 0, r = cols - 1;
        int u = 0, d = rows - 1;
        
        while (l <= r && u <= d) {
            for (int j = l; j <= r; ++j) {
                res.push_back(matrix[u][j]);
                cout << matrix[u][j] << " ";
            }
            ++u;

            for (int i = u; i <= d; ++i) {
                res.push_back(matrix[i][r]);
                cout << matrix[i][r] << " ";
            }
            --r;

            if (u <= d) {
                for (int j = r; j >= l; --j) {
                    res.push_back(matrix[d][j]);
                    cout << matrix[d][j] << " ";
                }
                --d;
            }

            if (l <= r) {
                for (int i = d; i >= u; --i) {
                    res.push_back(matrix[i][l]);
                    cout << matrix[i][l] << " ";
                }
                ++l;
            }
        }

        return res;
    }
};
