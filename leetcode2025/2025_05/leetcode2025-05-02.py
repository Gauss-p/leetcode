class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        # 我们可以将字符串dominoes分段，我们分段的方式如下：如果一个子字符串的左右端点都不是'.'，并且中间所有的字符都不是'.'，那么这就是一段
        # 根据我们对段的定义，可以将其分为如下几种情况：1.左右端点字符相同;2.左端点是R右端点是L;3.左端点是L右端点是R
        # 根据题目，可以知道三种情况的答案：情况1的答案就是全部字符都变成和左右端点相同;情况2的答案就是左边一半变成R，右边一半变成L，中间如果有剩余就保持'.'不变;情况3的答案就是除左右端点外中间所有值都保持'.'不变
        # 归纳一下，如果原来是L...L那么之后就是LLLLL，如果原来是R...R，那么之后就是RRRRR，如果原来是R...L那么之后就是RR.LL，如果原来是L...R，那么之后还是L...R
        # 如果单纯这样累加答案，我们发现处于两段交接的端点会被重复计算，所以我们对于每一段的答案都不累加最后一个值即可
        # 但是我们发现左右两边有可能计算不到，所以我们可以在原字符串的左右两边增加两个哨兵L和R，再根据上一段的答案累计方法，因为我们没有加最后一个字符，所以最终的答案只会多出左边的哨兵，而不会有右边的那个哨兵，因此在返回答案的时候去掉第一个字符即可
        dominoes = 'L'+dominoes+'R' # 增加哨兵
        n = len(dominoes)
        pre = 0
        res = ""
        for i in range(1,n):
            if dominoes[i] == '.':
                # 只计算最开始被推的牌
                continue
            tmp = ""
            if dominoes[i] == dominoes[pre]:
                tmp = (i-pre+1)*dominoes[i]
            elif dominoes[i] == 'L':
                tmp = ((i-pre+1)//2)*'R'+((i-pre+1)%2)*'.'+((i-pre+1)//2)*'L'
            else:
                tmp = 'L'+(i-pre-1)*'.'+'R'
            res += tmp[:-1] # 不加最后一个字符
            pre = i
        return res[1:]
        # ------------------------------------------
        # n = len(dominoes)
        # left = []
        # last = (-1, "NO")
        # for i in range(n):
        #     left.append(last)
        #     if dominoes[i] != '.':
        #         last = (i, dominoes[i])
        # right = []
        # last = (-1, "NO")
        # for i in range(n-1, -1, -1):
        #     right.insert(0, last)
        #     if dominoes[i] != '.':
        #         last = (i, dominoes[i])

        # res = ""
        # for i in range(n):
        #     if dominoes[i] != '.':
        #         res += dominoes[i]
        #         continue
        #     l, r = left[i], right[i]
        #     if "NO" in [l[1], r[1]]:
        #         if l[1]=="NO" and r[1]=="L":
        #             res += r[1]
        #         elif l[1]=="R" and r[1]=="NO":
        #             res += l[1]
        #         else:
        #             res += '.'
        #         continue
        #     if l[1] == r[1]:
        #         res += l[1]
        #     elif l[1]=='L' and r[1]=='R':
        #         res += '.'
        #     else:
        #         mid = (l[0]+r[0])/2
        #         if i < mid:
        #             res += 'R'
        #         elif i > mid:
        #             res += 'L'
        #         else:
        #             res += '.'
        # return res

if __name__ == "__main__":
    s = Solution()
    dominoes = ".L.R...LR..L.."
    print(s.pushDominoes(dominoes))
