class Solution(object):
    def isPalindrome(self, s):
        if s == s[::-1]:
            return True
        
        string = ""

        for i in range(len(s)):
            if s[i].isalnum():
                string = string + s[i].lower()
                
        return string == string[::-1]