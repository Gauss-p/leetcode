from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        candidates.append(101)
        # 首先对candidates数组进行排序后分组，这样的操作是为了防止答案中出现重复。举个例子，如果candidates = [2,2,1,3,5,5,4]，那么对它排序后分组的结果即为[[1,1],[2,2],[3,1],[4,1],[5,2]]，其中每一个子列表的第一个元素代表数值，第二个元素代表该值的个数。我们将这个结果存入列表newC中
        newC = []
        length = 1
        for i in range(1, len(candidates)):
            if candidates[i] == candidates[i-1]:
                length += 1
            else:
                newC.append([candidates[i-1], length])
                length = 1

        # 定义dfs函数，dfs(x, score)的答案表示:从newC中索引为x的子列表开始选择，选择前的总和为score，那么最终的解集是什么。根据这个定义，我们可以得到该题目的答案即为dfs(0,0)。因为题目中要求不能重复，所以我们在之前先对candidates进行排序后分组，这样我们就可以明确知道每一种数字可以选几个以及当前已经选了几个，在计算过程中就不会出现重复。我们用vis数组存储每个数字分别选了几个。这样，在score累计到达target时，我们就可以根据vis还原出所选的所有数字，记录答案即可。
        n = len(newC)
        vis = [0]*n # 存储每个数字选择的个数
        def dfs(x, score):
            if score == target:
                # 还原选的所有数字
                tmp = []
                for i in range(n):
                    for j in range(vis[i]):
                        tmp.append(newC[i][0])
                return [tmp]
            if score > target or x == n:
                # 超出target后就再也不可能恰好凑够target，所以返回空列表，代表没有答案
                return []
            ans = []
            for i in range(newC[x][1]+1):
                vis[x] = i
                ans += dfs(x+1, score+i*newC[x][0]) # 统计所有答案
                vis[x] = 0
            return ans
        return dfs(0, 0)

if __name__ == "__main__":
    s = Solution()
    candidates = [10,1,2,7,6,1,5]
    target = 8
    print(s.combinationSum2(candidates, target))
