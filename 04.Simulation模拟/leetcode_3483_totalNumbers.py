from typing import List

class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        n = len(digits)
        res = set()
        for i in range(n):
            if digits[i]==0:
                continue
            for j in range(n):
                if j==i:
                    continue
                for k in range(n):
                    if k==i or k==j:
                        continue
                    x = digits[i]*100+digits[j]*10+digits[k]
                    if x%2==0:
                        res.add(x)
        return len(res)

if __name__ == "__main__":
    s = Solution()
    digits = [1,2,3,4]
    print(s.totalNumbers(digits))
