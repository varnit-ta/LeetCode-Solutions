class Solution(object):
    def findDuplicate(self, nums):
        for i in range(len(nums)):
            t = abs(nums[i])

            if nums[t-1] < 0:
                return t
            else:
                nums[t-1] = 0 - nums[t-1]