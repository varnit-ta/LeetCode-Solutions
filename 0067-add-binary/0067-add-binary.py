class Solution(object):
    def addBinary(self, a, b):
        result = ""
        carry = 0

        len_diff = len(a) - len(b)
        if len_diff > 0:
            b = "0" * len_diff + b
        elif len_diff < 0:
            a = "0" * (-len_diff) + a

        for i in range(len(a) - 1, -1, -1):
            digit_sum = int(a[i]) + int(b[i]) + carry
            result = str(digit_sum % 2) + result
            carry = digit_sum // 2

        if carry:
            result = "1" + result

        return result
