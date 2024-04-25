class Solution(object):
    def minTimeToVisitAllPoints(self, points):
        result = 0

        for i in range(1, len(points)):
            x = abs(points[i][0] - points[i-1][0])
            y = abs(points[i][1] - points[i-1][1])

            mx, mn = max(x, y), min(x, y)

            result += mn + (mx - mn)

        return result