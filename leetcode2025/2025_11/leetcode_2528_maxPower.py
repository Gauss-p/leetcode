from typing import List

class Solution:
    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        # 为了确定每一个城市在新建电站之后的电量，我们首先需要根据题目给出的电站列表stations来计算最初情况下每一个城市的电量。而这个的计算可以使用前缀和。首先求出给出的电站数组的前缀和，然后对于每一个位置确定可以传输到当前位置的最左侧和最右侧位置，用前缀和数组中的两个对应值做差即可得到当前位置的城市的电量
        # 接下来，我们需要确定在所有策略中，最小的城市电量的最大值，考虑到这是最小最大问题，我们可以用二分查找的方式来计算答案。定义二分查找中的判断函数为check(mid)，用来计算所有的城市电量最小值是否能够达到mid，如果可以返回True，否则返回False。为了实现这个，我们需要用到差分数组，如果我们在一个位置i向右r个长度的位置i+r放置了一个电站，那么这个电站最远可以影响到i+2*r的位置，因此为了表示这一区间内所有位置的电量加1，我们就可以使用差分数组
        # 接下来，我们采用在循环的同时更新差分数组，因此，在循环的开始，我们需要先用sumDiff还原出当前位置的电量，接下来，如果当前电量curPower小于给出的最小值，我们就需要通过新增电站的方式使其达到最小电量，而由于在前面的所有位置上我们都已经保证了电量大于给出最小值，因此当前需要增加的电站最好要让它的影响范围的最左侧是当前位置，也就是在当前位置向右r个位置放置一个电站，然后更新差分数组中电站最右侧能够影响的点右边一个值。注意，当我们在增加电站的时候，需要时刻关注当前总增加电站数量是否大于了给定的k，如果大于，就说明无法让所有城市的最小电量到达给出最小值
        # 最后，用二分查找确定最终答案即可
        n = len(stations)
        preSum = [0]*(n+1) # 前缀和数组
        for i in range(n):
            preSum[i+1] = preSum[i]+stations[i]

        curElectric = [0]*n # 最初各个城市的电量
        for i in range(n):
            left = max(0, i-r)
            right = min(n-1, i+r)+1
            curElectric[i] = preSum[right]-preSum[left]
        
        def check(mid): # 判断函数
            sumDiff = 0
            diff = [0]*(n+1) # 差分数组
            used = 0
            for i in range(n):
                sumDiff += diff[i]
                curPower = curElectric[i]+sumDiff
                if curPower < mid: # 需要新增电站
                    sub = mid-curPower # 为了让当前电量达到mid，需要增加mid-curPower个电站
                    used += sub # 更新已增加电站数量
                    if used > k:
                        return False
                    sumDiff += sub
                    curRight = min(n-1, i+2*r) # 当前电站能够影响的最右端点
                    diff[curRight+1] -= sub # 为了让之后循环到这个位置时去除当前新增电站的影响
            return True

        res = 0
        left, right = min(curElectric), max(curElectric) + k + 1
        while left<=right:
            mid = (left+right)//2
            if check(mid):
                res = mid
                left = mid+1
            else:
                right = mid-1
        return res


if __name__ == "__main__":
    s = Solution()
    stations = [1,2,4,5,0]
    r, k = 1, 2
    print(s.maxPower(stations, r, k))
