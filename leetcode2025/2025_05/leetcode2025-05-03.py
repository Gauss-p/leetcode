from typing import List

class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        # 将两行的每一列合并为一个二元组，然后求出所有二元组的交集x，那么对于x有以下三种情况
        # 1.len(x)=2，此时说明所有的二元组都只由x中的两个元素构成，只要第一行相同了，第二行一定相同，所以我要么将第一行所有元素都变为x[0]，要么将第一行所有元素都变为x[1]，答案就是两种情况的最小值，即min(tops.count(x[0]), tops.count(x[1]))
        # 2.len(x)=1，此时说明每一列中都至少有一个x[0]，也就是我们需要将第一行或第二行全部变为x[0]，若要将第一行全部变成x[0]，则需将不是x[0]的所有元素与下面交换，而若要将第二行全部变成x[0]，也需将不是x[0]的所有元素与上面交换，答案就是两种情况的最小值，即min(n-tops.count(x[0]), n-bottoms.count(x[0]))
        # 3.len(x)=0，此时说明没有一个元素存在于所有列中，返回-1即可
        n = len(tops)
        x = set([tops[0], bottoms[0]])
        for i in range(1,n):
            x = x.intersection(set([tops[i], bottoms[i]]))

        x = list(x)
        if len(x) == 2:
            return min(tops.count(x[0]), tops.count(x[1]))
        if len(x) == 1:
            return min(n-tops.count(x[0]), n-bottoms.count(x[0]))
        return -1

if __name__ == "__main__":
    s = Solution()
    tops = [2,1,2,4,2,2]
    bottoms = [5,2,6,2,3,2]
    print(s.minDominoRotations(tops, bottoms))
