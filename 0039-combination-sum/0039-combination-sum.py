class Solution(object):
    def combinationSum(self, candidates, target):
        candidates.sort()
        result = []

        def traverse(array, total, start):
            if total == target:
                result.append(array)
                return
            if total > target:
                return

            for i in range(start, len(candidates)):
                if candidates[i] > target - total:
                    break
                traverse(array + [candidates[i]], total + candidates[i], i)

        traverse([], 0, 0)
        return result
