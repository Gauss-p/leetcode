class Solution:
    def distinctSubseqII(self, s: str) -> int:
        # 计算以各个字母为结尾的不同子序列总个数，最终进行求和即可
        # 需要注意的是对于每一个新出现的字母，都需要在统计数组中更新以它为结尾的子序列总个数，而新的总个数即为：当前以26个字母分别结尾的不同子序列个数总和再加1，其中前者表示将新字符增加在他们之后，后者表示当前单个字符也是一个子序列
        modNum = 1_000_000_007
        cnt = [0]*26
        for i,c in enumerate(s):
            cnt[ord(c)-ord('a')] = (sum(cnt)+1)%modNum
        return sum(cnt)%modNum

if __name__ == "__main__":
    sl = Solution()
    s = "aaa"
    print(sl.distinctSubseqII(s))
