class Solution(object):
    def climbStairs(self, n):
        if n == 0:
            return 0

        if n == 1:
            return 1

        arr = [1 for i in range(n)]
        arr2 = [[arr[:], 0, n]]

        while arr[-1] == 1 and (arr[-2] != 2 or arr[-2] != 2):
            arr.pop()
            arr.pop()
            arr.insert(0, 2)

            arr2.append([arr[:], arr2[-1][1] + 1, arr2[-1][2] - 2])

        result = 0

        for k in arr2:
            if k[0][:] == k[0][::-1]:
                result += 1
            else:
                result += factorial(len(k[0]))/(factorial(k[1]) * factorial(k[2]))

        print(arr2)

        return result