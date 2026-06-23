from itertools import accumulate

class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        modNum = 1_000_000_007
        r -= l
        m = r+1
        # 为了简便计算，可以将l和r都减少l，使区间变为[0,r-l]，这和原有情况是等价的
        # 定义dp0[i][j]表示数组长度为i且第i个数字为j时，最后两个数字呈上升趋势的情况下，数组的总数量
        # 定义dp1[i][j]表示数组长度为i且第i个数字为j时，最后两个数字呈下降趋势的情况下，数组的总数量
        # 因此可以根据第i个位置填写的数字决定上一个位置填写的数字范围，由于对这个范围内的所有可能的填写情况都要累加，故可以想到用前缀和来优化计算

        dp0 = [1]*m
        dp1 = [1]*m
        for i in range(1, n):
            preSum0 = list(accumulate(dp0, initial = 0))
            preSum1 = list(accumulate(dp1, initial = 0))
            for j in range(r+1):
                # 第i个数字填j时，若最后两个数字呈上升趋势，则上一个数字取值范围为[l,j-1]，否则范围为[j+1,r]
                dp0[j] = preSum1[j]%modNum
                dp1[j] = (preSum0[-1]-preSum0[j+1])%modNum
        return (sum(dp0)+sum(dp1))%modNum

if __name__ == "__main__":
    s = Solution()
    n, l, r = 3, 4, 5
    print(s.zigZagArrays(n, l, r))
