class Solution(object):
    def twoSum(self, numbers, target):
        i = 0
        j = len(numbers) - 1

        while j > i:
            a = numbers[i]
            b = numbers[j]

            if a + b == target:
                return [i+1, j+1]
            elif a + b > target:
                j -= 1
            elif a + b < target:
                i += 1