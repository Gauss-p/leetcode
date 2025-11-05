from typing import List
from collections import defaultdict
from sortedcontainers import SortedList

class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        # 用滑动窗口的思路，分别使用两个有序列表维护窗口内出现次数最大的x个元素和其余的所有元素，将出现次数最大的x个元素按照(cnt[v],v)的形式存入lstMax中，即出现次数在前，元素在后，同时将其余的元素按照同样的形式存入lstRest中，这样我们就能够按照题目要求的顺序来从小到大排序所有的元素
        # 接下来，我们需要维护这两个有序列表，但是如果我们单纯对于当前位置对应的值进行次数的统计，并不能够实现在两个有序列表中的元素变化，因此我们需要单独的两个函数来分别向窗口中增加元素和减少元素。由于在主函数中调用的时候不会出现重复加入的情况，因此不需要考虑v在两个有序列表中已经出现过的情况
        # 首先是增加元素v，那么根据对两个有序列表中元素的要求，我们真正需要加入的是元组(cnt[v], v)。接下来就是将其存入哪一个列表的问题：如果当前元组大于lstMax中最小的那个元组，说明当前元组可以被列入最大的x个元素当中，因此将其加入lstMax中；否则就说明当前元组无法被纳入最大的x个元素，因此需要将其加入lstRest中
        # 其次是减去元素v，同样，我们真正需要减去的是元组(cnt[v], v)，由于在将元组加入两个有序列表中时，我们是仅仅加入其中一个，因此只需判断即可确定应当在哪个有序列表中删除该元组：如果该元组出现在lstMax中，那就在lstMax中删除该元组，否则就在lstRest中删除该元组
        # 根据两个函数的定义可以发现，当我们需要将一个元素v的出现次数从x改为y(y=x-1 or y=x+1)时，需要先调用删除函数将元组(x, v)删除，然后再将(y, v)加入

        # 接下来在滑动窗口的循环中，对于窗口中的元素我们已经分好组了，一组lstMax，一组lstRest，但是在单纯的加减元组的过程中我们并没有保证lstMax的长度大小，因此还需在每一次循环中对lstMax的长度进行分情况处理：如果len(lstMax)<x，那么就将lstRest中最大的元组转移到lstMax中，否则就将lstMax中最小的元组转移到lstRest中
        # 在处理完毕之后，我们就可以通过对lstMax求和得出res对应位置的答案了
        # 注意：在计算的过程中，我们可以始终维护lstMax中的和，即在两个函数中对总和进行加减操作，同时在滑动窗口中对于lstMax的长度的分情况处理时也同时进行加减，这样即可减少求和时的时间
        def add(v):
            if cnt[v] == 0:
                return
            p = (cnt[v], v)
            if lstMax and p > lstMax[0]: # 当前元组可以加入前x个元素当中
                lstMax.add(p)
                nonlocal curSum
                curSum += p[0]*p[1] # 维护lstMax中的和
            else:
                lstRest.add(p)

        def remove(v):
            if cnt[v] == 0:
                return
            p = (cnt[v], v)
            if p in lstMax: # 加在lstMax当中
                lstMax.remove(p)
                nonlocal curSum
                curSum -= p[0]*p[1] # 维护lstMax中的和
            else: # 加在lstRest当中
                lstRest.remove(p)

        lstMax = SortedList()
        lstRest = SortedList()
        cnt = defaultdict(int) # 统计各个数字出现频次
        curSum = 0

        n = len(nums)
        res = [0]*(n-k+1)
        for i in range(n):
            v = nums[i]
            remove(v) # 更新当前元素
            cnt[v] += 1
            add(v)

            j = i-k+1 # 窗口左端点
            if j<0:
                continue
            
            while lstRest and len(lstMax) < x: # 长度不够x个
                p = lstRest.pop()
                lstMax.add(p)
                curSum += p[0]*p[1]
            
            while len(lstMax) > x: # 长度超过x个
                p = lstMax.pop(0)
                lstRest.add(p)
                curSum -= p[0]*p[1]
            
            res[j] = curSum # 记录答案
            # 移除左端点处元素
            remove(nums[j])
            cnt[nums[j]] -= 1
            add(nums[j])
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,1,2,2,3,4,2,3]
    k, x = 6, 2
    print(s.findXSum(nums, k, x))
