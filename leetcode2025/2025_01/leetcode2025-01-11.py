class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        res,cnt = 0,0
        while num1>0 and num2>0 and num3>0:
            res += min(num1%10, num2%10, num3%10)*(10**cnt)
            cnt += 1
            num1,num2,num3 = num1//10,num2//10,num3//10
        return res

if __name__ == "__main__":
    s = Solution()
    num1,num2,num3 = 1,10,1000
    print(s.generateKey(num1,num2,num3))
