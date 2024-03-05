class Solution(object):
    def isPalindrome(self, x):
        pal = True
        for i in range(len(str(x))):
            if str(x)[i] == str(x)[len(str(x))-i-1]:
                pal = True
            else:
                pal = False
                break
        return pal