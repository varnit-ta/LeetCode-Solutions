class Solution(object):
    def searchMatrix(self, matrix, target):
        def binarySearch(start, end, row):
            if start > end:
                return False

            mid = start + (end - start) // 2
            if row[mid] == target:
                return True
            elif row[mid] < target:
                return binarySearch(mid + 1, end, row)
            else:
                return binarySearch(start, mid - 1, row)

        for row in matrix:
            if target >= row[0] and target <= row[-1]:
                if binarySearch(0, len(row) - 1, row):
                    return True
            elif target < row[0]:
                return False

        return False