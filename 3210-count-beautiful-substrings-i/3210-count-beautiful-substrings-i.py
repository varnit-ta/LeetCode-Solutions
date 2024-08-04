class Solution(object):
    def beautifulSubstrings(self, s, k):
        vowels = {"a", "e", "i", "o", "u"}

        count = 0

        for i in range(len(s)):
            v = 0
            c = 0
            for j in range(i, len(s)):
                if s[j] in vowels:
                    v += 1
                else:
                    c += 1

                if v == c and (v * c) % k == 0:
                    count += 1
        return count               