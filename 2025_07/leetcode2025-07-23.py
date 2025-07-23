class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        # 贪心地想，假如我们遇到了一连串全是a和b构成的子字符串，那么肯定是先删除得分最高的组合最好，也就是假如x>y，那么我们先删除'ab'就是最佳选择，如果y>x，那么我们先删除'ba'就是最佳选择，因此为了将这两种情况共用一个代码，我们可以将两个字符分别用a和b两个变量表示，它们的初始值分别为'a'和'b'，我们假设当前先删除a+b是最佳选择，那么就可以适应x>y的情况，而如果y>x，我们只需将a和b交换，并将x和y交换即可得到和第一种情况类似的情况
        # 接下来我们考虑如何计算，假如我们遇到了全部都由'a'和'b'构成的一个字符串，那么我们从头开始遍历，先找出所有可能的a+b的组合，这可以利用栈的思路来解决，我们只要遇到一个等于a的字符就将其统计一次，即将cntA加1，而在我们遇到一个等于b的字符时，我们需要判断之前是否有等于a的字符，也就是cntA是否大于0，如果大于0，就说明现在找到了一个a+b的组合，我们就可以将该组合计入答案，并消耗一个a，即将cntA减1.在将整个字符串循环完后，可以保证将所有的a+b组合都统计了一遍，那么如果a和b字符还有剩余，只有可能组成的是b+a的字符串，因此在最后我们还需统计剩下的b+a字符串，因为如果要组成这个字符串就需要一个b和一个a，因此我们最多只能够组成min(cntA, cntB)个字符串
        # 但是s不一定全部都是'a'和'b'，因此我们还需要在遍历时考虑当一个连续'a'和'b'字符串结束时，cntA和cntB应当如何处理。套用上面的方法，可以发现，当我们遇到一个非'a'非'b'的字符时，就说明一个连续'a'和'b'字符串结束了，也就需要我们统计当前剩余的b+a字符串的数量，在计入答案后，我们就相当于重开一个全部由'a'和'b'构成的字符串，也就需要将cntA和cntB全部置为0，相当于重置
        a, b = 'a', 'b'
        if y>x:
            # 先删除得分多的组合
            a, b = b, a
            x, y = y, x
        s += '.' # 加一个哨兵，用来在同一个循环中计算最后一段连续'a'和'b'的字符串中剩余b+a字符串的数量
        cntA, cntB = 0, 0
        res = 0
        for c in s:
            if c == a:
                # 一个a字符入栈
                cntA += 1
            elif c == b:
                if cntA > 0:
                    # 可以匹配一个a+b字符串，消耗一个a字符
                    cntA -= 1
                    res += x
                else:
                    # 如果无法匹配就将一个字符b入栈
                    cntB += 1
            else:
                res += min(cntA, cntB)*y # 最后统计剩余的b+a字符串数量
                cntA = 0
                cntB = 0
        return res

        # @cache
        # def dfs(curS, score):
        #     if 'ab' not in curS and 'ba' not in curS:
        #         return score
        #     ans = 0
        #     for i in range(len(curS)-1):
        #         if curS[i:i+2] == 'ab':
        #             ans = max(ans, dfs(curS[:i]+curS[i+2:], score+x))
        #         elif curS[i:i+2] == 'ba':
        #             ans = max(ans, dfs(curS[:i]+curS[i+2:], score+y))
        #     return ans
        # return dfs(s, 0)

if __name__ == "__main__":
    sl = Solution()
    s = "cdbcbbaaabab"
    x, y = 4, 5
    print(sl.maximumGain(s, x, y))
