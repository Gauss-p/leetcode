# https://leetcode.cn/problems/range-sum-query-mutable/description/
# 307. 区域和检索 - 数组可修改

from typing import List

# 这道题目本质上是FenwickTree模板题，这道题目如果用前缀和来维护，那么每一次update和sumRange时都需要O(n)的时间，而如果用FenwickTree则只需要O(log(n))的时间
# FenwickTree在查询前缀和时是将每一个位置的索引按照二进制拆分成多个数字，在求和时按照拆分出来的各个数字来寻找对应的和，累加即可。对于每一个位置，我们都存储一个和，这个和用来保存以当前位置为结尾的一个子数组的总和，用一个数组tree来存储各个位置对应的和，那么问题在于，应当如何分配每一个位置对应子数组的开头，才能够让我们在求和时按照二进制位来分解呢？
# 举个例子，如果一个位置是13，那么分析它的二进制，可以得到1101，也就是说，13=8+4+1，因此我们期望的分解方式应当是3个子数组，长度分别为1和4和8，而如果我们依次去掉13二进制的最后一个1，就可以得到如下的序列：1101,1100,1000,0000，三个数分别代表13,12,8,0，注意到13和12之间的差值为1，12和8之间的差值为4，8和0之间的差值为8，这样，我们就将前13个数字分成了我们所需要的3部分：(0,8],(8,12],(12,13]，因此，为了实现预期的求和方式，我们就可以采用这样的子数组开头分配方式，也就是对于每一个位置i，我们可以通过位运算去掉i二进制中最后一个1，也就是i-(i&(-i))，因此tree[i]中存储的就应当是原数组中索引位于区间(i-(i&(-i)), i]中的和，这样我们就确定出了每一个位置对应的子数组的起点
# 借用这个思路，我们可以得到求0到某一个位置的前缀和的方法，也就是不断去掉最后一个二进制位是1的位置，然后累加tree中对应的数字即可
# 接下来，题目中还有可能要我们更新，注意到，如果更新一个位置，可能多个tree中的数字都会发生改变，因此我们还需要考虑更新时的问题。假设我们现在更改第5个数字的值，那么考虑tree中的哪些和会受到影响，首先，tree[5]会受影响，其次，tree[6]存的是(4,6]的和，因此tree[6]也会受影响，以此类推，还有tree[8],tree[16],tree[32]都会受影响，我们将这些数字的二进制排列起来，可以得到：101, 110, 1000, 10000, 100000，注意到每一个数字都等于前一个数字加上前一个数字最后一个是1的二进制位，因此我们可以通过将更改数字的序号不断增加它最后一个1的位来得到需要更改的所有tree中元素，也就是，如果更新第i个数，那么我们就不断更新tree[i]，并将i每次变成i+(i&(-i))即可
# 需要注意的是，在创建tree数组时，由于二进制操作中不用到0，所以我们在调用tree时不用到索引0，也就需要将tree的大小设置为初始大小加1

class NumArray:
    def __init__(self, nums: List[int]):
        n = len(nums)
        self.nums = [0]*n
        self.tree = [0]*(n+1)
        # 最开始直接利用更新函数创建tree数组
        for i in range(1, n+1):
            self.update(i-1, nums[i-1])

    def update(self, index: int, val: int) -> None:
        delta = val-self.nums[index]
        self.nums[index] = val
        index += 1 # 由于tree中索引0不用，所以tree中的索引始终比nums中的索引多1
        while index <= len(self.nums):
            self.tree[index] += delta
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

if __name__ == "__main__":
    nums = [1,3,5]
    na = NumArray(nums)
    vals = [[0,2],[1,2],[0,2]]
    ops = ["sumRange","update","sumRange"]
    for i in range(len(vals)):
        if ops[i] == "sumRange":
            print(na.sumRange(vals[i][0], vals[i][1]))
        else:
            na.update(vals[i][0], vals[i][1])
