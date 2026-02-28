class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        cnt = [0]*26
        modNum = 1_000_000_007
        for c in s:
            cnt[ord(c)-ord('a')] += 1
        res = 0
        for i in range(t):
            res = 0
            cur = [0]*26
            for j in range(26):
                if cnt[j] > 0:
                    if j != 25:
                        cur[j+1] = (cur[j+1]+cnt[j])%modNum
                        res = (res+cnt[j])%modNum
                    else:
                        res = (res+2*cnt[j])%modNum
                        cur[0] = (cur[0]+cnt[j])%modNum
                        cur[1] = (cur[1]+cnt[j])%modNum
            cnt = cur.copy()
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "abcyy"
    t = 2
    print(sl.lengthAfterTransformations(s, t))
