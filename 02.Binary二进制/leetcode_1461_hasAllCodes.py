class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        n = len(s)
        cur = 0
        maxNum = 1<<k
        totNums = [0]*maxNum
        for i in range(n):
            cur = (cur<<1) | int(s[i])
            if i<k-1:
                continue
            totNums[cur] = 1
            cur ^= (int(s[i-k+1])<<(k-1))
        
        return 0 not in totNums

if __name__ == "__main__":
    sl = Solution()
    s = "00110110"
    k = 2
    print(sl.hasAllCodes(s, k))
