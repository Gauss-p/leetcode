class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        # 因为长度为3，又要求回文，因此第1和第3个字母必须相同，所以在寻找的时候，直接在s中找到一个字母出现的最左边位置和最右边位置，然后统计两个位置中间的不同字母总个数，累加入答案中即可
        n = len(s)
        l = [-1]*26 # 每一个字母的最左边出现位置
        r = [-1]*26 # 每一个字母的最右边出现位置
        for i in range(n):
            charIndx = ord(s[i])-ord('a')
            if l[charIndx] == -1:
                l[charIndx] = i
            r[charIndx] = i

        res = 0
        for c in range(26):
            curL, curR = l[c], r[c]
            if min(curL, curR) == -1 or curL+1 >= curR: # 确保当前字母有出现过且最左最右两个位置之间至少有一个字母
                continue
            st = set(list(s[curL+1:curR])) # 不同字母总个数
            res += len(st)
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "aabca"
    print(sl.countPalindromicSubsequence(s))
