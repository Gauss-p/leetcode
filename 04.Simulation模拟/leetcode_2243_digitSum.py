class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            ns = [sum(map(int, s[i:i+k])) for i in range(0, len(s), k)]
            s = ''.join(list(map(str, ns)))
        return s

if __name__ == "__main__":
    sl = Solution()
    s = "11111222223"
    k = 3
    print(sl.digitSum(s, k))
