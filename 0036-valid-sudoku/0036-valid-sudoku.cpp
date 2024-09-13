class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> rowTest(10, 0);
            vector<int> colTest(10, 0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (num < 1 || num > 9 || rowTest[num] != 0) {
                        return false;
                    }
                    rowTest[num] = 1;
                }
                
                if (board[j][i] != '.') {
                    int num = board[j][i] - '0';
                    if (num < 1 || num > 9 || colTest[num] != 0) {
                        return false;
                    }
                    colTest[num] = 1;
                }
            }
        }

        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                vector<int> boxTest(10, 0);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char cell = board[boxRow + i][boxCol + j];
                        if (cell != '.') {
                            int num = cell - '0';
                            if (num < 1 || num > 9 || boxTest[num] != 0) {
                                return false;
                            }
                            boxTest[num] = 1;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
