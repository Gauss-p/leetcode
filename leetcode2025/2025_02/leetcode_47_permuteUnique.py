from typing import List

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        vis = [0]*n
        tmp = []
        res = set()
        def dfs(i):
            if sum(vis) == n:
                res.add(tuple(tmp))
                return
            for j in range(n):
                if vis[j] == 0:
                    vis[j] = 1
                    tmp.append(nums[j])
                    dfs(j)
                    tmp.pop()
                    vis[j] = 0
        dfs(-1)
        return list(map(list, res))

if __name__ == "__main__":
    s = Solution()
    nums = [1,1,2]
    print(s.permuteUnique(nums))
