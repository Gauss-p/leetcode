from typing import List

class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        nums = []
        while n:
            nums.append(n&(-n))
            n ^= (n&(-n))

        preProduct = [1]*(len(nums)+1)
        for i in range(len(nums)):
            preProduct[i+1] = preProduct[i]*nums[i]
        
        modNum = 1_000_000_007
        res = []
        for l,r in queries:
            res.append((preProduct[r+1]//preProduct[l])%modNum)
        return res

if __name__ == "__main__":
    s = Solution()
    n = 15
    queries = [[0,1],[2,2],[0,3]]
    print(s.productQueries(n, queries))
