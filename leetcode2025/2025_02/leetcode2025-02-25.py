class Allocator:

    def __init__(self, n: int):
        self.lst = [0]*n

    def allocate(self, size: int, mID: int) -> int:
        cnt = 0
        for i in range(len(self.lst)):
            if self.lst[i]>0:
                cnt = 0
                continue
            cnt += 1
            if cnt == size:
                self.lst[i-size+1:i+1] = [mID]*size
                return i-size+1
        return -1

    def freeMemory(self, mID: int) -> int:
        res = 0
        for i in range(len(self.lst)):
            if self.lst[i] == mID:
                res += 1
                self.lst[i] = 0
        return res

if __name__ == "__main__":
    alct = Allocator(10)
    op = ["allocate","allocate","allocate","freeMemory","allocate","allocate","allocate","freeMemory","allocate","freeMemory"]
    nums = [[1,1],[1,2],[1,3],[2],[3,4],[1,1],[1,1],[1],[10,2],[7]]
    for i in range(len(op)):
        if op[i] == "allocate":
            print(alct.allocate(nums[i][0], nums[i][1]), end = " ")
        else:
            print(alct.freeMemory(nums[i][0]), end = " ")
    print()
