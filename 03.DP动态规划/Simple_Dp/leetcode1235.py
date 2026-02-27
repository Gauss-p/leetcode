from typing import List
from bisect import *

class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        # 为了方便起见，我们将所有的工作组合成一个二维列表jobs，其中每一个jobs[i]长度为3，三个元素分别是该工作的开始时间，结束时间和工作报酬，即startTime[i], endTime[i], profit[i]，然后将每一份工作按照jobs[i][1]排序
        # 动态规划，定义dp[i]表示在前i份工作中能够获取的最大工作总报酬，那么对于dp[i]，它有两种组成方式，一种是进行第i份工作，一种是不进行第i份工作。因此答案就是dp[n]，其中n=len(startTime)
        # 如果是后者，因为如果不包括第i份工作的总报酬，在前i份工作中能够获取的最大总报酬，就可以直接看作在前i-1份工作中能够获取的最大总报酬，因此那么dp[i]就可以直接由上一个值转移过来，即dp[i] = dp[i-1]；
        # 如果是前者，那么为了进行第i份工作，我们必须找到在第i份工作开始之前就已经结束的最后一份工作，其中“最后一份工作”是为了保证最大值，因为进行越多工作就越能达到更高的总报酬。那么这就启示我们可以利用二分查找，在排序后的工作结束时间中寻找最后一份结束时间小于等于第i份工作开始时间的工作，因此，我们可以将“第i份工作”定义为在按照工作结束时间排序后的jobs中索引为i-1的工作。回到递推关系式，我们就可以先求出最后一份结束时间小于等于第i份工作开始时间的工作的索引indx，然后，注意dp中和jobs中的索引是相差1的，因此转移时需要将indx+1，即dp[i] = dp[indx+1]+jobs[i-1][2]，其中val就是第i份工作的报酬
        # 因此，对于dp[i]，它的递推关系式就应该是dp[i] = max(dp[i-1], dp[indx+1]+jobs[i-1][2])
        # 注意，在寻找前一份工作时，我们需要保证该工作在第i份工作之后
        n = len(startTime)
        jobs = list(zip(startTime, endTime, profit)) # 合并所有会议，保证排序的时候不会乱
        jobs.sort(key = lambda x:x[1])
        endTime.sort() # 两者都排序，在endTime中二分的结果就可以直接利用在jobs中
        dp = [0]*(n+1)
        for i in range(1, n+1):
            dp[i] = dp[i-1]
            indx = bisect_right(endTime, jobs[i-1][0])-1 # 寻找最后一个结束时间小于等于第i个工作开始时间的工作
            if indx+1 < i: # 保证indx在i之前
                dp[i] = max(dp[i], dp[indx+1]+jobs[i-1][2])
        return dp[n]

if __name__ == "__main__":
    s = Solution()
    startTime = [1,2,3,3]
    endTime = [3,4,5,6]
    profit = [50,10,40,70]
    print(s.jobScheduling(startTime, endTime, profit))
