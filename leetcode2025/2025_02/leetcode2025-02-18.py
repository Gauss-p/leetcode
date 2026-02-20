from typing import List
from bisect import *
from collections import defaultdict

class RangeFreqQuery:

    def __init__(self, arr: List[int]):
        self.cnt = defaultdict(list)
        for i in range(len(arr)):
            self.cnt[arr[i]].append(i)

    def query(self, left: int, right: int, value: int) -> int:
        return bisect_right(self.cnt[value], right)-bisect_left(self.cnt[value], left)

if __name__ == "__main__":
    arr = [12,33,4,56,22,2,34,33,22,12,34,56]
    rfq = RangeFreqQuery(arr)
    ques = [[1,2,4],[0,11,33]]
    for q in ques:
        print(rfq.query(q[0],q[1],q[2]))
