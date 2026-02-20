from typing import List

class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        # 定义两个列表hasKey和hasBox，其中hasKey[i]表示当前我们是否拿到第i个盒子的钥匙，hasBox[i]表示当前我们是否拿到了第i个盒子，那么我们可以知道，只要对于一个盒子x满足hasKey[x]=1且hasBox[x]=1，就说明我们现在可以打开第x个盒子
        # 那么首先初始化两个数组，根据题意可以知道，如果status[i]=1，就说明我们现在已经可以打开第i个盒子，那么对应的，相当于我们现在已经有第i个盒子的钥匙了，即需要将hasKey[i]置为1，为了方便，直接将status的所有值赋给hasKey即可，而对于给出的initialBoxes，如果盒子的索引在它里面，就说明我们现在得到了这个盒子，相应的，就应该将hasBox索引对应的位置变为1
        # 用dfs，每一次进入dfs(x)就说明当前我们可以打开第x个盒子，那么为了防止重新打开这个盒子，就需要将hasBox[x]变回0，同时统计答案，将candies[x]累计入答案，接下来进行两步操作：
        #       1.遍历keys[x]，用y遍历，就说明如果打开了盒子x，就可以得到第y个盒子的钥匙，那么将hasKey[y]变为1，但是如果要打开盒子y，我们需要保证当前得到了盒子y，也就是需要在hasBox[y]=1的情况下才能继续进行dfs(y)
        #       2.遍历containedBoxes[x]，还是用y遍历，但这时表示的是当打开盒子x以后可以得到盒子y，也就是需要将hasBox[y]变为1，但如果要打开盒子y，还需要拥有盒子y的钥匙，即需要在hasKey[y]=1的情况下才能继续进行dfs(y)
        # 那么最终计算答案的方式就是遍历所有的盒子编号，如果当前hasKey[i]=1且hasBox[i]=1，才可以进行dfs(i)的计算。注意，这里也可以不需要遍历所有编号，只需要遍历initialBoxes中的编号即可，因为每次计算都会从该盒子出发将所有可以打开的盒子都打开一遍，不会少计算，但我们还需要每次判断是否满足hasKey[i]=1且hasBox[i]=1，因为在dfs中可能会更改两个列表中的值

        n = len(status)
        hasKey = status # 初始化
        hasBox = [0]*n
        for i in initialBoxes:
            hasBox[i] = 1

        res = 0
        def dfs(x):
            # 每次进入函数都累计答案
            nonlocal res
            res += candies[x]
            hasBox[x] = 0 # 防止重复计算

            for y in keys[x]:
                # 拿到y盒子的钥匙，还需要得到y盒子才能打开它
                hasKey[y] = 1
                if hasBox[y]:
                    dfs(y)

            for y in containedBoxes[x]:
                # 得到y盒子，还需要拿到y盒子的钥匙才能打开它
                hasBox[y] = 1
                if hasKey[y]:
                    dfs(y)

        for i in range(n):
            if hasBox[i] and hasKey[i]:
                # 将所有当前满足打开条件的盒子都计算一遍
                dfs(i)

        return res

if __name__ == "__main__":
    s = Solution()
    status = [1,0,1,0]
    candies = [7,5,4,100]
    keys = [[],[],[1],[]]
    containedBoxes = [[1,2],[3],[],[]]
    initialBoxes = [0]
    print(s.maxCandies(status, candies, keys, containedBoxes, initialBoxes))
