class Solution {
public:
    int solve(vector<int>& arr){
        stack<int> stk;
        int mx = 0;
        int n = arr.size();

        for (int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : arr[i];

            while (!stk.empty() && arr[stk.top()] > curr) {
                int height = arr[stk.top()];
                stk.pop();

                int width = stk.empty() ? i : i - stk.top() - 1;
                mx = max(mx, height * width);
            }
            stk.push(i);
        }

        return mx;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> mat(rows, vector<int>(cols, 0));

        for (int j = 0; j < cols; j++) {
            mat[0][j] = (matrix[0][j] == '1') ? 1 : 0;
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = (matrix[i][j] == '1') ? mat[i - 1][j] + 1 : 0;
            }
        }

        int mx = 0;
        for (auto& row : mat) {
            mx = max(mx, solve(row));
        }

        return mx;
    }
};
