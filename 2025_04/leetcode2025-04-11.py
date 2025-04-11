class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        def check(x):
            tot, half, n = 0, 0, 0
            y = x
            while y>0:
                tot += (y%10)
                y //= 10
                n += 1
            if n&1:
                return False
            n //= 2
            while x>0 and n>0:
                half += (x%10)
                x //= 10
                n -= 1
            return tot == half*2
        
        res = 0
        for i in range(low, high+1):
            if check(i):
                res += 1
        return res

        # res = 0
        # for i in range(low, high+1):
        #     tmp = list(map(int, list(str(i))))
        #     n = len(tmp)
        #     if n%2 == 0 and sum(tmp[:n//2])*2==sum(tmp):
        #         res += 1
        # return res

if __name__ == "__main__":
    s = Solution()
    low = 1
    high = 100
    print(s.countSymmetricIntegers(low, high))
