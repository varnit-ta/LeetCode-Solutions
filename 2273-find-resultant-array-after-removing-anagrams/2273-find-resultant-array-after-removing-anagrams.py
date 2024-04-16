class Solution(object):
    def removeAnagrams(self, words):
        result = []
        p = 0

        while p < len(words):
            word = words[p]
            a = {}

            for k in word:
                if k in a:
                    a[k] +=1
                else:
                    a[k] = 1

            if result and result[-1] == a:
                words.pop(p)
            else:
                result.append(a)
                p +=1

        return words