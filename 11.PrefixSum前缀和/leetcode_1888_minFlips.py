class Solution:
    def minFlips(self, s: str) -> int:
        # 可以这样考虑，对于每一个位置i，提前计算出将s[:i]和s[i:]变为以特定元素开头的交替字符串的操作次数，这样，对于每一个位置都按照交替要求将这两者相加，即表示对每一个位置都将前半段放到字符串末尾后，将其变成交替字符串的操作次数
        # 而前缀和后缀的操作次数可以用前缀和及后缀和维护：将每个前缀和后缀变成交替字符串的操作次数，但注意到开头元素的不同会直接导致操作次数的不同，因此在计算的时候需要对同一个位置维护两个值。故定义前缀和数组preSum，其中preSum[i][0]表示将s[:i]变成以0开头的交替字符串的操作次数，同时preSum[i][1]表示将s[:i]变成以1开头的交替字符串的操作次数。同样的，sufSum[i][0]表示将s[i:]变成以0结尾的交替字符串的操作次数，sufSum[i][1]表示将s[i:]变成以1结尾的交替字符串的操作次数
        # 为了满足交替要求，如果将s从一个位置i拆分后重新拼接，必须令其前缀的开头元素和后缀的结尾元素不同，故在计算的时候，只能计算：preSum[i][0]+sufSum[i][1]和preSum[i][1]+sufSum[i][0]，最后求所有的最小值即可
        n = len(s)
        preSum = [[0,0] for _ in range(n+1)]
        sufSum = [[0,0] for _ in range(n+1)]
        cur = 0
        for i in range(n):
            preSum[i+1][1] = preSum[i][1]+(s[i]==str(cur))
            preSum[i+1][0] = preSum[i][0]+(s[i]!=str(cur))

            sufSum[n-i-1][1] = sufSum[n-i][1]+(s[n-i-1]==str(cur))
            sufSum[n-i-1][0] = sufSum[n-i][0]+(s[n-i-1]!=str(cur))
            cur ^= 1
        
        res = float("inf")
        for i in range(n+1):
            res = min(res, preSum[i][0]+sufSum[i][1], preSum[i][1]+sufSum[i][0])
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "111000"
    print(sl.minFlips(s))
