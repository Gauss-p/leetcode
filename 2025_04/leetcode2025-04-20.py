from typing import List
from collections import Counter

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        # 读题可知，如果有x只兔子都回答x-1，那么这些兔子就可以组成一个整体。因此，如果有x只兔子都回答y，那么首先可以组成x//(y+1)个整体，每个整体都有y+1只兔子，同时对于x中剩余的兔子，它们至少可以组成一个整体(尽管个数不够，但我们可以假设有一些没回答)，因此在刚才的答案的基础上我们还要再增加一组，为了处理x%(y+1)=0的情况，我们可以用(x+(y+1)-1)//(y+1)来计算所有整体的个数，再将其乘以(y+1)即可
        cnt = Counter(answers)
        res = 0
        for kv in cnt.items():
            res += ((kv[1]+kv[0])//(kv[0]+1))*(kv[0]+1)
        return res

if __name__ == "__main__":
    s = Solution()
    answers = [1,1,2]
    print(s.numRabbits(answers))
