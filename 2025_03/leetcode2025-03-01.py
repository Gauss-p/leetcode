from typing import List

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        path = []
        res = []
        # lastIndx表示上一个回文子串的结束位置，当前就要从该位置开始往后找
        def dfs(lastIndx):
            if lastIndx == n-1:
                return [path.copy()]
            ans = []
            for i in range(lastIndx+1, n):
                tmp = s[lastIndx+1:i+1]
                if tmp == tmp[::-1]:
                    # 只有当该串回文时才继续往后找
                    path.append(tmp)
                    ans += dfs(i)
                    path.pop()
            return ans
        return dfs(-1)
        # def dfs(lastIndx):
        #     if lastIndx == n-1:
        #         res.append(path.copy())
        #         return
        #     for i in range(lastIndx+1, n):
        #         tmp = s[lastIndx+1:i+1]
        #         if tmp == tmp[::-1]:
        #             path.append(tmp)
        #             dfs(i)
        #             path.pop()
        # dfs(-1)
        # return res

if __name__ == "__main__":
    sl = Solution()
    s = "aab"
    print(sl.partition(s))
