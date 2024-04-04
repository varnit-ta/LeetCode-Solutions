class Solution(object):
    def combinationSum2(self, candidates, target):
        result = []

        def traverse(array, candidate, total):
            if total == target:
                result.append(array[:])
                return

            if total > target:
                return

            for index, num in enumerate(candidate):
                if num > target - total:
                    break
                if index > 0 and candidate[index] == candidate[index - 1]:
                    continue

                traverse(array + [num], candidate[index + 1:], total + num)

        candidates.sort()
        traverse([], candidates, 0)
        return result
