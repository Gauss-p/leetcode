from typing import List
from functools import cache

class Solution:
    def maxPartitionsAfterOperations(self, s: str, k: int) -> int:
        # 根据题目，我们可以发现，我们最多只能修改一个位置的英文字母，同时，在计算分割数量的时候，我们每一次都要选择s中的最长前缀，而这个最长就限定了一件事情：在选择前缀的时候，当且仅当前缀中的字母种类第一次加到大于k时，我们才能将不包含最后一个字母的前缀分为一组，只有这样，才能保证题目的最长
        # 因此我们可以考虑dfs的思路，在dfs函数中传入3个参数来描述当前的情况：i,mask,changed，其中i表示当前处理到s[i]的位置，mask是一个一共有26位的二进制数字，每一个位置上是否为1就说明了在最近的上一个前缀中是否出现了字母表中该位置的字母，而changed则表示在前缀中是否进行了一次字母改变
        # 那么对于一个位置i，首先有两种情况，一种是不改变s[i]，一种是改变s[i]。在不改变s[i]时，如果在已选前缀中加入s[i]会使得前缀中字母的总种类数超过k，那么就说明必须从s[i]开始新开一个前缀，否则就说明必须将s[i]加入上一个前缀中。而如果要改变s[i]，那么就循环s[i]可能改变的所有的25个字母，分别进行尝试，每一次的尝试中都有两种情况，而这两种则跟上面的不改变s[i]时的两种判断相同了
        n = len(s)
        @cache
        def dfs(i, mask, changed):
            if i == n:
                return 1 # 递归基，无论如何都要结束一个段了
            ans = 0
            bit = 1<<(ord(s[i])-ord('a')) # 当前字母对应的二进制位
            newMask = mask | bit # 前缀中加入当前字母
            if newMask.bit_count() > k:
                # 需要分出一段，则将递归后的答案加1
                ans = dfs(i+1, bit, changed)+1
            else:
                # 不需分段，则直接加入当前字母
                ans = dfs(i+1, newMask, changed)
            if not changed:
                for j in range(26):
                    # 改为字母表中第j个字母
                    curBit = 1<<j
                    if curBit == bit:
                        continue
                    newMask = mask | curBit
                    if newMask.bit_count() > k:
                        # 分段
                        ans = max(ans, dfs(i+1, curBit, True)+1)
                    else:
                        # 不分段
                        ans = max(ans, dfs(i+1, newMask, True))
            return ans
        return dfs(0, 0, False)

if __name__ == "__main__":
    sl = Solution()
    s = "accca"
    k = 2
    print(sl.maxPartitionsAfterOperations(s, k))
