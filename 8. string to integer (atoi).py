class Solution:
    def myAtoi(self, s: str) -> int:
        i = 0
        n = len(s)
        sign = 1
        result = 0
        while i < n and s[i] == ' ':
            i += 1
        if i < n and s[i] == '-':
            sign = -1
            i += 1
        elif i < n and s[i] == '+':
            i += 1
        while i < n and '0' <= s[i] <= '9':
            result = result * 10 + (ord(s[i]) - ord('0'))
            if result > 2**31 - 1:
                return 2**31 - 1 if sign == 1 else -2**31
            i += 1
        return sign * result