class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        pos = [i for i in range(len(s)) if s[i]=='1']
        cur = []
        res = '1'*(len(s)+1)
        for i in range(len(pos)):
            if len(cur) > 0:
                cur.append('0'*(pos[i]-pos[i-1]-1))
            cur.append('1')
            if i < k-1:
                continue
            curS = ''.join(cur)
            if len(curS) < len(res) or (len(curS)==len(res) and curS<res):
                res = curS
            cur.pop(0)
            if len(cur):
                cur.pop(0)
        return '' if res=='1'*(len(s)+1) else res

if __name__ == "__main__":
    sl = Solution()
    s = "100011001"
    k = 3
    print(sl.shortestBeautifulSubstring(s, k))
