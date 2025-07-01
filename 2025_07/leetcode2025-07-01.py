class Solution:
    def possibleStringCount(self, word: str) -> int:
        # Alice出错只有可能在一个字符重复段中，所以我们找出所有的字符重复段，求出每一个的长度curLength，然后又因为Alice至多犯错一次，所以我们先假定她犯错一次，每一次就仅将答案加上curLength，在最后加上她不犯错的1即可
        n = len(word)
        res = 1
        for i in range(1, n):
            if word[i] == word[i-1]:
                res += 1
        return res

if __name__ == "__main__":
    s = Solution()
    word = "abbcccc"
    print(s.possibleStringCount(word))
