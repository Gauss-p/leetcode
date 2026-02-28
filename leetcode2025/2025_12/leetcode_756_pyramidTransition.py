from typing import List
from collections import defaultdict
from functools import cache

class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        # 根据allowed列表，我们可以归纳出每一组底边两个字母对应的所有合法的顶点字母，因此，对于给出的一行，我们可以按照归类生成所有可能的上面一行，因此可以用dfs的方式，从最底部的一行bottom开始向上查询，每次都找所有可能的上一行，然后再次传入函数，直到出现到达某一层只有单个字母的时候，就说明找到了一个合法的、且以bottom为底边的金字塔，这时直接返回True，即可一层一层直接传回最初的函数，从而返回True；但如果我们将所有可能的上一行都传入dfs函数中试过了，却没有得到任何一个True的答案，直接返回False即可
        groups = defaultdict(list)
        for a,b,c in allowed:
            groups[a+b].append(c)
        
        @cache
        def dfs(line):
            if len(line)==1:
                return True
            ans = False
            mode = set() # 记录所有可能的上一行
            for i in range(len(line)-1):
                cur = line[i:i+2]
                if cur not in groups:
                    return False
                if len(mode) == 0:
                    mode = set(groups[cur])
                    continue

                newMode = set()
                for c in groups[cur]:
                    for x in mode:
                        newMode.add(x+c) # 将已存储的所有字符串都加上一个字符，这样就可以得到全排列
                mode = newMode.copy()
            
            for s in mode:
                if dfs(s):
                    return True
            return False

        return dfs(bottom)

if __name__ == "__main__":
    s = Solution()
    bottom = "BCD"
    allowed = ["BCC","CDE","CEA","FFF"]
    print(s.pyramidTransition(bottom, allowed))
