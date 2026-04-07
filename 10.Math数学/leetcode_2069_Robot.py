from typing import List

class Robot:

    def __init__(self, width: int, height: int):
        self.w, self.h = width, height
        self.totLength = 2*(width+height)-4
        self.pos = 0
        self.start = False

    def step(self, num: int) -> None:
        self.start = True
        self.pos = (self.pos+num-1)%self.totLength+1
    
    def _getState(self):
        if self.pos <= self.w-1:
            return [self.pos, 0, "East"]
        if self.pos <= self.w+self.h-2:
            return [self.w-1, self.pos-self.w+1, "North"]
        if self.pos <= 2*self.w+self.h-3:
            return [self.w-(self.pos-self.w-self.h+2)-1, self.h-1, "West"]
        return [0, self.h-(self.pos-2*self.w-self.h+3)-1, "South"]

    def getPos(self) -> List[int]:
        return self._getState()[:2]

    def getDir(self) -> str:
        return self._getState()[2]

if __name__ == "__main__":
    r = Robot(6,3)
    ops = ["step","step","getPos","getDir","step","step","step","getPos","getDir"]
    nums = [[2],[2],[],[],[2],[1],[4],[],[]]
    for i in range(len(ops)):
        numStr = ""
        if len(nums[i]):
            numStr = str(nums[i][0])
        cmdstr = "r."+ops[i]+"("+numStr+")"
        print(eval(cmdstr))
