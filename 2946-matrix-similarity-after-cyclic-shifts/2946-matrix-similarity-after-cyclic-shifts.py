class Solution(object):
    def areSimilar(self, mat, k):
        result = []

        def rotate(array, count):
            arr = [0]*len(array)
            for index, k in enumerate(array):
                arr[(index+count)%len(array)] = k
            return arr

        for arr in mat:
            result.append(rotate(arr, k))

        return result == mat