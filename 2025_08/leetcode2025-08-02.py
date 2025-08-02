from typing import List
from collections import defaultdict

class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        # 为了选择更好的方案，我们需要先找出两个篮子中相同水果的数量之差，这样我们就能够知道要交换哪些水果，然后才能选择更优的交换方式。因此我们先用一个defaultdict来统计basket1和basket2中各个元素出现次数之差，默认将1中的元素加入并将2中的元素减去即可
        # 接下来，有了两组数据的单个元素出现次数之差，就可以计算应当将多少个该元素移动。假如A中比B中多了4个X元素，那么只有将4//2=2个X从A中移动到B中才能使两组数据中的X元素数量变为相等。所以在计算需要移动的元素个数时，如果该元素的出现次数之差是奇数，就说明不可能将它移动至两侧相等，故直接返回-1。否则，我们就将出现(次数之差除以2)个元素展开成一行，并加入一个列表中，之后只需在这个列表中两两选取进行交换即可
        # 由于两两选取后交换时都是取最小值的，因此直接将该列表排序，取前面一半元素求和即可。注意这里不需要考虑是否会选到位于同一个列表中的元素是因为，只要选取列表中前面一半的元素，就说明只要将它们一一和后面的元素交换即可达到我们的目的，而如果是一一交换的话，无论如何这些元素在min运算后都还是它们本身
        # 但是注意，如果将basket1中的3和basket2中的4交换，代价是3，但是假如这时basket2中有一个1，那么我们先将basket1中的3和这个1交换，然后将换到basket1中的1再和4交换，总共的代价只有1*2=2，因此我们发现，交换两个元素的最小代价可以是basket1和basket2中所有元素的最小值乘以2，所以在计算的时候需要和这个值取最小再加入答案
        n = len(basket1)
        cnt = defaultdict(int) # 记录相同元素出现次数之差
        mnCost = float("inf")
        for i in range(n):
            cnt[basket1[i]] += 1
            cnt[basket2[i]] -= 1
            mnCost = min(mnCost, basket1[i], basket2[i]) # 求所有元素的最小值

        tot = []
        for k, v in cnt.items():
            if abs(v)%2:
                # 奇数是不可能平均分成两半的
                return -1
            tot += [k]*(abs(v)//2) # 展开
        if len(tot) == 0:
            return 0

        tot.sort()
        mnCost *= 2 # 因为如果用最小值，需要交换两次，所以代价就是最小值的两倍
        res = 0
        for i in range(len(tot)//2):
            res += min(tot[i], mnCost) # 注意要和可能的最小代价比较
        return res

if __name__ == "__main__":
    s = Solution()
    basket1 = [4,2,2,2]
    basket2 = [1,4,1,2]
    print(s.minCost(basket1, basket2))
