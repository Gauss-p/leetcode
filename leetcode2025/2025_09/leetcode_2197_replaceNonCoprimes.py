from typing import List
from math import *

class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        # 由于题目中已经说明计算结果和计算顺序无关，因此我们可以从左到右计算，每次将新的数字加入答案列表中，只要发现答案列表中的最后两个数字非互质，就将它们弹出，并将两者的最小公倍数加入列表，每一次都这样处理到最后两个数字互质为止，最终返回答案列表即可
        st = []
        i = 0
        while i<len(nums):
            st.append(nums[i])
            while len(st)>1 and gcd(st[-1], st[-2])>1:
                a, b = st.pop(), st.pop()
                st.append(lcm(a, b))
            i += 1
        return st

if __name__ == "__main__":
    s = Solution()
    nums = [6,4,3,2,7,6,2]
    print(s.replaceNonCoprimes(nums))
