class Solution(object):
    def firstMissingPositive(self, nums):

        h = 0
        k = None

        nums.sort()
        a = len(nums)
        
        index = 0
        while (index < a):
            if nums[index] >= 0:
                k = index
                break
            else:
                index += 1

        i = k 

        if k == None:
            h = 1
        else:
            m = nums[k]

            if m > 1:
                h = 1
            else:
                while k <= i < a:
                    if nums[i] != m:
                        h = m
                    elif i == a-1:
                        h = nums[i] + 1
                    else:
                        m += 1
                    i += 1
        return h
