from typing import List
from collections import deque

class Solution:
    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        # 用二分查找来寻找可以完成的任务数量，因此左端点就是0，右端点就应设置为总任务数量和总工人数量的最小值
        # 为了判断当前的任务数量是否可以完成，我们需要定义一个判断函数check来控制左右端点的移动。在判断的时候，我们应用贪心的思路，尽量让最强的工人去做最简单的工作，这样更能确保任务能够完成，而对于那些确定要吃药才能完成当前最简单的任务的工人，我们就要让这颗药丸发挥最大的作用，也就是让这个工人吃药以后尽可能地去做最困难的工作。
        # 为了实现以上的功能，我们首先将任务数组和工人数组全部从小到大排序，当函数的传入值为k的时候，我们就是要判断workers[-k:]这些工人是否能完成tasks[k:]这些任务。我们定义一个双端队列，用来存储当前工人可以完成的所有任务(包括吃药以后)，所以在每次循环到一个新的、能力值为j的工人的时候，我们就将之后的难度小于等于j+strength的所有任务加入队列中。之后判断当前工人是否能完成最简单的工作(注意:因为我们前面所有的操作都没有改变任务难度大小的顺序，所以无论何时队列中的任务难度都是从小到大排序的，所以最简单的任务就是q[0]，最难的任务就是q[-1])，也就是说我们要判断j是否大于等于q[0]，如果判断为真，那么就让该工人完成最简单的这个任务，将q[0]弹出队列即可，而如果判断为假，则当前工人为了完成任务必须要吃药，此时就要尽可能地让这个工人干最难的活，那么将q[-1]弹出队列，同时将剩余药片个数p减1
        # 接下来判断边界，如果在统计完当前工人(吃药后)可以完成的所有任务后，任务队列还是空的，说明该工人无法完成任何任务，返回False；同时如果在我们认定该工人需要吃药时剩余药片个数为0，那么也说明他无法完成任何任务，返回False
        tasks.sort()
        workers.sort()

        def check(k):
            i = 0 # 该值用来标识在tasks中的索引
            p = pills # 剩余药片个数
            # q = []
            q = deque() # 经过测试，双端队列的运行时间是449ms，而列表运行时间为3009ms，双端队列效率更高
            for j in workers[-k:]:
                while i<k and tasks[i]<=j+strength:
                    # 加入之后所有的当前工人(吃药后)可以完成的任务
                    q.append(tasks[i])
                    i += 1
                if not q:
                    # 当前工人吃药后也无法完成任何任务
                    return False
                if j >= q[0]:
                    # 当前工人不吃药就可以完成最简单的任务
                    # q.pop(0)
                    q.popleft()
                    continue
                if p == 0:
                    # 当前工人无药可吃
                    return False
                # 当前工人吃药后完成最难的任务
                q.pop()
                p -= 1
            return True

        # 二分查找
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
