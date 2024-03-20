class Solution(object):
    def strStr(self, haystack, needle):
        if (len(haystack) == 1 and needle == haystack):
            return 0

        for i in range(len(haystack) - len(needle) + 1):
            if needle == haystack[i : i + len(needle)]:
                return i

        return -1