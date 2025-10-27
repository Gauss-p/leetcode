from typing import List

class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        n = len(bank)
        last = bank[0].count('1')
        res = 0
        for i in range(1, n):
            cur = bank[i].count('1')
            if cur > 0:
                res += last*cur
                last = cur
        return res

if __name__ == "__main__":
    s = Solution()
    bank = ["011001","000000","010100","001000"]
    print(s.numberOfBeams(bank))
