class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        # 根据定义，可以发现一个特殊的二进制字符串一定要满足以下条件：1.'0'和'1'的数量相同；2.第一个字符为'1'；3.最后一个字符为'0'。第一个条件即为题目要求，后两个条件则为题目第二个要求的变形，可以用反证法证明后面两个条件。
        # 首先，如果第一个字符为'0'，那么取长度为1的前缀，此时0的数量大于1的数量，不满足条件；其次，如果最后一个字符为1，那么取长度为n-1的前缀，根据第1个条件，在这个前缀中0的个数一定比1的个数多1，故不满足条件
        # 接下来，根据这个定义，我们可以这样计算：首先找到一个最短的1和0个数相同的子字符串，那么可以证明，“最短”保证了这个字符串的起始字符和结尾字符是不同的，之后，将其去掉首尾重新排列，得到一个最大的内部字符串，将这个重新排列得到得到的字符串的首位分别加上1和0，就形成了一个特殊的二进制字符串。按照这种方式找到字符串中所有的特殊的二进制子字符串，从大到小排列后首尾连接，即可得到原字符串重排后得到的最大字符串
        # 注意到上面计算过程中也用到了重排，故可以将这个计算方法设计为递归函数，在内部也调用即可
        start = 0
        i = 0
        specialStrings = []
        cnt = 0
        # 当s[i]='1'时，cnt+1，当s[i]='0'时，cnt-1，这样，当cnt=0时就说明这个字符串中0和1的数量相同
        while i<len(s):
            if s[i] == '1':
                cnt += 1
            else:
                cnt -= 1
            if cnt == 0:
                inner = s[start+1:i] # 去除首尾，对中间重排
                newStr = '1'+self.makeLargestSpecial(inner)+'0'
                specialStrings.append(newStr)
                start = i+1
            i += 1
        specialStrings.sort(reverse = True) # 从大到小排列，首尾相接即可
        return ''.join(specialStrings)

if __name__ == "__main__":
    sl = Solution()
    s = "11011000"
    print(sl.makeLargestSpecial(s))
