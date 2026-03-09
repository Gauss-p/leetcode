from functools import cache

class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        # 可以发现，当总长度定下来的时候，如果确定了末尾数字，那么只需要处理前面的规模更小的数组即可，也就是说，如果确定末尾填写0还是填写1，那么剩下的问题就变成了一个相似但规模更小的子问题。因此可以用dfs的方式解决
        # 定义dfs(i, j, k)用来计算：剩余还需填写i个0和j个1，并且末尾数字填写k时的稳定二进制数组总数量，如果不考虑limit的限制，最简单的想法就是倒数第二个位置填0或1都没关系，即直接得到：dfs(i, j, 0)=dfs(i-1, j, 0)+dfs(i-1, j, 1)，同时dfs(i, j, 1)=dfs(i, j-1, 0)+dfs(i, j-1, 0)，这是没有考虑limit的限制的
        # 然后要加上limit的限制，怎么办？可以发现，如果当前的末尾数字填写了k，那么根据题目要求，在此处必须要保证在末尾不能连续出现limit+1个k，但原算法中并不能精确保证一定将最后的连续重复元素段长度控制在一定范围内，故如果要去除所有的「结尾连续出现limit+1个k」的情况，就需要对前面的元素进行考虑。可以发现，如果要将末尾limit+1个位置全部置为k，可以去掉后limit+1个位置，只考虑前面部分的情况总数。假如此时k=0，那么前面部分的情况总数就应当是dfs(i-limit-1, j, 1)，这里之所以将倒数第limit+1个位置置为和k不同的数字，是为了让dfs函数计算的所有情况都是合法情况，只有这样才能进行记忆化操作，而之后，这个计算出来的数量就是在dfs(i, j, 0)中计算出来的不合法的数组总数量，因此dfs(i, j, 0)还需要在dfs(i-1, j, 0)+dfs(i-1, j, 1)的基础上继续减去dfs(i-limit-1, j, 1)才行，即：
        # dfs(i, j, 0) = dfs(i-1, j, 0)+dfs(i-1, j, 1)-dfs(i-limit-1, j, 1)
        # 同理有：
        # dfs(i, j, 1) = dfs(i, j-1, 0)+dfs(i, j-1, 1)-dfs(i, j-limit-1, 0)
        # 至此，所有的递推式已经完成
        # 接下来考虑递归基：首先，如果传入的i或j已经为负值，那么计算就没有意义，直接返回0；其次，如果i=0，那么当且仅当当前位填1且剩余的j<=limit时才说明可以将剩余的所有数字填上且满足“稳定”要求，返回1，否则0；同理如果j=0，那么当且仅当当前位填0且剩余的i<=limit时才说明可以将剩余所有数字填上且满足“稳定”要求，返回1，否则0
        modNum = 1_000_000_007
        @cache
        def dfs(i, j, k):
            if i<0 or j<0:
                return 0
            if i == 0: # 递归基
                return k==1 and j<=limit
            if j == 0:
                return k==0 and i<=limit
            if k == 0:
                return (dfs(i-1, j, 0) + dfs(i-1, j, 1) - dfs(i-limit-1, j, 1))%modNum # 注意减去不合法情况
            else:
                return (dfs(i, j-1, 0) + dfs(i, j-1, 1) - dfs(i, j-limit-1, 0))%modNum
        
        return (dfs(zero, one, 0) + dfs(zero, one, 1))%modNum

if __name__ == "__main__":
    s = Solution()
    zero = 1
    one = 1
    limit = 2
    print(s.numberOfStableArrays(zero, one, limit))
