from typing import List
from collections import deque

class Solution:
    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        tasks.sort()
        workers.sort()

        def check(k):
            i = 0
            p = pills
            # q = []
            q = deque()
            for j in workers[-k:]:
                while i<k and tasks[i]<=j+strength:
                    q.append(tasks[i])
                    i += 1
                if not q:
                    return False
                if j >= q[0]:
                    # q.pop(0)
                    q.popleft()
                    continue
                if p == 0:
                    return False
                q.pop()
                p -= 1
            return True

        l = 0
        r = min(len(tasks), len(workers))+1
        while l+1<r:
            mid = (l+r)//2
            if check(mid):
                l = mid
            else:
                r = mid
        return l

if __name__ == "__main__":
    s = Solution()
    tasks = [3,2,1]
    workers = [0,3,3]
    pills = 1
    strength = 1
    print(s.maxTaskAssign(tasks, workers, pills, strength))
