from typing import List

class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        # 完全模拟即可，首先分析题意可以发现，每一次进行加a操作的时候需要对所有下标为奇数的数字进行操作，而位于偶数下标的位置的数字则可能通过轮转后b位来变成奇数位接受加a的操作，而偶数下标想要变成奇数下标，最主要的就是要满足b是奇数，如果b是偶数，那无论如何最初位于偶数位的数字都不可能轮转到奇数位上
        # 因此，对于原数我们就可以先将奇数位上的数字和偶数位上的数字分离，然后，对于奇数位上的数字，它们可以加上0a~9a的数字后对10取余，而对于偶数位上的数字，当且仅当b为奇数时它们可以加上0a~9a的数字后对10取余，否则它们不能变化
        # 接着，循环所有的累加情况，对奇数位累加的有10种情况，而对偶数位累加的有1或10种情况，因此两者嵌套循环，即可遍历到所有的累加情况。接着，对于累加后的每一种情况，我们都需要不断轮转后b位来求出所有可能的轮转情况，然后对于所有轮转情况求出一个最小的答案即可，需要注意的是，在轮转后b位的时候，只要出现当前轮转后的结果和总的情况相同，就需要退出循环
        # 最后，对于每一种累加情况的所有轮转情况，都求一个最小值即可得到答案
        n = len(s)
        odd = []
        even = []
        for i in range(n):
            # 分离奇数位和偶数位
            if i&1:
                odd.append(int(s[i]))
            else:
                even.append(int(s[i]))
        
        res = '9'*n
        for i in range(0, 9*a+1, a):
            curOdd = [] # 对奇数位进行累加操作
            for indx in range(len(odd)):
                curOdd.append(str((odd[indx]+i)%10))

            upper = 9*a+1 if b&1 else 1 # 当且仅当b为偶数的时候，偶数位才有可能轮转到奇数位上被累加
            for j in range(0, upper, a):
                curEven = [] # 对偶数位进行累加操作
                for indx in range(len(even)):
                    curEven.append(str((even[indx]+j)%10))

                tot = "" # 按照累加后的奇偶位求出对应字符串
                for indx in range(n):
                    if indx&1:
                        tot += curOdd[indx//2]
                    else:
                        tot += curEven[indx//2]
                
                mode = tot[-b:]+tot[:-b] # 轮转后b位
                curAns = tot
                while mode != tot: # 每次都进行轮转操作，一直到和原字符串再次重合为止
                    curAns = min(curAns, mode)
                    mode = mode[-b:]+mode[:-b]
                res = min(res, curAns) # 求最小值
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "5525"
    a = 9
    b = 2
    print(sl.findLexSmallestString(s, a, b))
