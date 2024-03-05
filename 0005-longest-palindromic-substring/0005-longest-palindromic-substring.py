class Solution(object):
    def longestPalindrome(self, s):
        start = 0
        strLen = len(s)
        end = start + strLen
        notPal = True

        while notPal:
            if s == s[::-1]:
                notPal = False
                return s
                break
            while end != len(s) and notPal == True:
                string = s[start:end+1]
                if string == string[::-1]:
                    notPal = False
                    return string
                start += 1
                end = start + strLen
            strLen -= 1
            start = 0
            end = start + strLen