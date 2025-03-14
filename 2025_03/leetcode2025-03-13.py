from collections import defaultdict

class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        n = len(word)
        # 定义myCount用来计算word中所有元音字母至少出现一次并且‘至少’包含m个辅音字母的子字符串总数
        def myCount(m):
            res = 0
            vowel = defaultdict(int)
            cnt = 0
            l = 0
            # 用滑动窗口的思路，自动遍历右端点，手动滑动左端点
            for i in range(n):
                c = word[i]
                if c in "aeiou":
                    vowel[c] += 1
                else:
                    cnt += 1
                # 如果当前存储的数据已经满足元音字母至少出现一次和辅音字母至少出现m次的要求，我们就将滑动窗口的左端点l右移，直到不满足以上要求。那么移动之后，我们可以知道只要是以[0,l)中的一个位置为开始，r为结尾的子字符串都可以满足以上要求。因为越往前字母的数量越多，不需要担心不满足以上情况
                # 所以在每一次滑动左端点之后，都新发现l个满足要求的子字符串，将l加入答案即可
                while len(vowel)==5 and cnt>=m:
                    if word[l] in "aeiou":
                        vowel[word[l]] -= 1
                        if vowel[word[l]]==0:
                            vowel.pop(word[l])
                    else:
                        cnt -= 1
                    l += 1
                res += l
            return res
        # 所以，最终的答案就是word中至少k个辅音字母的子字符串的数量减去至少k+1个辅音字母的子字符串的数量
        return myCount(k)-myCount(k+1)

if __name__ == "__main__":
    s = Solution()
    word = "aeiou"
    k = 0
    print(s.countOfSubstrings(word, k))
