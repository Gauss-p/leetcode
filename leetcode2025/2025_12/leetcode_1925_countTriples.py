from math import sqrt

class Solution:
    def countTriples(self, n: int) -> int:
        res = 0
        for i in range(1, n):
            for j in range(i+1, n):
                k_squared = i*i+j*j
                k = int(sqrt(k_squared))
                if k*k==k_squared and k_squared <= n*n:
                    res += 1+(i!=j)
        return res

if __name__ == "__main__":
    s = Solution()
    n = 5
    print(s.countTriples(n))
