class Solution {
public:
    int uniquePaths(int m, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<vector<int>> matrix(m, vector<int>(n, 0));
        matrix[m-1][n-1] = 1;

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i < m-1) matrix[i][j] += matrix[i+1][j];
                if (j < n-1) matrix[i][j] += matrix[i][j+1];
            }
        }

        return matrix[0][0];
    }
};
