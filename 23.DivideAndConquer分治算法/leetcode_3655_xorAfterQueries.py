from typing import List
from math import sqrt

class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        # 根据题目要求，我们可以知道，题目所需要的是我们按照queries中的所有查询来更改nums中的部分数组，最后对nums中的所有数字进行异或求答案。首先可以想到暴力解法，也就是对于每一组[l,r,k,v]，我们都从l循环到r，间隔为k，然后将循环到的每一个数字乘以v。但是这有一个问题，就是如果k太小，就需要将几乎所有元素依次遍历更新，这需要O(n**2)的时间，一定会超时。因此我们将查询分成两个部分，第一个部分中所有的k值都是比较大的，第二个部分中所有的k值都是比较小的，那么对于第一个部分，我们就可以直接暴力计算，第二个部分则需要另外处理
        # 如何快速处理一段数字的乘积呢？我们可以仿照差分数组，构建一个商分数组，但是注意到，如果单纯用商分数组来处理一个子数组中的数字，让它们乘上一个数，我们其实只能够操作一段连续的数字，而不能像题目要求的那样操作一段数字中以一定间隔分割的部分数字。怎么办？既然构造的时候比较麻烦，那么我们可以选择在还原数组的时候搞一些事情。正常还原的时候是从头到尾乘上一些数字的，但是假如我们按照给定的间隔来还原其中的部分数字，是否可以达到效果呢？
        # 举个例子，假如我们要处理的是l=1,r=9,k=3,那么我们需要对以下序号进行处理:[1, 4, 7]，那么我们在商分数组中索引为1的位置乘上v，并在索引为10的位置除以v即可，之所以要在10的位置除，是因为仿照差分数组中: 间隔为1，就在终点位置向后移动1再除，那么在这里，间隔为3, 就要在终点位置向右移动3再除. 这样构造出来的列表, 如果按照间隔3来还原, 同样可以得到我们需要的乘积效果, 因此上述"另外处理"就可以用这种方式
        # 为了还原的时候方便, 我们可以在构建商分数组的时候对于每一个不同的间隔构建一个单独的商分数组, 然后对于所有间隔相同的查询分别进行上述的操作, 最后在还原的时候按照间隔分别还原即可. 注意, 在还原的时候, 不需要对于所有位置都以它为开头来进行一次计算, 因为对于一个固定间隔k, 从0开始计算和从k开始计算是重复的.
        modNum = 1_000_000_007
        n = len(nums)
        B = int(sqrt(len(queries)))
        diff = [None]*B

        for l,r,k,v in queries:
            if k>=B:
                for i in range(l, r+1, k):
                    # k比较大, 循环次数比较少, 可以直接暴力
                    nums[i] = (nums[i]*v)%modNum
                continue
            
            if not diff[k]:
                diff[k] = [1]*(n+k)
            diff[k][l] = (diff[k][l]*v)%modNum # 将左端点乘以v
            r = r-(r-l)%k+k # 计算右端点之后k个位置
            diff[k][r] = (diff[k][r]*pow(v, -1, modNum))%modNum

        for k, d in enumerate(diff):
            if not d:
                continue
            
            for start in range(k):
                prod = 1
                for i in range(start, n, k):
                    # 还原需要乘的数字以及原数组中的数字
                    prod = (prod*d[i])%modNum
                    nums[i] = (nums[i]*prod)%modNum

        res = 0
        for i in nums:
            res ^= i
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,1,1]
    queries = [[0,2,1,4]]
    print(s.xorAfterQueries(nums, queries))
