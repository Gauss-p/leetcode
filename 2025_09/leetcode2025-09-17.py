from collections import defaultdict
from sortedcontainers import SortedList

class NumberContainers:
    # 维护一个位置字典，其中存储每一个数字出现的所有位置，并用SortedList存储，这样就可以自动排序，返回时直接返回该数字对应的SortedList中第一个元素即可
    # 同时维护一个数字字典，其中存储每一个位置当前对应的数字，在更新元素的时候，如果给出的位置并没有在该字典中，就直接创建一个新的键值对，同时更新位置字典中该数字所出现的位置。而如果之前记录过该位置，那么我们就需要更改其数字字典中的值，同时更新位置字典中原先的数值和新的数值出现过的位置列表，这里弹出的时候只需用bisect_left查找其索引即可
    def __init__(self):
        self.pos = defaultdict(SortedList)
        self.num = defaultdict(int)

    def change(self, index: int, number: int) -> None:
        if index not in self.num:
            # 没有记录过该位置，直接更新
            self.num[index] = number
            self.pos[number].add(index)
        else:
            # 记录过该位置，需将原来数字的位置列表中弹出该位置，并将新数字的位置列表中加入该位置
            old = self.num[index]
            self.num[index] = number
            idx = self.pos[old].bisect_left(index)
            self.pos[old].pop(idx)
            self.pos[number].add(index)

    def find(self, number: int) -> int:
        if len(self.pos[number]):
            return self.pos[number][0]
        return -1

if __name__ == "__main__":
    nc = NumberContainers()
    op = ["find","change","change","change","change","find","change","find"]
    nums = [[10],[2,10],[1,10],[3,10],[5,10],[10],[1,20],[10]]
    for i in range(len(op)):
        if op[i] == "find":
            print(nc.find(nums[i][0]))
        else:
            nc.change(nums[i][0], nums[i][1])
