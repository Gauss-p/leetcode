from collections import defaultdict

class Solution:
    def clearStars(self, s: str) -> str:
        # 贪心地想，对于每一个星号，如果都需要删除左边的一个最小元素，那肯定是删除最靠近星号的最小元素最好，只有这样才能保证删除后的字典序最小
        # 我们用一个字母栈，由26个栈组成，第i个栈中存储的就是第i个字母出现过的位置，那么从0开始循环，只要发现当前位置的栈非空，就将该栈的最后一个元素弹出并标记它已被删除，这样既可以保证删除的是最小元素，又可以保证是和当前位置最近的一个
        pos = [[] for _ in range(26)]
        n = len(s)
        s = list(s)
        # removed = defaultdict(int)
        for i in range(n):
            if s[i] != '*':
                pos[ord(s[i])-ord('a')].append(i)
            else:
                for p in pos:
                    if len(p) > 0:
                        # removed[p.pop()] = 1
                        s[p.pop()] = '*'
                        break
        
        res = ""
        for i in range(n):
            # if s[i] == '*' or removed[i]:
            if s[i] == '*':
                continue
            res += s[i]
        return res

if __name__ == "__main__":
    sl = Solution()
    s = "aaba*"
    print(sl.clearStars(s))
