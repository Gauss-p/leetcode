from typing import List

class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        # 将对应数值之差的大小在limit以内的位置分为一组，那么这一组内的所有数字都可以互相交换，故为了让最终的数组字典序最小，只需将同一组内的数字排序后再按照下标从小到大依次填入即可。
        vals = []
        for i,v in enumerate(nums):
            vals.append((v, i))
        vals.sort()

        groups = []
        for i in range(len(vals)):
            if len(groups)==0 or vals[i][0]-nums[groups[-1][-1]] > limit:
                groups.append([vals[i][1]])
            else:
                groups[-1].append(vals[i][1])
        
        for i in range(len(groups)):
            groups[i].sort()
        
        newNums = []
        for g in groups:
            newNums.append([])
            for i in g:
                newNums[-1].append(nums[i])
            newNums[-1].sort()
        
        for indx,g in enumerate(groups):
            for pos,i in enumerate(g):
                nums[i] = newNums[indx][pos]
        return nums

if __name__ == "__main__":
    s = Solution()
    nums = [1,5,3,9,8]
    limit = 2
    print(s.lexicographicallySmallestArray(nums, limit))
