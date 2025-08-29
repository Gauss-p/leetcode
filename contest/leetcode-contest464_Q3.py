from typing import List

class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        # 分析题目，可以知道，对于每一个位置，我们要么跳转到后面数字比当前位置小的位置，要么跳转到前面数字比当前位置大的位置，又因为题目要求我们对每一个位置求出最大可以跳转到的数值，所以我们理论上来说应当尽可能的往前面跳。但是有一种特殊情况：如果当前位置之后有比当前数字小的位置，并且两个位置之间有一个数字比当前数字还大，那么我们就可以先往后跳一下再往前跳一下，这样就可以到达一个数值更大，却在当前位置之后的地方。因此，其实总共就是两种跳法，一种是直接往前，一种是借助之后一个更小的元素跳到两者之间的更大元素
        # 如果是第一种跳法，很简单，每一个位置的答案就是当前位置对应的前缀最大值。但是对于第二种跳法，我们需要从后往前来考虑。首先，假如我们已经求出nums的前缀最大值preMax和后缀最小值sufMin，其中preMax[i]=max(nums[:i+1])，且sufMin[i]=min(nums[i:])，那么在什么情况下我们不能进行第二种跳转呢？如果对于一个位置i，有preMax[i]<=sufMin[i+1]，就说明i之前的所有数字都比i之后的任意一个数字还要小，那么此时就不可能进行第二种跳转，只能进行第一种，也就是res[i]=preMax[i]
        # 而如果此时preMax[i]>sufMin[i+1]，我们就可以进行一些变换：首先，将i跳跃到nums[:i+1]中的最大值的位置，这一定是合法的，因为在nums[:i+1]中，第i个位置就是最后一个位置，所以无论如何，最大值的位置都在第i个位置之前；接下来，将i跳跃到nums[i+1:]之中的最小值位置，这也是合法的，因为已知前面部分的最大值大于后面部分的最小值了；然后，将i从nums[i+1:]中最小值位置跳到i+1的位置，这同样合法，因为i+1就是nums[i+1:]数组的起点，最小值位置无论如何都在它之后。这样，经过三次跳转，第i个位置的元素就可以跳到第i+1个位置，因此我们有：res[i]=res[i+1]。注意到第i个位置的答案可能和第i+1个位置的答案有关，所以我们可以从后往前遍历
        # 综上，可以得到：从后往前计算答案，如果preMax[i]<=sufMin[i+1]，那么res[i]=preMax[i]，否则res[i]=res[i+1]
        # 需要注意的是，在从后往前遍历的时候，我们可以同时维护一个变量sufMin，用来记录nums[i+1:]的最小值，这样也可以省去一个列表和一些循环
        n = len(nums)
        preMax = [0]*n # 前缀最大值
        preMax[0] = nums[0]
        for i in range(1, n):
            preMax[i] = max(preMax[i-1], nums[i])
        # sufMin = [float("inf")]*(n+1)
        # for i in range(n-1, -1, -1):
        #     sufMin[i] = min(sufMin[i+1], nums[i])
        res = [0]*n
        res[n-1] = preMax[n-1] # 为了防止res[i]=res[i+1]指令超出限制，我们先预处理res[n-1]的值
        sufMin = nums[n-1] # 后缀最小值
        for i in range(n-2, -1, -1):
            if preMax[i] <= sufMin:
                # 第一种跳转
                res[i] = preMax[i]
            else:
                # 第二种跳转
                res[i] = res[i+1]
            sufMin = min(sufMin, nums[i])
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [2,3,1]
    print(s.maxValue(nums))
