class Solution(object):
    def findErrorNums(self, nums):
        result = []

        total = len(nums) * (len(nums) + 1)/2
        nums_sum = 0

        for i in range(len(nums)):
            t = abs(nums[i])

            if nums[t-1] < 0:
                result.append(t)
            else:
                nums_sum += t
                nums[t-1] = -nums[t-1]

        result.append(total - nums_sum)
        return result