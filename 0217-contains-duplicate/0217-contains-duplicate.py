class Solution(object):
    def containsDuplicate(self, nums):
        a = {}

        for num in nums:
            if num not in a:
                a[num] = 1
            else:
                return True

        return False        