from typing import List

class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        spaces = set(spaces)
        n = len(s)
        res = ""
        for i in range(n):
            if i in spaces:
                res += " "
            res += s[i]
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "LeetcodeHelpsMeLearn"
    spaces = [8,13,15]
    print(sl.addSpaces(s, spaces))
