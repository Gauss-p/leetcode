class Solution:
    def maxProduct(self, n: int) -> int:
        lst = sorted(list(map(int, list(str(n)))), reverse = True)
        return lst[0]*lst[1]

if __name__ == "__main__":
    s = Solution()
    n = 31
    print(s.maxProduct(n))
