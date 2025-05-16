from typing import List

class Solution:
    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        # 定义动态规划数组dp，其中dp[i]表示从下标[i,n-1]中可以选择出来的以words[i]为起点的最长子序列的长度，根据定义可以发现如果要求出dp[i]，我们需要知道它之后的所有值，因此采用倒序遍历是更好的选择。
        # 将下标i从n-1到0倒序遍历，同时用另一个下标j从i+1到n-1正序遍历，对于每一个下标j，如果我们想将dp[i]从dp[j]转移过来，式子就是dp[i]=dp[j]+1，但前提是必须满足如下的条件:1.words[i]和words[j]的汉明距离为1，2.groups[i]!=groups[j]，但是为了避免计算出比dp[i]还小的答案，我们可以再增加一个限制条件dp[j]>dp[i]，这样就可以保证每一次计算出来的答案都是比当前dp[i]更大的。
        # 同时，如果后面没有一个下标j可以满足上面的条件，那么我们也需要将dp[i]置为1，意思就是只选当前单词，为了统一上面的dp[j]+1和这里的1，我们可以将dp中所有数值的初始值都设置为0，并在每次循环到合适的下标j时只更新dp[i]为dp[j]，一直到j的循环结束后再将dp[i]加1
        # 但是题目要求我们求出子序列中的内容而非子序列的长度，所以我们可以设置一个from_列表，长度为n，其中的from_[i]表示i接下来一个应该跳转到那个下标，所以我们需要知道的只有最大的dp[i]对应的i值，这样我们就可以通过from_数组还原所有的单词了
        def check(s1, s2):
            # 判断汉明距离是否为1
            if len(s1)!=len(s2) or s1==s2:
                return False
            diff = 0
            for i in range(len(s1)):
                if s1[i] != s2[i]:
                    diff += 1
                if diff >= 2:
                    return False
            return True

        n = len(groups)
        dp = [0]*n # 动态规划数组
        from_ = [-1]*n # 记录路径的数组
        max_indx = n-1
        for i in range(n-1, -1, -1):
            for j in range(i+1, n):
                if dp[j] > dp[i] and groups[i] != groups[j] and check(words[i], words[j]):
                    # 如果满足三个条件就更新dp[i]，同时将i之后的最佳转移位置更新为j
                    dp[i] = dp[j]
                    from_[i] = j
            dp[i] += 1
            if dp[i] > dp[max_indx]:
                # 保存最长子序列的开头
                max_indx = i
        
        res = []
        while max_indx != -1:
            # 还原路径
            res.append(words[max_indx])
            max_indx = from_[max_indx]
        return res

# ===================================================================================================================================

        # def hammingDis(s1, s2):
        #     ans = 0
        #     for i in range(len(s1)):
        #         if s1[i] != s2[i]:
        #             ans += 1
        #     return ans
        # n = len(groups)
        # @cache
        # def dfs(indx, path):
        #     ans = ()
        #     curPath = list(path)
        #     for i in range(indx+1, n):
        #         if indx==-1 or (groups[i]!=groups[indx] and len(words[i])==len(words[indx]) and hammingDis(words[i], words[indx])==1):
        #             curPath.append(words[i])
        #             tmp = dfs(i, tuple(curPath))
        #             if len(tmp) > len(ans):
        #                 ans = tmp
        #             curPath.pop()
        #     if len(path) > len(ans):
        #         ans = path
        #     return ans
        # return list(dfs(-1, tuple()))

if __name__ == "__main__":
    s = Solution()
    words = ["bab","dab","cab"]
    groups = [1,2,2]
    print(s.getWordsInLongestSubsequence(words, groups))
