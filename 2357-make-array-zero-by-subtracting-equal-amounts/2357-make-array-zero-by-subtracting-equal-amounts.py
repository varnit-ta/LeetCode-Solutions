class Solution(object):
    def minimumOperations(self, nums):
        nums.sort()

        while nums and nums[0] == 0:
            nums.pop(0)

        if not nums:
            return 0

        count = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                count += 1

        return count