class Solution(object):
    def singleNumber(self, nums):
        if len(nums) == 1:
            return nums[0]

        result = 0
        for num in nums:
            result ^= num
        return result 