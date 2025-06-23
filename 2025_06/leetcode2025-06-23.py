from typing import List

# 我们可以考虑先构造十进制下的回文数，然后用一个check函数判断该数字在给定的进制下是否为回文数，这样就可以获取到对于每一个进制k的所有k镜像数字
# 我们先实现check函数，传入一个十进制数字x和一个进制k，需要判断x在k进制下是否为回文数，那么我们可以取出x在k进制下的后半段，将其翻转，然后和前半段进行比较。类比十进制下取一个数字最后一位的方法，我们可以发现x在k进制下的最后一位就是x%k，同时因为要实现翻转，我们需要将已经计算出来的已翻转后半段half的最后加上当前数字，所以同样类比10进制下的添加最后一位数字的方法，half就变成half*k+(x%k)，之后，我们就需要将x在k进制下的最后一位去掉，也就是需要将x//k。为了保证求出的half是后半段，我们就需要在循环中始终保持half<x，一旦退出，要么half=x，要么half>x，如果half=x，那么x在k进制下一定是回文数，而如果half>x，可能是x在k进制下的总位数为奇数，我们需要将half在k进制下的最后一位去掉，再与x进行比较，即，如果half//k==x，那么就说明x在k进制下的总位数为奇数，且是回文数，否则就不是回文数
def check(x, k):
    if x%k == 0:
        return False
    half = 0
    while half < x:
        half = half*k+(x%k)
        x //= k
    return half==x or half//k==x

# 最后我们需要将每一个生成出来的十进制回文数对于所有进制进行判断，看是否在该进制下也是回文数，如果是，就在预处理的列表中加入该数字(注意，为了计算方便，我们存储所有k镜像数字的方式是用前缀和来存储的)，否则不加。
# 我们可以用一个函数来循环判断所有的进制k是否满足x在k进制下也是回文数的条件，如果满足，并且已经找到的k镜像数字的总个数还没有达到总个数，就将x和k镜像数字中最后一个数字相加，并存入其中，这是直接计算前缀和的方式
# 而我们期望的是，在主要的生成十进制回文数的函数中，一直生成到将所有进制下的30个k镜像数字都找到后才停止，因此，只要发现还有一个进制中的30个数字没有找到，就将返回值设定为False，标记当前还未完成

def pre_finished(x):
    done = True
    for k in range(2, 10):
        if len(ans[k])<MAX_NUM+1 and check(x, k):
            ans[k].append(ans[k][-1]+x)
        
        if len(ans[k])<MAX_NUM+1:
            done = False
    return done

# 然后我们需要实现在十进制中直接生成回文数，那么因为题目要求的是最小n个数字的和，因此我们可以考虑用十进制数字位数从小到大生成，具体思路如下：我们用一个base表示当前一轮生成数字的起始位置，最开始base为1，那么我们从base到base*10循环，就可以得到一些位数相同的数字，然后对于每一个数字x，我们利用它构建一个回文数字。我们先用x的字符串newX来构建回文数字，newX+newX[::-1][1:]就可以得到以x的最后一个数字为中间位置的，总位数为奇数的一个回文数字。为了保证生成的数字遵循从小到大的顺序，我们需要在该循环结束后再次启动一个循环用来生成总位数为偶数的回文数字，即直接用newX+newX[::-1]即可生成
# 在生成以后需要调用上面的函数进行对每一个进制的判断和添加，只要还未填完，就要继续循环

MAX_NUM = 30
ans = [[0] for _ in range(10)] # 这里初始化一个0是为了在计算前缀和时取[-1]时列表中有一个值，并且该值不会对前缀和产生影响。同时这个0还可以占位，使得在返回答案时直接返回ans[k][n]即可，不需要对n进行加减1的操作
def init():
    base = 1
    while True:
        for cur in range(base, base*10):
            newN = str(cur)
            newN += newN[::-1][1:]
            if pre_finished(int(newN)):
                return

        for cur in range(base, base*10):
            newN = str(cur)
            newN += newN[::-1]
            if pre_finished(int(newN)):
                return
        
        base *= 10

init()

class Solution:
    def kMirror(self, k: int, n: int) -> int:
        return ans[k][n]

if __name__ == "__main__":
    s = Solution()
    k, n = 2, 5
    print(s.kMirror(k, n))
