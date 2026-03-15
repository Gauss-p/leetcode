### 题目分析

题目要求实现一个类，用来对一个列表实现：

1. 添加元素
2. 对所有元素加同一个值
3. 对所有元素乘同一个值
4. 查找某个位置的元素

### 基本思路

如果每次的对所有元素同加或同乘一个值都用循环来实现的话，时间复杂度太高，但就算将每次的操作保存下来，在每次查询元素的时候从最初的值开始进行模拟计算，同样会超时，因此需要采用其他方式进行优化。

最好的方式当然是看能否在最后查询的时候，直接将对应位置的值进行一次乘法和加法即可得到答案，因此可以按照这样的思路来寻找规律，即寻找是否能够将数字`v`进行多次操作后的值仅用这样一个式子表示：

$$v\times mulNum + addNum$$

根据定义，最开始的时候`mulNum`为1，`addNum`为0，分别考虑两种操作：
1. 如果要对`v`进行加一个数字`inc`的操作，那么式子会变成：$$v\times mulNum+(addNum+inc)$$也就是说只有`addNum`会加上`inc`。

2. 而如果要对`v`进行乘一个数字`m`的操作，那么式子会变成：$$v\times (mulNum\times m)+(addNum\times m)$$因此此时需要对`mulNum`和`addNum`都乘上`m`。

根据上面的两种情况，即可维护这两个值，使得最后只需要计算$v\times mulNum+addNum$即可得到v在进行所有变换后的值。

但由于中途加入的元素不能直接用所有操作去变换，又不能对每个元素单独保存一组`mulNum`和`addNum`，因此需要在加入列表的时候对这个元素进行变换，使其能够和其他元素统一适用一组值。

而如果要让加入列表的元素`x`满足$x\times mulNum+addNum=v$，实际上只需在列表中加入：
$$\frac{v-addNum}{mulNum}$$

注意在实现上面的除法时需要用到**逆元**。

### 复杂度
时间复杂度：$O(1)$
空间复杂度：$O(n)$

### 代码实现

```python
modNum = 1_000_000_007
class Fancy:

    def __init__(self):
        self.lst = []
        self.addNum = 0
        self.mulNum = 1

    def append(self, val: int) -> None:
        self.lst.append(((val-self.addNum)*pow(self.mulNum, -1, modNum))%modNum)

    def addAll(self, inc: int) -> None:
        self.addNum += inc

    def multAll(self, m: int) -> None:
        self.mulNum = (self.mulNum*m)%modNum
        self.addNum = (self.addNum*m)%modNum

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.lst):
            return -1
        return (self.lst[idx]*self.mulNum + self.addNum)%modNum
```
