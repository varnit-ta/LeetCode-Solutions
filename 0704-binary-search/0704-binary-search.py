class Solution(object):
    def search(self, nums, target):

        def binarySearch(nums, start, end):
            if start > end:
                return -1

            mid = start + (end - start)//2

            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                return binarySearch(nums, start, mid - 1)
            elif nums[mid] < target:
                return binarySearch(nums, mid + 1, end)
            
        return binarySearch(nums, 0, len(nums) - 1)