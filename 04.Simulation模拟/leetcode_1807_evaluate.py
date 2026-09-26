from typing import List

class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        mp = dict()
        for k,v in knowledge:
            mp[k] = v
        
        res = ""
        cur = ""
        for i in s:
            if i == ')':
                res += mp.get(cur[1:], '?')
                cur = ""
            elif i == '(' or len(cur) > 0:
                cur += i
            else:
                res += i
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "(name)is(age)yearsold"
    knowledge = [["name","bob"],["age","two"]]
    print(sl.evaluate(s, knowledge))
