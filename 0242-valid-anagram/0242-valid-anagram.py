class Solution(object):
    def isAnagram(self, s, t):
        a = {}
        b = {}

        for i in range(len(s)):
            s_char = s[i]

            if s_char in a:
                a[s_char] += 1
            else:
                a[s_char] = 1
            
        for i in range(len(t)):
            t_char = t[i]
            
            if t_char in b:
                b[t_char] += 1
            else:
                b[t_char] = 1

        return a == b