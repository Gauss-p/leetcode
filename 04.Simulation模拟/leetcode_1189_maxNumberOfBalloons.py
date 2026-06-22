from collections import Counter

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        origin = Counter("balloon")
        cnt = Counter(text)
        res = 10**18
        for i in origin.keys():
            res = min(res, cnt[i]//origin[i])
        return res

if __name__ == "__main__":
    s = Solution()
    text = "nlaebolko"
    print(s.maxNumberOfBalloons(text))
