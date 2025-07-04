from typing import List
from string import *

class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        # 利用3304题目的方法，我们发现，可以将k-1的二进制单独取出来进行判断，对于3304题而言，因为每一次操作都是需要更改的，因此答案就需要累加k-1的二进制中1的个数，每出现一个1就需要更改一次答案
        # 但是现在题目已经给出了每一次是否操作，因此我们需要对每一位1的组成进行判断，当前是否操作过，如果操作过，就需要更改一次答案，否则就不需要
        # 因此我们累加所有二进制位是1并且当前位有进行操作过的个数，返回它在字母表中对应的字母即可，又因为可能出现大于26的索引，因此我们需要对它进行模除后返回答案
        k -= 1
        m = k.bit_length()
        res = 0
        for i in range(m-1, -1, -1):
            if k>>i & 1 and operations[i]==1:
                res += 1
        return ascii_lowercase[res%26]

if __name__ == "__main__":
    s = Solution()
    k = 5
    operations = [0,0,0]
    print(s.kthCharacter(k, operations))
