class Solution(object):
    def minPathSum(self, grid):
        ROW, COL = len(grid), len(grid[0])

        res = [[float("inf")] * (COL + 1) for i in range(ROW + 1)]
        res[ROW][COL - 1] = 0

        for i in range(ROW-1, -1, -1):
            for j in range(COL-1, -1, -1):
                res[i][j] = grid[i][j] + min(res[i+1][j], res[i][j+1])

        return res[0][0]