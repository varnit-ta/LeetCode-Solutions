class Solution(object):
    def findFarmland(self, land):
        result = []
        rows, cols = len(land), len(land[0])

        def traverse(loc):
            pos = [(1, 0), (0, 1)]
            max_x, max_y = loc

            for k in pos:
                x = loc[0] + k[0]
                y = loc[1] + k[1]
                if 0 <= x < rows and 0 <= y < cols and land[x][y] == 1:
                    land[x][y] = 0
                    new_x, new_y = traverse((x, y))
                    max_x = max(max_x, new_x)
                    max_y = max(max_y, new_y)

            return max_x, max_y

        for i in range(rows):
            for j in range(cols):
                if land[i][j] == 1:
                    land[i][j] = 0
                    top_left = (i, j)
                    bottom_right = traverse(top_left)
                    result.append([top_left[0], top_left[1], bottom_right[0], bottom_right[1]])

        return result