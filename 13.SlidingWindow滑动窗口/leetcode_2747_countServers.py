from typing import List
from collections import defaultdict

class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        # 分析题目，实际上需要做的只是要求一个定长滑动窗口在不同位置时，其中的不同元素数量。因此可以考虑用滑动窗口实现。
        # 首先将queries进行排序，同时将logs按照时间进行排序。定义两个指针l和r，表示logs[l:r+1]中的元素的时间均处在选定的长度为x的时间范围中，因此对于一个新的范围，即一个新的queries中的元素pos，只需要将r向右移动直到logs[r][1]超过pos，同时将l向右移动直到logs[l][1]到达pos-x的右侧，与此同时维护其中不同元素的总数，即可得到pos对应的时间范围内不同的server_id总数量active，用n-active即可得到当前位置对应的答案
        logs.sort(key = lambda x:x[1])
        queries = sorted((v,i) for i,v in enumerate(queries))
        active = 0
        res = [0]*len(queries)
        cnt = defaultdict(int)
        l, r = 0, 0

        for v,i in queries:
            while r<len(logs) and logs[r][1]<=v:
                if cnt[logs[r][0]] == 0:
                    # 新出现的server_id，不同元素数量加1
                    active += 1
                cnt[logs[r][0]] += 1
                r += 1
            
            while l<len(logs) and logs[l][1]<v-x:
                cnt[logs[l][0]] -= 1
                if cnt[logs[l][0]] == 0:
                    # 将当前的server_id删完了，窗口内不同元素数量减1
                    active -= 1
                l += 1

            res[i] = n-active
        return res

if __name__ == "__main__":
    s = Solution()
    n = 3
    logs = [[1,3],[2,6],[1,5]]
    x = 5
    queries = [10,11]
    print(s.countServers(n, logs, x, queries))
