class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        preSum, sufSum = [0]*(n+1), [0]*(n+1)
        for i in range(n):
            preSum[i+1] = preSum[i]+(customers[i]=='N')
            sufSum[n-i-1] = sufSum[n-i]+(customers[n-i-1]=='Y')
        
        cost = float("inf")
        res = 0
        for i in range(n+1):
            cur = preSum[i]+sufSum[i]
            if cur < cost:
                cost = cur
                res = i
        return res

if __name__ == "__main__":
    s = Solution()
    customers = "YYNY"
    print(s.bestClosingTime(customers))
