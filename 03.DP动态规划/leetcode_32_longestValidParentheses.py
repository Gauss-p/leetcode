class Solution:
    def longestValidParentheses(self, s: str) -> int:
        # 定义动态规划数组dp，其中dp[i]表示以s中第i个字符为结尾能够得到的最长有效括号子序列，那么在计算的时候，如果当前字符是(，即不可能有以它结尾的合法括号序列，对应的dp值就应该是0，否则，找左边一个字符，如果左边字符对应的子序列左侧一个位置恰好是(，可以与当前位置的)进行配对，包裹以左侧字符为结尾的最长括号序列，同时长度增加2，即：dp[i]=dp[i-1]+2
        # 需要注意的是，括号关系不仅仅有嵌套，还有并列，因此在计算出当前最长字串对应的左端点后，需要加上该左端点左侧位置对应的最长字串的长度
        n = len(s)
        dp = [0]*(n+1)
        for i in range(n):
            if s[i] == '(':
                continue
            else:
                if i > 0:
                    left = i-1-dp[i]
                    if left>=0 and s[left] == '(': # 嵌套情况
                        dp[i+1] = dp[i]+2
                        if left-1 >= 0 and dp[left]: # 并列情况
                            dp[i+1] += dp[left]
        return max(dp)

if __name__ == "__main__":
    sl = Solution()
    s = "(()"
    print(sl.longestValidParentheses(s))
