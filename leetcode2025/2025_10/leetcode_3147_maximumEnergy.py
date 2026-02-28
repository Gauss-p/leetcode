from typing import List

class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        # 找出每一个路径的共同点，其实就是每一条路径上的所有索引模除k都是相等的，因此我们以模除k的余数作为分组标准，分出k个组分别计算即可。但是如果我们从前往后计算，就无法保证每一条找到的路径都是直接到达序列的末端，因此我们需要从后往前计算，每一次算出一条合法路径就用答案记录下来最大值即可
        res = -float("inf")
        tot = [0]*k
        for i in range(len(energy)-1, -1, -1):
            tot[i%k] += energy[i]
            if tot[i%k] > res:
                res = tot[i%k]
        return res

if __name__ == "__main__":
    s = Solution()
    energy = [5,2,-10,-5,1]
    k = 3
    print(s.maximumEnergy(energy, k))
