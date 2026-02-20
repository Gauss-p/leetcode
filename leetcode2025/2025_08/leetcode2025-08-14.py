class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        # 判断该数字的三进制中是否有2即可，如果有，就说明不能用多个3的幂构成，返回False，否则返回True
        while n:
            if n%3==2:
                return False
            n //= 3
        return True

if __name__ == "__main__":
    s = Solution()
    n = 12
    print(s.checkPowersOfThree(n))
