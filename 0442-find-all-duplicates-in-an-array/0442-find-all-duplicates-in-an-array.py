class Solution(object):
    def findDuplicates(self, arr):
        result = []

        for num in arr:
            index = abs(num) - 1

            if arr[index] < 0:
                result.append(abs(num))
            else:
                arr[index] *= -1

        return result
