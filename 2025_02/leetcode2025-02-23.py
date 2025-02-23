from collections import defaultdict

class Skiplist:

    def __init__(self):
        self.dic = defaultdict(int)

    def search(self, target: int) -> bool:
        return target in self.dic and self.dic[target]!=0

    def add(self, num: int) -> None:
        self.dic[num] += 1

    def erase(self, num: int) -> bool:
        if num not in self.dic or self.dic[num]==0: return False
        self.dic[num] -= 1
        return True

if __name__ == "__main__":
    s = Skiplist()
    op = ["add","add","add","search","add","search","erase","erase","search"]
    nums = [[1],[2],[3],[0],[4],[1],[0],[1],[1]]
    for i in range(len(op)):
        if op[i]=="add":
            s.add(nums[i][0])
        elif op[i]=="search":
            print(s.search(nums[i][0]))
        else:
            print(s.erase(nums[i][0]))
