class Solution(object):
    def majorityElement(self, nums):
        count = {}
        max_app = 0
        result = 0

        for num in nums:
            if num in count:
                count[num] += 1
            else:
                count[num] = 1

            if max_app < count[num]:
                max_app = count[num]
                result = num

        return result