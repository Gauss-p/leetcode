from collections import defaultdict

class Solution:
    def sortVowels(self, s: str) -> str:
        # 暴力，直接取出所有元音字母所在位置，并将所有元音字母取出并排序，依次填充进去即可
        s = list(s)
        n = len(s)
        pos = []
        letters = []
        for i in range(n):
            if s[i] in "aeiouAEIOU":
                pos.append(i)
                letters.append(s[i])
        letters.sort()
        for i in range(len(pos)):
            indx = pos[i]
            s[indx] = letters[i]
        return ''.join(s)

        # n = len(s)
        # pos = defaultdict(int)
        # letters = []
        # for i in range(n):
        #     if s[i] in "aeiouAEIOU":
        #         pos[i] = 1
        #         letters.append(s[i])
        # letters.sort()
        # res = ""
        # j = 0
        # for i in range(n):
        #     if pos[i]:
        #         res += letters[j]
        #         j += 1
        #     else:
        #         res += s[i]
        # return res

if __name__ == "__main__":
    sl = Solution()
    s = "lEetcOde"
    print(sl.sortVowels(s))
