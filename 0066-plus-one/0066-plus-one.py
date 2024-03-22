class Solution(object):
    def plusOne(self, digits):
        a = ''.join([str(i) for i in digits])
        a = int(a) + 1
        return [int(i) for i in str(a)]
