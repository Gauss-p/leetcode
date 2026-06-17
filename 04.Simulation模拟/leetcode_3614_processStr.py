class Solution:
    def processStr(self, s: str, k: int) -> str:
        ops = "*#%"
        length = 0
        for c in s:
            if c not in ops:
                length += 1
            if c == "*" and length >= 1:
                length -= 1
            if c == "#":
                length <<= 1
                
        if k >= length:
            return '.'
            
        for c in s[::-1]:
            if c not in ops:
                if k == length-1:
                    return c
                else:
                    length -= 1
            if c == "%":
                k = length-1-k
            if c == "#":
                if k >= length//2:
                    k = k-length//2
                length //= 2
            if c == "*":
                length += 1
        return '.'

if __name__ == "__main__":
    sl = Solution()
    s = "a#b%*"
    k = 1
    print(sl.processStr(s, k))
