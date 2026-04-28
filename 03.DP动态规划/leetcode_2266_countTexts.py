modNum = 100_000_000_7
# 定义动态规划列表f和g，f[i]表示在"234568"中的某个数字连续出现i次以后的文字信息数量，g[i]表示在"79"中的某个数字连续出现i次以后的文字信息数量
# 那么f[i]可以看成由f[i-1],f[i-2],f[i-3]转移过来的，因为对于数字"234568"，每个字母最多连按3次，所以这长度为i的重复数字的结尾就有可能是连按1，2或3下。举个例子，如果有连续4个2，那么它所对应的信息结尾就有可能是'a'或'b'或'c'，如果是'a'，那么就是从连续3个2那里转移过来的，如果是'b'，那么就是从连续2个2那里转移过来的，否则就是从连续1个2那里转移过来的。所以f[i] = f[i-1]+f[i-2]+f[i-3]
# 同理，g[i] = g[i-1]+g[i-2]+g[i-3]+g[i-4]
# 所以我们可以首先计算所有长度对应的可能的情况总数
f = [1,1,2,4]
g = [1,1,2,4]
for i in range(10**5-3):
    f.append((f[-1]+f[-2]+f[-3])%modNum)
    g.append((g[-1]+g[-2]+g[-3]+g[-4])%modNum)

class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        pressedKeys += "%"
        res = 1
        length = 1
        n = len(pressedKeys)
        for i in range(1, n):
            if pressedKeys[i] == pressedKeys[i-1]:
                length += 1
                continue
            if pressedKeys[i-1] in "79":
                res = (res*g[length])%modNum
            else:
                res = (res*f[length])%modNum
            length = 1
        return res

if __name__ == "__main__":
    s = Solution()
    pressedKeys = "22233"
    print(s.countTexts(pressedKeys))
