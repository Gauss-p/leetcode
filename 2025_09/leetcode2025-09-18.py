from typing import List
from heapq import *

class TaskManager:
    # 维护一个字典，用每一个任务的编号作为键，分别存储这个编号对应的任务的对应用户和优先级。那么在添加和修改的函数中，我们都只需要将其任务编号对应的信息修改即可，而在删除函数中，我们采用延迟删除的方式，将一切删除操作全部放在最后一个函数中，而在删除函数中仅仅用[-1, -1]来标记其被删除了即可
    # 同时维护一个优先级队列，也就是小根堆，每次弹出所有的任务中优先级最大同时任务编号最大的那个任务。那么在添加和修改的函数中，我们都只需将其整个信息按照对应顺序加入列表中即可，但由于延迟删除的方式，我们在删除函数中先不进行删除操作，而是在执行任务的函数中不断弹出堆顶元素，不过由于可能出现更改和删除，导致该任务不存在了，因此我们需要和最新信息也就是字典中的数据进行比对，只有两者相同的时候才返回用户编号
    def __init__(self, tasks: List[List[int]]):
        self.task = {}
        self.todo = []
        for u, t, p in tasks:
            self.task[t] = (u, p)
            heappush(self.todo, (-p, -t, u))

    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.task[taskId] = (userId, priority)
        heappush(self.todo, (-priority, -taskId, userId))

    def edit(self, taskId: int, newPriority: int) -> None:
        curUserId = self.task[taskId][0]
        self.add(curUserId, taskId, newPriority)

    def rmv(self, taskId: int) -> None:
        self.task[taskId] = (-1, -1)

    def execTop(self) -> int:
        while len(self.todo)>0:
            p, t, u = heappop(self.todo)
            if self.task[-t] == (u, -p):
                self.rmv(-t)
                return u
        return -1

if __name__ == "__main__":
    origion = [[1,101,10],[2,102,20],[3,103,15]]
    tm = TaskManager(origion)
    op = ["add","edit","execTop","rmv","add","execTop"]
    num = [[4,104,5],[102,8],[],[101],[5,105,15],[]]
    for i in range(len(op)):
        if op[i] == "add":
            tm.add(num[i][0], num[i][1], num[i][2])
        if op[i] == "edit":
            tm.edit(num[i][0], num[i][1])
        if op[i] == "execTop":
            print(tm.execTop())
        else:
            tm.rmv(num[i][0])
