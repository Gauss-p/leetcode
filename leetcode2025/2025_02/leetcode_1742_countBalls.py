from collections import defaultdict

class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        cnt = defaultdict(int)
        for i in range(lowLimit, highLimit+1):
            tmp = sum(map(int, str(i)))
            cnt[tmp] += 1
        return max(cnt.values())

if __name__ == "__main__":
    s = Solution()
    lowLimit, highLimit = 1, 10
    print(s.countBalls(lowLimit, highLimit))
