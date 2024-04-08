class Solution(object):
    def searchInsert(self, nums, target):
        def binarySearch(arr, left, right, a):
            if right >= left:
                mid = left + (right - left)//2
                if arr[mid] == a:
                    return mid
                elif arr[mid] > a:
                    return binarySearch(arr, left, mid - 1, a)
                else:
                    return binarySearch(arr, mid + 1, right, a)
            else:
                return left

        return binarySearch(nums, 0, len(nums) - 1, target)