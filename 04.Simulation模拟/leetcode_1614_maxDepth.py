class Solution:
    def maxDepth(self, s: str) -> int:
        res = 0
        cnt = 0
        for i in s:
            cnt += (1 if i=='(' else (-1 if i==')' else 0))
            res = max(res, cnt)
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "()(())((()()))"
    print(sl.maxDepth(s))
