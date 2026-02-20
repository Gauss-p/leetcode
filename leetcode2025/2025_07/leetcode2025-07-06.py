from typing import List
from collections import Counter

class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.NUMS1 = nums1
        self.NUMS2 = nums2
        self.cnt1 = Counter(nums1)
        self.cnt2 = Counter(nums2)

    def add(self, index: int, val: int) -> None:
        self.cnt2[self.NUMS2[index]] -= 1
        self.NUMS2[index] += val
        self.cnt2[self.NUMS2[index]] += 1

    def count(self, tot: int) -> int:
        res = 0
        for k in self.cnt1.keys():
            if tot-k in self.cnt2:
                res += self.cnt1[k]*self.cnt2[tot-k]
        return res

if __name__ == "__main__":
    nums1 = [1,1,2,2,2,3]
    nums2 = [1,4,5,2,5,4]
    fsp = FindSumPairs(nums1, nums2)
    ops = ["count","add","count","count","add","add","count"]
    vals = [[7],[3,2],[8],[4],[0,1],[1,1],[7]]
    for i, op in enumerate(ops):
        if op == "count":
            print(fsp.count(vals[i][0]))
        else:
            fsp.add(vals[i][0], vals[i][1])
