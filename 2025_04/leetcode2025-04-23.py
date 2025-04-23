from functools import cache

class Solution:
    def countLargestGroup(self, n: int) -> int:
        # 定义dfs函数，dfs(s, pos, limited)用来计算以pos位为起点开始填写数字，并且数字各位的总和为s，同时数字不超过n的总填写方式，而limited表示前面是否有数字填到等于n的相应位置的数，因为如果前面有数字和原数相等，那么后面的数字最大只能填写到n对应位置的数字，而如果前面有一个数字小于n相应位置的数字，那么后面所有数字最大都可以填写到9
        # 因此对于dfs(s, pos, limited)，我们首先要确定pos位能够填写的最大值，如果前面有数字达到上限，那么当前就只能填到n中对应数字，否则可以填到9，所以mx=strN[pos] if limited else 9，之后遍历当前位置可以填写的值i，因为limited还需要往后传递，所以还要考虑当前是否填到了最大值，因此答案就要加上dfs(s-i, pos+1, limited and i==mx)，最后将所有情况遍历后加到一起就得到了答案
        # 因为题目要求的是并列数字最多的数组，所以我们要循环所有的可能数位和，一共有m位，数字从1开始，因此数位和的范围就是[1,m*9]，遍历所有的数位和，得到答案后求答案最大值的个数即可
        strN = list(map(int, str(n)))
        m = len(strN)
        @cache
        def dfs(s, pos, limited):
            # 数位和为s，从pos位开始填
            if pos == m:
                if s == 0:
                    return 1
                return 0
            mx = strN[pos] if limited else 9
            ans = 0
            for i in range(min(s, mx)+1):
                # 遍历当前位置可以填写的所有数字
                ans += dfs(s-i, pos+1, limited and i==mx)
            return ans

        mxCnt = 0
        res = 0
        for i in range(1, m*9+1):
            # 求最多数字的数位和个数
            tmpCnt = dfs(i, 0, True)
            if tmpCnt > mxCnt:
                res = 1
                mxCnt = tmpCnt
            elif tmpCnt == mxCnt:
                res += 1
        return res

        # cnt = defaultdict(int)
        # for i in range(1,n+1):
        #     cnt[sum(map(int, list(str(i))))] += 1
        # mx = max(cnt.values())
        # res = 0
        # for kv in cnt.items():
        #     if kv[1] == mx:
        #         res += 1
        # return res

if __name__ == "__main__":
    s = Solution()
    n = 13
    print(s.countLargestGroup(n))
