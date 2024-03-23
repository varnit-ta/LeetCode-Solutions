class Solution(object):
    def addTwo(self, a, b):
        if a == 1 and b == 1:
            return [1, 0]
        elif a == 1 and b == 0 or a == 0 and b == 1:
            return [0, 1]
        else:
            return [0, 0] 

    def addBinary(self, a, b):
        result = ""

        if len(a) < len(b):
            a = "0"*(len(b) - len(a)) + a
        else:
            b = "0"*(len(a) - len(b)) + b

        i = len(a)-1
        carry = 0

        while i >= 0:
            ans1 = self.addTwo(int(a[i]), int(b[i]))
            ans2 = self.addTwo(ans1[1], carry)

            if ans1[0] == 1 or ans2[0] == 1:
                carry = 1
            else:
                carry = 0

            result = str(ans2[1]) + result

            if i == 0 and carry == 1:
                result = "1" + result

            i -= 1

        return result