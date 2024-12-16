from sortedcontainers import SortedList
from typing import List

class Solution:
    def closestRoom(self, rooms: List[List[int]], queries: List[List[int]]) -> List[int]:
        # 为了方便计算，我们可以将queries按照每个查询中的最小面积从大到小排序，但是又因为题目要求我们按顺序返回答案，所以我们需要将queries的每个元素和它自身的索引一起排序。定义queries的大小为q，我们可以使用一个技巧，即单独排序[0,q]的所有元素，但是排序函数我们定义为lambda i:-queries[i][1]，这样我们就可以将所有序号按照它们对应的查询的第二个值——minSize按照从大到小的顺序排序，其中负号的作用就是反向排序
        # 同时，我们将rooms数组按照房间大小从小到大的顺序进行排序
        # 然后创建一个有序集合 roomId。用双指针遍历 query_id 和 rooms，把房间面积 ≥minSize 的房间号添加到 roomId 中。然后在 roomId 中搜索离 pre 最近的左右两个房间号，其中离 pre 最近的房间号就是答案。
        rooms.sort(key = lambda x:x[1])
        q = len(queries)
        res = [-1]*q
        j = len(rooms)-1
        roomId = SortedList()
        for i in sorted(range(q), key = lambda i:-queries[i][1]):
            per,minSize = queries[i]
            while j>=0 and rooms[j][1] >= minSize:
                roomId.add(rooms[j][0])
                j -= 1
            
            roomIndex = roomId.bisect_left(per)
            diff = float("inf")
            if roomIndex:
                diff = per-roomId[roomIndex-1]
                res[i] = roomId[roomIndex-1]
            if roomIndex < len(roomId) and roomId[roomIndex]-per < diff:
                res[i] = roomId[roomIndex]
        return res

if __name__ == "__main__":
    s = Solution()
    rooms, queries = [[2,2],[1,2],[3,2]], [[3,1],[3,3],[5,2]]
    print(s.closestRoom(rooms, queries))
