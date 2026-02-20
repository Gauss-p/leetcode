class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        res = ""
        indx = 0
        for i in range(0, len(s), k):
            if indx&1:
                res += s[i:i+k]
            else:
                res += s[i:i+k][::-1]
            indx += 1
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "abcdefg"
    k = 2
    print(sl.reverseStr(s, k))
