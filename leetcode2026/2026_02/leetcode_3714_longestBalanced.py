from collections import defaultdict

class Solution:
    def longestBalanced(self, s: str) -> int:
        # cnta[j]-cnta[i] = cntb[j]-cntb[i] ==> cnta[i]-cntb[i] = cnta[j]-cntb[j]
        # cntb[j]-cntb[i] = cntc[j]-cntc[i] ==> cntb[i]-cntc[i] = cntb[j]-cntc[j]
        # cnta[j]-cnta[i] = cntc[j]-cntc[i] ==> cnta[i]-cntc[i] = cnta[j]-cntc[j]
        # 分三种情况，分别是：1.只有一种字母，2.有两种不同的字母，3.有三种不同的字母
        # 第一种情况很简单，直接找到最长的连续重复子串的长度即可
        # 对于第二种情况，又可以分成三种子情况，即两个不同的字母分别是ab, bc或ac，因此，只要一个数组满足上面任意一个条件，并且第三个字符在其中没有出现，那么这就是一个平衡子串
        # 第三种情况则在其中任选两个条件，只要一个数组的左右端点满足任意两个条件，那么都是一个平衡子串
        n = len(s)

        res = 0
        i = 0
        while i<n:
            start = i
            i += 1
            while i<n and s[i]==s[i-1]:
                i += 1
            res = max(res, i-start)
        
        def calc(x, y):
            nonlocal res
            i = 0
            while i<n:
                pos = {0:i-1}
                d = 0
                while i<n and (s[i]==x or s[i]==y):
                    d += 1 if s[i]==x else -1
                    if d in pos:
                        res = max(res, i-pos[d])
                    else:
                        pos[d] = i
                    i += 1
                i += 1

        calc('a', 'b')
        calc('b', 'c')
        calc('a', 'c')

        pos = {(0,0):-1}
        cnt = defaultdict(int)
        for i in range(n):
            x = s[i]
            cnt[x] += 1
            key = (cnt['a']-cnt['b'], cnt['b']-cnt['c'])
            if key in pos:
                res = max(res, i-pos[key])
            else:
                pos[key] = i
        return res

        # cnta = [0]*(n+1)
        # cntb = [0]*(n+1)
        # cntc = [0]*(n+1)
        # for i in range(n):
        #     cnta[i+1] = cnta[i]+(s[i]=='a')
        #     cntb[i+1] = cntb[i]+(s[i]=='b')
        #     cntc[i+1] = cntc[i]+(s[i]=='c')

        # tot = defaultdict(int)
        # for i in range(n+1):
        #     diffAB = cnta[i]-cntb[i]
        #     diffBC = cntb[i]-cntc[i]
        #     if (diffAB, diffBC) in tot:
        #         res = max(res, i-tot[(diffAB, diffBC)])
        #     else:
        #         tot[(diffAB, diffBC)] = i

            
        # return res

if __name__ == "__main__":
    sl = Solution()
    s = "abbac"
    print(sl.longestBalanced(s))
