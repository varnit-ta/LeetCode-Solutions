class Solution(object):
    def islandPerimeter(self, grid):
        result = 0

        def perimeter(ind):
            r = 0
            search = [(0, 1), (1, 0), (-1, 0), (0, -1)]

            for k in search:
                x = ind[0] + k[0]
                y = ind[1] + k[1]

                if x < len(grid) and y < len(grid[x]) and x >= 0 and y >= 0:
                    if grid[x][y] == 1:
                        r += 1

            return r

        for indr in range(len(grid)):
            for indc in range(len(grid[indr])):
                if grid[indr][indc] == 1:
                    surr = perimeter((indr, indc))
                    result += 4-surr

        return result