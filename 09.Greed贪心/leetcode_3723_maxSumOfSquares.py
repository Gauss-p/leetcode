class Solution:
    def maxSumOfSquares(self, num: int, Sum: int) -> str:
        if Sum/num > 9:
            return ""
        return ('9'*(Sum//9)+str(Sum%9)+'0'*(num-(Sum//9+1)))[:num]

if __name__ == "__main__":
    s = Solution()
    num, Sum = 3, 15
    print(s.maxSumOfSquares(num, Sum))
