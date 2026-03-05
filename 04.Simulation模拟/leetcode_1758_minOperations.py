class Solution:
    def minOperations(self, s: str) -> int:
        res1 = 0
        cur = 0
        for i in s:
            if i == str(cur):
                res1 += 1
            cur ^= 1
        return min(res1, len(s)-res1)

if __name__ == "__main__":
    sl = Solution()
    s = "10"
    print(sl.minOperations(s))
