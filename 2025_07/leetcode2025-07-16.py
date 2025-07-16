from typing import List

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        # 如果最终的子序列是a,b,c,d，那么它们一定满足(a+b)%2=(b+c)%2=(c+d)%2，因此可以得到(a-c)%2=0, (b-d)%2=0，也就是说，a和c关于模除2同余，b和d关于模除2同余
        # 如果将nums中所有数字看成它模除2以后的数字，那么我们要找的就是·间隔数字相同·的最长子序列
        # 定义f[x][y]表示在模除2之后子序列结尾为x和y的最长子序列长度，那么我们考虑状态转移方程，每循环到一个模除2之后为x的数字，对于所有可能的(x,y)，我们如果将当前数字放到以(x,y)为结尾的子序列的最后，那么就会得到一个长度多了1的，以(y,x)为结尾的子序列，因此可以得到：f[y][x]=f[x][y]+1，且对于所有可能的y都需要更新f[y][x]
        res = 0
        f = [[0]*2 for _ in range(2)]
        for i in nums:
            x = i%2 # 取出当前数字模除2之后的余数
            for y in range(2):
                f[y][x] = f[x][y]+1 # 更新所有可能的(y,x)
                if f[y][x] > res:
                    res = f[y][x]
        return res

        # n = len(nums)
        # odd, even = 0, 0
        # last = nums[0]%2
        # diff = 1
        # for i in nums:
        #     if i & 1:
        #         odd += 1
        #     else:
        #         even += 1
        #     if i%2 != last:
        #         diff += 1
        #         last = i%2
        # return max(diff, odd, even)

if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4]
    print(s.maximumLength(nums))
