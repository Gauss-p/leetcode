from typing import List

class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        n = len(arr)
        visited = [0]*n
        def dfs(indx):
            if indx >= n or indx < 0 or visited[indx]:
                return False
            if arr[indx] == 0:
                return True
            visited[indx] = 1
            return dfs(indx+arr[indx]) | dfs(indx-arr[indx])
        return dfs(start)

if __name__ == "__main__":
    s = Solution()
    arr = [4,2,3,0,3,1,2]
    start = 5
    print(s.canReach(arr, start))
