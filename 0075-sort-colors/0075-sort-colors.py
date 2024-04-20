class Solution(object):
    def sortColors(self, nums):
        red, white, blue = 0, 0, 0
        for num in nums:
            if num == 0:
                red += 1
            elif num == 1:
                white += 1
            else:
                blue += 1
        
        nums[:] = [0] * red + [1] * white + [2] * blue