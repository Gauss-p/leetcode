class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        cur = 0
        res = 0
        newNum = str(num)
        for i in range(len(newNum)):
            cur = cur*10+int(newNum[i])
            if i<k-1:
                continue
            if cur!=0 and num%cur == 0:
                res += 1
            cur = cur%(10**(k-1))
        return res

if __name__ == "__main__":
    s = Solution()
    num, k = 240, 2
    print(s.divisorSubstrings(num, k))
