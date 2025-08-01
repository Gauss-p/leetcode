# https://leetcode.cn/problems/number-of-integers-with-popcount-depth-equal-to-k-ii/description/
# 3624. 位计数深度为 K 的整数数目 II

from typing import List

# 由于本题要进行的操作1本质上是对一个数组进行求子数组的和，操作2本质上是对原数组中的值进行修改，因此这个问题可以用FenwickTree来解决
# 首先分析题目，由于查询操作是要在给定区间中找到位计数深度正好为k的数字个数，因此可以将数组中的所有数字变成0或1，其中0代表位计数深度不等于k，1代表位计数深度等于k，这样我们要求的就是给定区间中的和了。但是注意到k并不只是一个数，在题目给出的数据范围中表明k的取值范围是[0,5]一共六个数字，因此对于每一个k，我们都新建一个FenwickTree，这样就可以分别针对每一个k值进行设置树状数组了
# 接下来我们需要对FenwickTree的一些实现细节进行更改，由于这里整个数组都已经被我们转换成了0或1，因此在初始化函数中，我们就不需要保存原数组了，而且，对于tree数组的初始化，我们也不需要在初始化函数中进行循环，因为所有FenwickTree的初始化都可以在主函数中按照计算出来的位计数深度通过不同FenwickTree的update函数进行
# 对于update函数，不同于以往的更改，如果要将处于i位置的数字x更改为y，我们需要先求出x和y对应的位计数深度dx和dy，然后将dx对应的树状数组中i位置更改为0，并将dy对应的树状数组中i位置更改为1，因此每一个树中的update函数的val都可以有两个值，1或-1，1代表更改为1，-1代表更改为0

class FenwickTree:
    def __init__(self, n):
        self.tree = [0]*(n+1)

    def update(self, index: int, val: int) -> None:
        while index < len(self.tree):
            self.tree[index] += val # 直接加给出的val即可，因为给出的就是1或-1
            index += (index&(-index)) # 往后更新

    def preSum(self, pos):
        # 按照预期的方式求前缀和
        ans = 0
        while pos >= 1:
            ans += self.tree[pos]
            pos -= (pos&(-pos))
        return ans

    def sumRange(self, left: int, right: int) -> int:
        # 两个前缀和相减即可得到中间的和，注意这里需要传入tree中对应的索引，需要都加1
        return self.preSum(right+1)-self.preSum(left)

def calcK(x):
    # 按照定义计算每一个数字的位计数深度
    res = 0
    while x>1:
        res += 1
        x = x.bit_count()
    return res

class Solution:
    def popcountDepth(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        f = [FenwickTree(n+1) for _ in range(6)] # 对每一个位计数深度都定义一个FenwickTree
        for i in range(n):
            d = calcK(nums[i]) # 不同的深度需要对不同的树进行更新
            f[d].update(i+1, 1)
            
        res = []
        for q in queries:
            if q[0] == 1:
                d = q[3]
                res.append(f[d].sumRange(q[1], q[2]))
            else:
                i = q[1]
                oldD = calcK(nums[i])
                f[oldD].update(i+1, -1) # 删除之前的
                nums[i] = q[2]
                newD = calcK(nums[i])
                f[newD].update(i+1, 1) # 加上更改后的
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,4]
    queries = [[1,0,1,1],[2,1,1],[1,0,1,0]]
    print(s.popcountDepth(nums, queries))
