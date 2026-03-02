from typing import List

class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        # 注意观察，如果要让对角线右上角的所有元素都变成0，需要令每一行都满足：如果该行索引为i，那么它末尾连续0的个数至少为n-i-1，可以发现，限定的末尾连续0的个数是随i的增加而减小的，故可以将grid中的每一行按照其末尾连续0的个数从大到小进行冒泡排序，即可找到将它排序所需要的交换次数，之后，如果排序后的每一行的0的个数都满足限制，才能返回这个交换次数，只要有一行在排序后依然没法满足对0的个数的限制，就直接返回-1
        def calc(row):
            # 计算每一行末尾连续0的个数
            cnt = 0
            for i in row[::-1]:
                if i == 1:
                    break
                cnt += 1
            return cnt
        
        newGrid = [] # 将每一行都压缩成一个数字即可
        for row in grid:
            newGrid.append(calc(row))
        
        n = len(newGrid)
        res = 0
        for i in range(n):
            if newGrid[i] >= n-i-1:
                # 已经满足条件，不需要交换
                continue
            indx = i+1
            while indx<n and newGrid[indx] < n-i-1:
                # 在后面找能够满足该条件的行
                indx += 1
            if indx == n: # 没有任何行可以满足该行的条件
                return -1
            val = newGrid.pop(indx) # 交换
            newGrid.insert(i, val)
            res += indx-i
        return res

if __name__ == "__main__":
    s = Solution()
    grid = [[0,0,1],[1,1,0],[1,0,0]]
    print(s.minSwaps(grid))
