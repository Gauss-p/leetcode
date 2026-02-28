class Solution:
    def numSub(self, s: str) -> int:
        modNum = 1_000_000_007
        s += '0'
        n = len(s)
        last = 0
        res = 0
        for i in range(1, n):
            if s[i-1] != s[i]:
                if s[i-1] == '1':
                    curLength = i-last
                    res += (1+curLength)*curLength//2
                last = i
        return res%modNum
        
if __name__ == "__main__":
    sl = Solution()
    s = "0110111"
    print(sl.numSub(s))
