from typing import List

class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        # 对于每一个朋友对(a,b)，只要两者所掌握的语言中没有交集，我们就将它标记为待处理朋友对，之后，对于所有的待处理朋友对，我们都选择同一种语言进行教学，因此，朋友对中所有的不会这一种语言的人的总数量就是一个答案。但是我们可以教他们学任意一种语言，因此循环所有的语言，都进行一次计算，取最小的答案即可
        lang = list(map(set, languages))
        lang.insert(0, {})
        teach = []
        for a,b in friendships:
            if len(lang[a].intersection(lang[b])) == 0:
            # if lang[a].isdisjoint(lang[b]):
                teach.append([a,b])

        res = float("inf")
        for k in range(1, n+1):
            ans = 0
            tmp = set()
            for a,b in teach:
                if k not in lang[a]:
                    tmp.add(a)
                if k not in lang[b]:
                    tmp.add(b)
            res = min(res, len(tmp))
        return res

if __name__ == "__main__":
    s = Solution()
    n = 2
    languages = [[1],[2],[1,2]]
    friendships = [[1,2],[1,3],[2,3]]
    print(s.minimumTeachings(n, languages, friendships))
