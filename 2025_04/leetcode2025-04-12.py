from collections import Counter
from math import factorial

class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        # 我们要求的是长度为n的好整数个数，可以看作先求出所有长度为n的k回文整数再将每个k回文整数的所有排列数量相加。为了构造回文整数，我们可以考虑这种方式：对于长度n，我们将它分成左右两半，如果知道了左边一半，那么另一半只需要将左边一半翻转后再拼接即可。
        # 我们称左边一半的长度为m，如果n为偶数，那么m只需要为n//2即可，但如果n为奇数，那么m需要为n//2+1，因为我们需要让左半边的数包括最中间的那个数。总结以上规律，可知m=(n-1)//2
        # 所以为了构造长度为n的回文整数，只需找到所有长度为m的整数翻转构造即可。现已知一个长度为m的整数i，那么分两种情况，如果n为偶数，那么回文整数就是str(i)+str(i)[::-1]，否则回文整数应是str(i)+str(i)[::-1][1:]，因为要避开中间一位。总结规律，可知回文整数就是str(i)+str(i)[::-1][n%2:]
        # 接下来我们需要将这些回文整数去重，去重的目的是为了避免重复计算回文数的其他排列。例如，如果有一个是1551，另一个是5115，它们的其他排列其实一样，所以将每个回文数排序后存入一个set中即可(排序指将1551变成1155)
        # 最后我们要计算每个回文数的其他排列的总数。对于每一个回文数字符串，我们首先统计其中每个字符出现的频数，接着，运用排列组合的知识，第一位因为不能填0，所以第一位的填法有n-cnt["0"]种，而之后没有限制，所以之后所有位的填法总共就有(n-1)!种，因此初步计算结果为(n-cnt['0'])*(n-1)!。接下来要去重，因为一个数字可能出现多次，因此将初步计算结果除以每个字符出现次数的阶乘即可得到答案，累加即可
        m = (n-1)//2
        st = set()
        for i in range(10**m, 10**(m+1)):
            # 生成回文数
            tmpStr = str(i)
            rev = tmpStr[::-1]
            newNum = tmpStr+rev[n%2:]
            if int(newNum)%k != 0:
                # 判断是否满足k回文的要求
                continue
            st.add("".join(sorted(newNum)))
        
        res = 0
        for i in st:
            # 总排列数之和
            cnt = Counter(i)
            sum1 = (n-cnt["0"])*factorial(n-1)
            for v in cnt.values():
                sum1 = sum1//factorial(v)
            res += sum1
        return res

if __name__ == "__main__":
    s = Solution()
    n = 3
    k = 5
    print(s.countGoodIntegers(n, k))
