class Solution(object):
    def findWordsContaining(self, words, x):
        result = []

        for index, k in enumerate(words):
            if x in k:
                result.append(index)

        return result