from typing import List
from heapq import *

class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        # 记mx为nums的初始最大值，我们可以发现，如果经过若干次操作，可以使得未操作过的mx变成数组中的最小值，那么在这之后，每进行n次操作，数组nums中的所有元素都会被乘一遍multiplier，因为当mx变成数组中的最小值时，数组中其他任何一个元素y都满足mx<=y<=multiplier*mx，所以只要开始乘，就会将整个数组循环一遍
        # 其证明过程如下：如果y>multiplier*mx，根据我们的条件可以知道除mx外任何一个元素都已经至少被乘过一次multiplier，所以y至少也被乘过一次multiplier，那么在进行一次操作之前的y值y/multiplier > mx，不满足mx为最大值的条件，矛盾。所以对于数组中任何一个元素都满足y<=multiplier*mx，这样我们就可以证明，只要mx成为了数组中的最小值，之后的所有操作都是在数组中循环进行的
        # 所以我们可以利用小顶堆，不断地进行操作，直到发现堆顶元素变成了nums初始最大值mx，就退出循环。在这之后的所有操作都可以循环进行，所以我们可以发现，数组中的每一个元素都需要至少乘(k/n)次multiplier，同时因为k/n可能还有余数，所以对于数组的前(k%n)个元素我们还需要多乘一次multiplier，这个操作可以通过循环来进行
        if multiplier == 1:
            # 如果乘数为1，那么无论乘多少次都没有意义，返回nums即可
            return nums
        n,m = len(nums), int(1e9+7)
        mx = max(nums) # 取出nums初始最大值
        v = [(num, i) for i,num in enumerate(nums)] # 创建小顶堆
        heapify(v)
        while v[0][0]<mx and k:
            # 刚开始按顺序执行操作，直到mx成为堆顶元素，即最小值的时候就退出循环
            k -= 1 # 每操作一次总次数就减1
            num,i = heappop(v) # 进行操作
            heappush(v, (num*multiplier,i))
        v.sort()
        for i in range(n):
            # 对于每个元素，都需要至少乘multiplier**(k/n)，同时因为之后进行的是循环操作，所以对于数组中前(k%n)个元素要多乘一次multiplier
            times = k//n + (i < k%n)
            nums[v[i][1]] = ((v[i][0]%m) * pow(multiplier, times, m)) % m # python中的pow就是快速幂，不需要重新写
        return nums

if __name__ == "__main__":
    s = Solution()
    nums = [2,1,3,5,6];
    k,multiplier = 5,2
    print(s.getFinalState(nums,k,multiplier))
