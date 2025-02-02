class Solution:
    def reverse(self, x: int) -> int:
        if x >= 0:
            y = str(x)
            rev = y[::-1]
            z = int(rev)
        elif x < 0:
            y = str(abs(x))
            rev = y[::-1]
            z = int(rev)
            z = z * -1
        if z < -2**31 or z > 2**31 - 1:
            return 0
        
        return z