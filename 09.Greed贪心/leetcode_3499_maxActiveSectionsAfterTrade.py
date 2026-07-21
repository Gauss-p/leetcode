class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        groups = []
        s += '2'
        n = len(s)
        last = 0
        for i in range(1,n):
            if s[i] != s[i-1]:
                groups.append((last, i-last))
                last = i

        m = len(groups)
        res = s.count('1')
        cnt = res
        for i in range(1,m-1):
            if s[groups[i-1][0]]=='0' and s[groups[i][0]]=='1' and s[groups[i+1][0]]=='0':
                res = max(res, cnt+groups[i+1][1]+groups[i-1][1])
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "0100"
    print(sl.maxActiveSectionsAfterTrade(s))
