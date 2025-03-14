class Solution:
    def isBalanced(self, num: str) -> bool:
        n = len(num)
        odd, even = 0, 0
        for i in range(n):
            if i&1:
                odd += int(num[i])
            else:
                even += int(num[i])
        return odd==even

if __name__ == "__main__":
    s = Solution()
    num = "1234"
    print(s.isBalanced(num))
