class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        # 从右往左遍历，只要累加的二进制对应的十进制数字还没有超过k就可以继续在前面累加1，而如果超过了k，我们就只能计算前面0的个数而不能计算1的个数了
        # 在程序中我们用v来维护当前已经记录的二进制数字,并且用cnt来维护v的二进制位数,那么每一次在v之前加一个1时就直接用v或上1<<cnt即可实现
        cnt = 0
        v = 0
        n = len(s)
        for i in range(n-1, -1, -1):
            if s[i] == '0':
                cnt += 1
            elif (v|(1<<cnt))<=k:
                v |= (1<<cnt)
                cnt += 1
        return cnt

if __name__ == "__main__":
    sl = Solution()
    s = "1001010"
    k = 5
    print(sl.longestSubsequence(s, k))
