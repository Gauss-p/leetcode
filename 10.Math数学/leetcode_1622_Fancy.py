modNum = 1_000_000_007
class Fancy:

    def __init__(self):
        self.lst = []
        self.addNum = 0
        self.mulNum = 1

    def append(self, val: int) -> None:
        self.lst.append(((val-self.addNum)*pow(self.mulNum, -1, modNum))%modNum)

    def addAll(self, inc: int) -> None:
        self.addNum += inc

    def multAll(self, m: int) -> None:
        self.mulNum = (self.mulNum*m)%modNum
        self.addNum = (self.addNum*m)%modNum

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.lst):
            return -1
        return (self.lst[idx]*self.mulNum + self.addNum)%modNum

if __name__ == "__main__":
    f = Fancy()
    ops = ["append","addAll","append","multAll","getIndex","addAll","append","multAll","getIndex","getIndex","getIndex"]
    nums = [[2],[3],[7],[2],[0],[3],[10],[2],[0],[1],[2]]
    for i in range(len(ops)):
        if ops[i] == "append":
            f.append(nums[i][0])
        elif ops[i] == "addAll":
            f.addAll(nums[i][0])
        elif ops[i] == "multAll":
            f.multAll(nums[i][0])
        else:
            print(f.getIndex(nums[i][0]))
