class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        res = 0
        while num1 != 0 and num2 != 0:
            if num1 >= num2:
                res += num1//num2
                num1 %= num2
            else:
                res += num2//num1
                num2 %= num1
        return res

if __name__ == "__main__":
    s = Solution()
    num1, num2 = 2, 3
    print(s.countOperations(num1, num2))
