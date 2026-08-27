from functools import cache
from collections import Counter

class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        maxest = "".join(sorted(list(s), reverse = True))
        if maxest <= target:
            return ""
        n = len(s)
        cnt = Counter(s)
        @cache
        def dfs(indx, cur, flag):
            if flag == True:
                leftS = ""
                for k,v in cnt.items():
                    leftS += k*v
                return cur+"".join(sorted(list(leftS)))
            if indx == n:
                if cur > target:
                    return cur
                return "{"*n
            ans = '{'*n
            for k in cnt.keys():
                if (k < target[indx] and flag == False) or cnt[k] == 0:
                    continue
                cnt[k] -= 1
                if k == target[indx]:
                    ans = min(ans, dfs(indx+1, cur+k, flag))
                else:
                    ans = min(ans, dfs(indx+1, cur+k, True))
                cnt[k] += 1
            return ans
        res = dfs(0, "", False)
        return "" if res=='{'*n else res

if __name__ == "__main__":
    sl = Solution()
    s, target = "abc", "bba"
    print(sl.lexGreaterPermutation(s, target))
