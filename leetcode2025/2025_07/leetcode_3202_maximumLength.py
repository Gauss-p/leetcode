from typing import List

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        # 如果最终的子序列是a,b,c,d，那么它们一定满足(a+b)%k=(b+c)%k=(c+d)%k，因此可以得到(a-c)%k=0, (b-d)%k=0，也就是说，a和c关于模除k同余，b和d关于模除k同余
        # 如果将nums中所有数字看成它模除k以后的数字，那么我们要找的就是·间隔数字相同·的最长子序列
        # 定义f[x][y]表示在模除k之后子序列结尾为x和y的最长子序列长度，那么我们考虑状态转移方程，每循环到一个模除k之后为x的数字，对于所有可能的(x,y)(可以知道y的所有可能就是[0,k-1])，我们如果将当前数字放到以(x,y)为结尾的子序列的最后，那么就会得到一个长度多了1的，以(y,x)为结尾的子序列，因此可以得到：f[y][x]=f[x][y]+1，且对于所有可能的y都需要更新f[y][x]
        res = 0
        f = [[0]*k for _ in range(k)]
        for i in nums:
            x = i%k
            for y in range(k):
                f[y][x] = f[x][y]+1
                if f[y][x] > res:
                    res = f[y][x]
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,4,2,3,1,4]
    k = 3
    print(s.maximumLength(nums, k))
