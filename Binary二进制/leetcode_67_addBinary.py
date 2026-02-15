# https://leetcode.cn/problems/add-binary/?envType=daily-question&envId=2026-02-15
# 67.二进制求和

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(a) < len(b):
            a, b = b, a
        a = list(a)
        b = list(b)
        m, n = len(a), len(b)
        res = ""
        need = 0
        for i in range(1, m+1):
            cur = int(a[m-i])+need
            if i <= n:
                cur += int(b[n-i])
            if cur <= 1:
                res = str(cur)+res
                need = 0
            else:
                res = str(cur&1)+res
                need = 1
        
        if need:
            res = str(need)+res
        return res

if __name__ == "__main__":
    s = Solution()
    a, b = "11", "1"
    print(s.addBinary(a, b))
