from typing import List

class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        def check(a, b, c):
            if b < 1:
                return False
            b -= 1
            tot = 1+min(b, c)*2+a
            if b > c:
                tot += 1
            return tot<len(stones) and tot%2 == 1

        cnt = [0]*3
        for i in stones:
            cnt[i%3] += 1

        return check(cnt[0], cnt[1], cnt[2])|check(cnt[0], cnt[2], cnt[1])

if __name__ == "__main__":
    s = Solution()
    stones = [2,1]
    print(s.stoneGameIX(stones))
