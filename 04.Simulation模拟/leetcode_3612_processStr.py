class Solution:
    def processStr(self, s: str) -> str:
        res = ""
        for i in s:
            if i == "*":
                res = res[:-1]
            elif i == "#":
                res += res
            elif i == "%":
                res = res[::-1]
            else:
                res += i
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "a#b%*"
    print(sl.processStr(s))
