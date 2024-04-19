class Solution(object):
    def numIslands(self, grid):
        def traverse(loc):
            grid[loc[0]][loc[1]] = "0"
            pos = [(0, 1), (0, -1), (1, 0), (-1, 0)]

            for k in pos:
                x = loc[0] + k[0]
                y = loc[1] + k[1]
                
                if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y] == "1":
                    grid[x][y] = "0"
                    traverse((x, y))
        
        total_island = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    total_island += 1
                    traverse((i, j))


        return total_island
