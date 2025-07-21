class Solution:
    def makeFancyString(self, s: str) -> str:
        last = 0
        s += '.'
        n = len(s)
        res = ""
        for i in range(1, n):
            if s[i-1] != s[i]:
                cur = i-last # 计算当前重复块的长度
                res += min(cur, 2)*s[last] # 一个重复块内最多选2个
                last = i
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "leeetcode"
    print(sl.makeFancyString(s))
