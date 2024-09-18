#define pb push_back
#define F first
#define S second
#define vi vector<int>
#define vii vector<vector<int>>
#define FOR(x, a, b) for (int x = a; x < b; x++)
#define FORR(x, arr) for (auto& x : arr)

using namespace std;

class Solution {
public:
    vector<vector<string>> res;

    bool isValid(vector<string>& board, int rows, int cols, int n){
        for (int i = 0; i < n; i++){if (board[i][cols] == 'Q') return false;}
        for (int i = rows, j = cols; i >= 0 && j >= 0; --i, --j){ if (board[i][j] == 'Q') return false;}
        for (int i = rows, j = cols; i >= 0 && j < n; --i, ++j){ if (board[i][j] == 'Q') return false;}
        return true;
    }

    void f(vector<string>& board, int rows, int n){
        if (rows == n) res.push_back(board);

        FOR(i, 0, n){
            if (isValid(board, rows, i, n)){
                board[rows][i] = 'Q';
                f(board, rows + 1, n);
                board[rows][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if(n <= 0) return {{}};
        
        vector<string> board(n, string(n, '.'));
        f(board, 0, n);
        return res;
    }
};