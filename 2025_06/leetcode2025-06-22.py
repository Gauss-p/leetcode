from typing import List

class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        res = []
        for i in range(0, len(s), k):
            res.append(s[i:i+k]+(k-len(s[i:i+k]))*fill)
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "abcdefghij"
    k = 3
    fill = "x"
    print(sl.divideString(s, k, fill))
