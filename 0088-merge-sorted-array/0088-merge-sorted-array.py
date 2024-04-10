class Solution(object):
    def merge(self, nums1, m, nums2, n):
        nums1[:] = nums1[:m]
        
        if m == 0:
            nums1[:] = nums2
            return
        
        i, j, k = 0, 0, 0
        while i < m and j < n:
            if nums1[i] <= nums2[j]:
                i += 1
            else:
                nums1.insert(i, nums2[j])
                j += 1
                m += 1
        
        nums1.extend(nums2[j:])
