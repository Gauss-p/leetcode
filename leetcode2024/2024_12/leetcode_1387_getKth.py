class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        def getVal(x):
            cnt = 0
            while x>1:
                if x&1:
                    x = x*3+1
                else:
                    x //= 2
                cnt += 1
            return cnt
        
        vals = [(i,getVal(i)) for i in range(lo, hi+1)]
        vals.sort(key = lambda x:x[1])
        return vals[k-1][0]

if __name__ == "__main__":
    s = Solution()
    lo, hi, k = 12, 15, 2
    print(s.getKth(lo, hi, k))
