from typing import List

class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        # 贪心地想,肯定是要找到一种顺序使得按照这个顺序完成所有任务所需要的最初花费最小.可以发现,如果在最初执行的任务中,执行完后剩余的能量值越大,那么想要执行下一个任务所需要增加的能量值就越小,这样就可以更加充分地利用最初多余的那些能量,因此,可以按照执行完任务后的剩余能量值从大到小排序所有任务,排序之后的顺序一定是所需最初能量最少的那个顺序
        # 但由于根据顺序计算总能量的时候不好计算,需要从后往前遍历计算才能根据「完成后面所有任务的所需的最少初始能量」来计算再完成当前任务所需的最少初始能量,因此可以直接按每个任务的minimum-actual(即完成该任务剩余能量)值从小到大排序,再顺序遍历即可计算最少初始能量
        tasks.sort(key = lambda x:x[1]-x[0])
        res = 0
        for i in range(len(tasks)):
            res = max(res+tasks[i][0], tasks[i][1])
        return res

if __name__ == "__main__":
    s = Solution()
    tasks = [[1,2],[2,4],[4,8]]
    print(s.minimumEffort(tasks))
