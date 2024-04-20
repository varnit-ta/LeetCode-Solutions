class Solution(object):
    def searchMatrix(self, matrix, target):
        def binarySearch(start, end, arr):
            if start > end:
                return False

            mid = start + (end - start) // 2
            if arr[mid] == target:
                return True
            elif arr[mid] < target:
                return binarySearch(mid + 1, end, arr)
            else:
                return binarySearch(start, mid - 1, arr)

        def arraySearch(start, end, arr):
            if start > end:
                return False

            mid = start + (end - start) // 2
            row = arr[mid]
            if row[0] <= target <= row[-1]:
                return binarySearch(0, len(row) - 1, row)
            elif target < row[0]:
                return arraySearch(start, mid - 1, arr)
            else:
                return arraySearch(mid + 1, end, arr)

        if not matrix or not matrix[0]:
            return False

        return arraySearch(0, len(matrix) - 1, matrix)