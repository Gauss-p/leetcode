class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        val = {'(':1, ')':-1}
        res = 0
        cnt = 0
        for i in s:
            cnt += val[i]
            if cnt < 0:
                res += 1
                cnt += 1
        return res+cnt

if __name__ == "__main__":
    sl = Solution()
    s = "())"
    print(sl.minAddToMakeValid(s))
