from typing import List

class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        # 我们遍历所有可能的走法，求最大值即可。那么由于题目中是可以走回头路的，因此我们可以先往右走然后再往左走，这样就可以收集到左右两边的水果了，但是我们有步数限制，所以需要根据不同的情况确定能够采摘水果的位置区间。假设我们现在先往右走x步，接下来用剩余的步数往回走，那最终能够走到哪里呢？为了回到起点，我们就需要再用掉x步，因此最远也只能走到起点左边k-2*x步的位置，因此，遍历所有可能的x步，计算最大能够达到的区间进行计算即可。但是注意，如果x=k，那么我们计算出来向左能够走的步数就变成了k-2*k=-k，这样最左边能够到达的点就变成了startPos-(-k)=startPos+k，和右端点一样了，因此我们需要限制左端点的最大值为startPos，毕竟往左边走不能走着走着到右边了。但是还有一种情况，就是往左走后到达一个负数位置，这是不存在的，因此我们需要将左端点约束在大于等于0的范围内，综上，左端点无论如何应当在[0,startPos]内
        # 但是先往右走再往左走和先往左走再往右走是不一样的，因此我们还需遍历所有可能的向左走的步数，然后确定再向右走能够到达的最大的区间。不过注意，这里如果发现向左走时索引小于0了，直接退出循环即可，因为所有的可能的情况都已经计算遍了
        # 为了快速计算一个区间内的水果数量，我们可以用前缀和的思路
        maxPos = startPos+k
        preSum = [0]*(maxPos+2)
        i, j = 0, 0
        while i<=maxPos:
            if j<len(fruits) and i == fruits[j][0]:
                preSum[i+1] = preSum[i]+fruits[j][1]
                j += 1 # 双指针求前缀和，利用了fruits已排序的特性
            else:
                preSum[i+1] = preSum[i]
            i += 1
        
        res = 0
        for rightStep in range(k+1): # 先右后左
            l, r = min(startPos, max(0, startPos-(k-2*rightStep))), startPos+rightStep
            res = max(res, preSum[r+1]-preSum[l])
        for leftStep in range(k+1): # 先左后右
            l, r = startPos-leftStep, startPos+(k-2*leftStep)
            if l<0:
                break
            res = max(res, preSum[r+1]-preSum[l])
        return res

if __name__ == "__main__":
    s = Solution()
    fruits = [[2,8],[6,3],[8,6]]
    startPos = 5
    k = 4
    print(s.maxTotalFruits(fruits, startPos, k))
