from typing import List

modNum = 1_000_000_007
maxNum = 1001
prod = [1]*maxNum
for i in range(1, maxNum):
    prod[i] = (prod[i-1]*i)%modNum

inv = [1]*maxNum
inv[-1] = pow(prod[-1], -1, modNum)
for i in range(maxNum-2, 0, -1):
    inv[i] = (inv[i+1]*(i+1))%modNum

def myComb(a, b):
    if b == 0:
        return 1
    return (prod[a]*inv[b]*inv[a-b])%modNum

class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        # 可以发现，对于一棵树而言，根节点位置是不能动的，即必须保持在数组的索引0处，能动的只有剩余元素的顺序。假设对于当前根节点而言，左子树总共有left个数字，右子树总共有right个数字，且单纯对于左子树而言，总共有x个排列能够恰好得到同样的子树，单纯对于右子树而言，总共有y个排列能够恰好得到同样的子树，那么这整棵树总共有多少种可能的排列方式呢？可以这样考虑：假设现在选一种左子树的排列，一种右子树的排列，将它们相互交叉在一起，只要保证原先在同一个排列中的两个元素相对顺序不发生改变，得到的新排列就是一种合法的总的排列，举个例子，如果当前选择的左子树排列是[1,2]，右子树排列是[4,5]，那么最终总的排列只需要保证1在2的前面，且4在5的前面即可。也就是说，对于左右子树的各一种排列，总共就有C(left+right, left)种排列方式，那么这整棵树对应的数组排列方式就有：x*y*C(left+right, left)种。
        # 注意到，对于一个根节点，可以将剩余的元素分成左右两部分，并对左右两部分分别计算后才可得到当前根节点对应的总排列方式，因此可以用dfs的方式递归进行解决。

        n = len(nums)
        def dfs(indx, mn, mx):
            # indx表示当前根节点在nums中的索引，mn,mx分别表示以nums[indx]为根节点的子树中的最小值和最大值。
            # 又因为nums是1到n的一个排列，于是可以知道，左子树总共有nums[indx]-mn个元素，右子树共有mx-nums[indx]个元素
            x = nums[indx]
            small, large = -1, -1
            for i in range(indx+1, n):
                # 通过寻找出现在indx之后，且值位于区间[mn,mx]中的第一个大于nums[indx]和第一个小于nums[indx]的两个位置，可以确定nums[indx]的两个子节点。
                if small>-1 and large>-1:
                    break
                if nums[i] >= mn and nums[i] < x and small==-1:
                    small = i
                if nums[i] <= mx and nums[i] > x and large==-1:
                    large = i
            left = 1
            if small > -1: # 存在左子树
                left = dfs(small, mn, x-1)
            right = 1
            if large > -1: # 存在右子树
                right = dfs(large, x+1, mx)
            
            return (myComb(mx-mn, x-mn)*left*right)%modNum
        return dfs(0, 1, n)-1 # 减掉nums本身的那一种排列

if __name__ == "__main__":
    s = Solution()
    nums = [2,1,3]
    print(s.numOfWays(nums))
