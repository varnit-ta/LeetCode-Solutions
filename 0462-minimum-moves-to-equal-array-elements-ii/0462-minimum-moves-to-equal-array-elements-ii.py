class Solution(object):
    def minMoves2(self, nums):
        nums.sort()
        a = len(nums)//2
        count = 0

        for k in nums:
            count += abs(nums[a] - k)


        return count