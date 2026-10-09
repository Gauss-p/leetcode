class Solution:
    def minInsertions(self, s: str) -> int:
        s += '.'
        n = len(s)
        res = 0
        last = 0
        cnt = 0
        for i in range(n):
            if s[i] != s[last]:
                length = i-last
                if s[last] == '(':
                    cnt += length
                else:
                    res += length%2
                    cnt -= (length+length%2)//2
                    if cnt < 0:
                        res += (-cnt)
                        cnt = 0
                last = i
        return res+cnt*2

if __name__ == "__main__":
    sl = Solution()
    s = "(()))"
    print(sl.minInsertions(s))
