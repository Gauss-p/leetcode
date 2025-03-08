from typing import List

class Solution:
    def maximumBeauty(self, flowers: List[int], newFlowers: int, target: int, full: int, partial: int) -> int:
        # 对于这道题目，我们可以考虑贪心的算法。因为额外种花的最大数目一定，所以如果要将某个花园变成完善花园，最好是让这个花园原有的花数量最大，而如果我们要提高不完善花园的花的最小数目，只有将最小的几个花园同时增加才行。所以我们可以将flowers数组进行排序，要变完善花园的是flowers的后缀，要整体增加的是flowers的前缀
        # 如果我们要将flowers[i:n]都变成完善花园，那么需要的花数量就是target*(n-i)-sum(flowers[i:n]),而为了防止负数的出现，我们可以在最开始将flowers中所有超过target的花园中花数量全部置为target，本来对于花的数量超过target的花园我们也不会进行任何操作或计算，因此这样的操作不会影响答案。这样一来，将后缀变成完善花园需要的总花数就不会变成负数，我们就可以计算将flowers[i:n]变成完善花园后剩余的额外种花数量leftFlowers
        # 可以算出，leftFlowers=newFlowers-(target*(n-i)-sum(flowers[i:n]))。根据这个剩余花数，我们可以计算出一共能将多少前缀统一提高到多少。为了确定能够提高多少前缀，我们先一个数一个数地填平，即:因为已经从小到大排列，我们可以先将第一个数填到第二个数，再将第一、第二个数填到第三个数，以此类推，一直到无法将前j个数提高到flowers[j]为止。为了计算j，我们首先计算出preSum=sum(flowers[0:j])，这就是前j个数的总和，如果将前j个数全部填到flowers[j]还无法将leftFlowers用完，就继续前进j。写成符号语言就是，如果j*flowers[j]-preSum<=leftFlowers，那么j+=1。注意，因为j是从前向后循环的，所以preSum可以在循环时进行计算，即，在j+1之前把preSum加上flowers[j]，这样可以减少求前缀和的循环次数
        # 到此，我们只求出来一共能将多少前缀统一提高，接下来算能提高到多少。我们定义avg是能提高到的数字，那么如果将前j个花园全部提高到avg朵花，总的花数就是j*avg。但是又因为有剩余额外种花的个数的限定，所以总花数不能超过leftFlowers加上原有的总花数preSum，写成代码就是:j*avg<=leftFlowers+preSum。根据这个方程，我们可以解出avg的最大值，只有将avg最大化，总美丽值才能更大。所以max(avg)=(leftFlowers+preSum)//j
        # 这时我们就可以求出当前的总美丽值tmpBeauty=max(avg)*partial+(n-i)*full
        # 之后求答案的最大值即可
        n = len(flowers)
        for i in range(n):
            # 处理超过target的花园
            flowers[i] = min(flowers[i], target)

        leftFlowers = newFlowers-(n*target-sum(flowers)) # 计算将所有花园变成完善花园的剩余额外种花数量
        # 两个特殊情况，第一个是原本所有花园都是完善花园，那么最大总美丽值就是n*full
        if leftFlowers==newFlowers:
            return n*full
        # 第二个是可以用额外总种花数将所有花园都变成完善花园，那么最大总美丽值有两种情况，第一种是直接将所有花园都变成完善花园，第二个是将1个花园的花数增加到target-1，其他花园全部变成完善花园。第二种情况的实际例子是题目中的示例2:flowers = [2,4,5,3], newFlowers = 10, target = 5, full = 2, partial = 6.
        if leftFlowers>=0:
            return max((target-1)*partial+(n-1)*full, n*full)

        flowers.sort()
        res, j, preSum = 0, 0, 0
        for i in range(1,n+1):
            # 不将第i-1个花园变成target，即撤销第i-1个花园
            leftFlowers += (target-flowers[i-1])
            if leftFlowers<=0:
                # 如果连flowers[i:n]都无法填满，就继续撤销
                continue

            while j<i and flowers[j]*j-preSum<=leftFlowers:
                # 计算可以将多少花园统一增加
                preSum += flowers[j]
                j += 1

            avg = (preSum+leftFlowers)//j # 计算可以将这些花园增加到多少
            tmpBeauty = avg*partial+(n-i)*full # 计算当前总美丽值
            res = max(res, tmpBeauty) # 计算答案
        
        return res

if __name__ == "__main__":
    s = Solution()
    flowers = [1,3,1,1]
    newFlowers = 7
    target = 6
    full = 12
    partial = 1
    print(s.maximumBeauty(flowers, newFlowers, target, full, partial))
