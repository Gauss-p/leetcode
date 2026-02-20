from typing import List

class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        # 首先我们需要将第0个数字增加到target[0]，需要用target[0]次操作
        # 接下来，对于第i个数字(i>=1)，如果target[i-1]>target[i]，那么在将0变为target[i-1]的同时就可以将0变为target[i]，这样不需要额外花费任何操作。如果target[i-1]<target[i]，那么在将0变为target[i-1]之后还需要多余target[i]-target[i-1]次操作才能将0变为target[i]，因此需要将res加上target[i]-target[i-1]
        res = target[0]
        for i in range(len(target)-1):
            if target[i+1]-target[i] > 0:
                res += (target[i+1]-target[i])
        return res
        # return sum(max(0, target[i+1]-target[i]) for i in range(len(target)-1))+target[0]

if __name__ == "__main__":
    s = Solution()
    target = [1,2,3,2,1]
    print(s.minNumberOperations(target))
