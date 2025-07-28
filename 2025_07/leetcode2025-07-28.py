from typing import List

class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = 0
        mx = 0
        def dfs(indx, val):
            if indx == n:
                nonlocal mx,cnt
                if mx < val:
                    mx = val
                    cnt = 1
                elif mx == val:
                    cnt += 1
                return
            dfs(indx+1, val|nums[indx])
            dfs(indx+1, val)
        dfs(0, 0)
        return cnt

if __name__ == "__main__":
    s = Solution()
    nums = [3,1]
    print(s.countMaxOrSubsets(nums))
