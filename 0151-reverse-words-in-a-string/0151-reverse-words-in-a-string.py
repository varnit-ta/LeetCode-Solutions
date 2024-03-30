class Solution(object):
    def reverseWords(self, s):
        arr = []
        string = ""

        for i in range(len(s)):
            if s[i] != " ":
                string = string + s[i]
            else:
                if string != "":
                    arr.append(string)
                string = ""

        arr.append(string) if string != "" else None

        result = " ".join(arr[::-1])

        return result