from collections import defaultdict

class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        res = 0
        n = len(word)
        # 暴力遍历所有情况，以i为开头，j为结尾的子字符串如果五个元音字母都有，并且辅音字母个数正好为k，答案加1
        for i in range(n):
            vowel = defaultdict(int)
            cnt = 0
            for j in range(i,n):
                if word[j] in "aeiou":
                    vowel[word[j]] += 1
                else:
                    cnt += 1
                if len(vowel)==5 and cnt==k:
                    res += 1
                if cnt > k:
                    # 如果辅音字母的个数大于k，那么再往后辅音字母的个数一定大于k，再循环就没有意义了
                    break
        return res

if __name__ == "__main__":
    s = Solution()
    word = "ieaouqqieaouqq"
    k = 1
    print(s.countOfSubstrings(word, k))
