class ProductOfNumbers:

    def __init__(self):
        self.preZero = [0]
        self.preProd = [1]

    def add(self, num: int) -> None:
        self.preZero.append(self.preZero[-1]+(num==0))
        self.preProd.append(self.preProd[-1]*max(num, 1))

    def getProduct(self, k: int) -> int:
        if self.preZero[-1] > self.preZero[-k-1]:
            return 0
        return self.preProd[-1]//self.preProd[-k-1]

if __name__ == "__main__":
    pn = ProductOfNumbers()
    op = ["add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
    nums = [[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]
    for i in range(len(op)):
        if op[i] == 'add':
            pn.add(nums[i][0])
        else:
            print(pn.getProduct(nums[i][0]))
