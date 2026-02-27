class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        s += '.'
        n = len(s)
        parts = []
        last = 0
        for i in range(1, n):
            if s[i] != s[last]:
                parts.append(i-last)
                last = i
        
        res = 0
        for i in range(len(parts)-1):
            res += min(parts[i], parts[i+1])
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "00110011"
    print(sl.countBinarySubstrings(s))
