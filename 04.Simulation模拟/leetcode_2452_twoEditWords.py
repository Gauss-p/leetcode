from typing import List

class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        res = []
        for s in queries:
            flag = False
            for d in dictionary:
                if len(s) != len(d):
                    continue
                if sum(1 for i in range(len(s)) if s[i] != d[i]) <= 2:
                    flag = True
                    break
            if flag:
                res.append(s)
        return res

if __name__ == "__main__":
    s = Solution()
    queries = ["word","note","ants","wood"]
    dictionary = ["wood","joke","moat"]
    print(s.twoEditWords(queries, dictionary))
