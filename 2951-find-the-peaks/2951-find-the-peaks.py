class Solution(object):
    def findPeaks(self, mountain):
        result = []

        for i in range(1, len(mountain) - 1):
            if mountain[i-1] < mountain[i] > mountain[i+1]:
                result.append(i)

        return result