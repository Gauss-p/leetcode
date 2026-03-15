from typing import List

class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
        modNum = 1_000_000_007
        def calcSpace(fence, mx):
            fence.insert(0, 1)
            fence.append(mx)
            space = set()
            for i in range(len(fence)):
                for j in range(i+1, len(fence)):
                    space.add(abs(fence[i]-fence[j]))
            return space
        
        hSpace = calcSpace(hFences, m)
        vSpace = calcSpace(vFences, n)
        
        res = vSpace.intersection(hSpace)
        return (max(res)**2)%modNum if len(res) > 0 else -1

if __name__ == "__main__":
    s = Solution()
    m, n = 4, 3
    hFences = [2,3]
    vFences = [2]
    print(s.maximizeSquareArea(m, n, hFences, vFences))
