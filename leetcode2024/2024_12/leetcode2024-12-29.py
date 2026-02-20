from typing import List
from collections import defaultdict

class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        m = len(votes[0])
        dic = defaultdict(lambda: [0]*m)
        for v in votes:
            for i in range(m):
                dic[v[i]][i] -= 1
        # 直接利用列表比较大小的特性，就可以实现将各个队伍按照从·排位第1·的票数开始比较并进行排序
        # 那么对于所有排位票数都相同的情况下，还需要按字母顺序进行排序，那么我们在排序的时候再加入一个队列名称即可
        return ''.join(sorted(dic, key = lambda c:(dic[c], c))) # 按照题目要求排序，并整合成一个字符串

if __name__ == "__main__":
    s = Solution()
    votes = ["ABC","ACB","ABC","ACB","ACB"]
    print(s.rankTeams(votes))
