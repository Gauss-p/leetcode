from collections import defaultdict

class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        dic = defaultdict(int)
        res = 0
        for i in s:
            dic[i] += 1
            y = abs(dic["N"]-dic["S"])
            x = abs(dic["E"]-dic["W"])
            tmp = x+y
            tmp += 2*min(k,min(dic["E"],dic["W"])+min(dic["N"],dic["S"]))
            res = max(res, tmp)
        return res
            

if __name__ == "__main__":
    sl = Solution()
    s = "NWSE"
    k = 1
    print(sl.maxDistance(s, k))
