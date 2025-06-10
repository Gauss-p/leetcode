from collections import Counter

class Solution:
    def maxDifference(self, s: str) -> int:
        cnt = Counter(s)
        oddMx, evenMn = 0, float("inf")
        for c, v in cnt.items():
            if v&1:
                oddMx = max(oddMx, v)
            else:
                evenMn = min(evenMn, v)
        return oddMx-evenMn

if __name__ == "__main__":
    sl = Solution()
    s = "aaaaabbc"
    print(sl.maxDifference(s))
