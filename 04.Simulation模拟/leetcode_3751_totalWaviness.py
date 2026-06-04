class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        def calc(v):
            s = str(v)
            ans = 0
            for i in range(1, len(s)-1):
                if s[i-1]<s[i] and s[i]>s[i+1]:
                    ans += 1
                if s[i-1]>s[i] and s[i]<s[i+1]:
                    ans += 1
            return ans
        res = 0
        for i in range(num1, num2+1):
            res += calc(i)
        return res

if __name__ == "__main__":
    s = Solution()
    num1, num2 = 120, 130
    print(s.totalWaviness(num1, num2))
