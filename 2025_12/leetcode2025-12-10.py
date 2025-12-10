from typing import List

modNum = 1_000_000_007
maxNum = 100001
prod = [1]*maxNum # 预处理所有长度的全排列个数
for i in range(2, maxNum):
    prod[i] = (prod[i-1]*i)%modNum

class Solution:
    def countPermutations(self, c: List[int]) -> int:
        # 只要编号大于等于1的一台电脑的复杂度小于等于第0台电脑，就一定无法打开该电脑，因此遍历一次，只要遇到这种情况，直接返回0即可
        # 剩下的就是可以全部被0打开的情况，问题就转化成了除电脑0外剩下所有电脑的全排列个数，循环求解即可
        n = len(c)
        mn = min(c[1:])
        return 0 if mn<=c[0] else prod[n-1]

if __name__ == "__main__":
    s = Solution()
    c = [1,2,3]
    print(s.countPermutations(c))
