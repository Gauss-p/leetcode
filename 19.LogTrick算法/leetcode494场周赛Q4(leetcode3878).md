### 题目分析
题目要寻找的子数组只需满足：整个子数组的或值在这个子数组中出现过。

### 基本思路
最简单的想法是直接遍历所有的子数组，依次判断每个子数组是否满足要求，如果满足，直接用`res`统计1即可，最后就可以得到答案。

但是对于$10^5$这样的数据规模，上述算法的$O(n^2)$时间复杂度肯定会超时，因此可以尝试优化。

在暴力算法中，可以选择用外层循环的`i`遍历右端点，而后在内层循环的`j`中从`i`开始向左遍历，一边用字典统计数字是否出现过，一边用一个值维护整个子数组的或值，即可实时判断该子数组是否符合要求。注意到在这个运算过程中，`0~j`的部分总是会被重复计算，因此可以考虑将每个子数组按照`[或值orVal, 左端点left]`的形式存储在一个列表`or_left`中，这样，每次只需遍历`or_left`的所有元素，将每一个二元组的首个值均与当前位置的值进行异或即可

不过这样一来尽管不需要对每个`0~j`的部分进行重复计算了，但复杂度依然不会降低。观察到如果对于同一个右端点，有许多左端点和它所夹的子数组的或值都相同，那么这些左端点就可以批量进行处理，因此，每次在更新完所有的二元组后，可以将首个元素`orVal`相同且相邻的所有二元组合并，只保留最小的那个左端点，这样，在合并之后，整个`or_left`列表中保存的所有左端点的值就可以很自然地将前面所有索引划分成许多小段，同时保证相邻两个二元组`[orVal1, left1]`和`[orVal2, left2]`一定满足：

 > 		以处在$[left1, left2)$中的任意一个索引为左端点，当前位置为右端点，中间所夹的子数组的或值均为`orVal1`
 
 如果能够将所有数字的最近出现位置用一个字典`last`保存下来，那么这时候`以orVal1为或值，以当前位置i为右端点`的好子数组的左端点取值范围就是：$$leftSide \in [left1, min(last[orVal1], left2-1)]\iff last[orVal1]\geq left1$$
因此，这时候只需要遍历`or_left`中的所有二元组，分别计算上述的左端点取值情况数，累加即可得到以当前位置`i`为右端点的所有好子数组的数量

### 实现细节
在合并`or_left`中`orVal`相同的二元组时，可以采用原地修改+删除后缀的方式

在计算以`i`为右端点的好子数组数量时，当循环到`or_left`的最后一个二元组时已经不存在所谓的`left2`了，因此需要用`i`来代替`left2-1`这个值进行运算

### 复杂度
时间复杂度：$O(nlogU),\ 其中n=len(nums), U=max(nums)$
空间复杂度：$O(n+logU),\ n是last所占的,\ logU是or\_left所占的$

### 代码

```python
class Solution:
    def countGoodSubarrays(self, nums: list[int]) -> int:
        n = len(nums)
        or_left = []
        def init():
            return -1
        last = defaultdict(init)
        res = 0
        for i in range(n):
            x = nums[i]
            last[x] = i
            for j in range(len(or_left)):
                or_left[j][0] |= x
            or_left.append([x, i])

            indx = 1
            for j in range(1, len(or_left)):
                if or_left[j][0] != or_left[j-1][0]:
                    or_left[indx] = or_left[j]
                    indx += 1
            del or_left[indx:]

            for k in range(len(or_left)):
                orVal, low = or_left[k]
                high = or_left[k+1][1]-1 if k+1<len(or_left) else i
                lastOr = last[orVal]
                if lastOr >= low:
                    res += (min(high, lastOr)-low+1)
        return res
```