from typing import List
from random import shuffle

class Solution:
    def generateSchedule(self, n: int) -> List[List[int]]:
        # 假如用一个初始的场次列表尽可能地排列出一个合法的赛程，我们就需要每一次在选择下一个场次的时候都需要和上一次进行的比赛进行判断，只有没有重叠的时候才能够加入列表中并继续，但，如果进行测试，我们会发现，单纯一个初始场次列表可能会在计算过程中导致到最后没有一个场次可以继续选下去，因此我们需要变换不同的场次列表
        # 如何变换不同的场次列表呢？我们可以每一次将初始的场次列表用shuffle函数进行打乱，然后再进行一次上面所说的计算，每一次尽可能的往后填充赛程，而在打乱的过程中，只要发现有一次打乱后的初始场次可以生成一个合法的赛程，我们就直接返回生成出来的赛程，结束循环
        # 也许有两次shuffle打乱的结果是相同的，但是由于题目没有规定一定要什么顺序，所以合法的赛程可能有很多种，我们只需要在打乱的同时碰巧蒙到一种合法的就可以了，只不过为了让找到答案的概率更大，我们需要打乱更多次，经过测试，总共打乱10次也是可以通过的，只不过通过的概率会变小，偶尔才能通过，但如果打乱1000次甚至5000次，不通过的概率基本上就是0了
        if n<=4: # 这里可以特殊判断
            return []

        for _ in range(1000):
            pairs = [[i,j] for i in range(n) for j in range(n) if i!=j] # 初始场次列表
            shuffle(pairs) # 打乱
            res = []
            pre0, pre1 = -1, -1
            while pairs:
                flag = False # 看当前能不能找到一个场次能排在res之后，如果不能，就继续下一次的打乱
                for i in range(len(pairs)):
                    if pre0 not in pairs[i] and pre1 not in pairs[i]: # 合法
                        pre0, pre1 = pairs[i]
                        res.append(pairs[i])
                        pairs.pop(i)
                        flag = True # 找到了
                        break
                if not flag: # 没找到，就直接继续下一次打乱
                    break
            if len(pairs)==0: # 只有当所有场次都被用完，才能返回答案
                return res
        return []

if __name__ == "__main__":
    s = Solution()
    n = 5
    print(s.generateSchedule(n))
