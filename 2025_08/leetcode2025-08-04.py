from typing import List
from collections import defaultdict

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        # 不定长滑动窗口，循环过程中保证窗口内只有两种元素即可
        n = len(fruits)
        cnt = defaultdict(int)
        res = 0
        l = 0
        for r in range(n):
            cnt[fruits[r]] += 1
            while len(cnt) > 2:
                cnt[fruits[l]] -= 1
                if cnt[fruits[l]] == 0:
                    cnt.pop(fruits[l])
                l += 1
            res = max(res, r-l+1)
        return res

if __name__ == "__main__":
    s = Solution()
    fruits = [0,1,2,1]
    print(s.totalFruit(fruits))
