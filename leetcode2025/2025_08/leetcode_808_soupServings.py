from functools import cache

class Solution:
    def soupServings(self, n: int) -> float:
        # 用dfs的方式，其中dfs(i,j)的返回值为：当A中剩余汤为i并且B中剩余汤为j时的答案。注意到题目中所有取法中取出的值中，都是25的倍数，因此为了计算方便，我们可以将题目给出的容量n除以25向上取整，这样每一次操作的时候就相当于直接减去1或2或3或4了。对于返回值，如果发现i和j同时小于等于0，就直接返回1/2，如果只有i小于等于0，那么直接返回1，如果只有j小于等于0，那么直接返回0，题目中的概率0.25在递归中的“归”时乘一下即可
        # 注意，注意到题目中的：“返回值在正确答案 10-5 的范围内将被认为是正确的”，因此我们可以自己编写测试用例，找到最小的并且能够使得答案为0.99999的n的值，在最开始的时候直接判断如果n大于该值就返回1即可
        if n >= 4276:
            return 1
        @cache
        def dfs(i, j):
            if i<=0 and j<=0:
                return 0.5
            if i<=0:
                return 1
            if j<=0:
                return 0
            return 0.25*(dfs(i-4, j)+dfs(i-3, j-1)+dfs(i-2, j-2)+dfs(i-1, j-3))
        return dfs((n+24)//25, (n+24)//25)

if __name__ == "__main__":
    s = Solution()
    n = 4275
    print(s.soupServings(n))
