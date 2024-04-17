class Solution(object):
    def moveZeroes(self, nums):
        i = 0
        count = 0
        while i < len(nums):
            if nums[i] == 0:
                nums.pop(i)
                count += 1
            else:
                i += 1

        while count:
            nums.append(0)
            count -= 1
        
        return nums