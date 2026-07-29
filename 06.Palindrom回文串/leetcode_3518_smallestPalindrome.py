maxNum = 10001
prod = [1]*maxNum
for i in range(1, maxNum):
    prod[i] = prod[i-1]*i

def comb(m, n):
    return prod[m]//(prod[m-n]*prod[n])

class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        n = len(s)
        left = s[:n//2]
        cnt = [0]*26
        for c in left:
            cnt[ord(c)-ord('a')] += 1

        # def calc(tot):
        #     ans = prod[tot]
        #     for i in cnt:
        #         if i == 0:
        #             continue
        #         ans //= prod[i]
        #     return ans
        val = prod[n//2]
        for i in cnt:
            if i == 0:
                continue
            val //= prod[i]

        left = ''.join(sorted(left))
        res = ""
        counted = 0
        for i in range(n//2):
            for j in range(26):
                if cnt[j]:
                    cnt[j] -= 1
                    # cur = calc(n//2-i-1)
                    cur = val*(cnt[j]+1)//(n//2-i)
                    if counted+cur >= k:
                        val = cur
                        res += chr(ord('a')+j)
                        break
                    counted += cur
                    cnt[j] += 1

        if len(res) < n//2:
            return ""

        res = res+(s[n//2] if n&1 else '')+res[::-1]
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "abba"
    k = 2
    print(sl.smallestPalindrome(s, k))
