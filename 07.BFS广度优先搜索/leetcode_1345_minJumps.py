from typing import List
from collections import defaultdict

class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n = len(arr)
        pos = defaultdict(list)
        for i in range(n):
            pos[arr[i]].append(i)

        q = [0]
        res = 0
        visited = [0]*n
        visited[0] = 1
        while q:
            q2 = []
            for x in q:
                if x == n-1:
                    return res
                if x > 0 and visited[x-1] == 0:
                    visited[x-1] = 1
                    q2.append(x-1)
                if x < n-1 and visited[x+1] == 0:
                    visited[x+1] = 1
                    q2.append(x+1)
                for y in pos[arr[x]]:
                    if visited[y]:
                        continue
                    visited[y] = 1
                    q2.append(y)
                pos[arr[x]] = []
            q = q2
            res += 1
        return -1

if __name__ == "__main__":
    s = Solution()
    arr = [100,-23,-23,404,100,23,23,23,3,404]
    print(s.minJumps(arr))
