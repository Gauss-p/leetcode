from itertools import permutations
from collections import Counter

class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        # 这个题目要求的是符合条件的子序列，那么我们可以考虑暴力的算法
        # 注意到，对于每一个字符c，如果在s中出现次数为cnt[c]，假设我们想将它放在答案子序列中，那么因为答案子序列在s中需要出现k次，因此c在答案子序列中的出现次数就必须是cnt[c]//k，那么我们就将s中所有的字符按照它在答案子序列中应当出现的次数合成一个基字符串，但是注意到题目中要求我们字典序要最大，因此我们直接将基字符串从大到小排列即可
        # 在排列之后，我们就需要对每一个可能的长度进行判断，即，如果当前我们需要选取长度为length的答案子序列，那么就需要在基字符串base中寻找所有的长度为length的排列方式，之后对每一个排列方式进行判断，判断k个它是否能够按顺序出现在原字符串s中，如果能，它就是一个备选答案了
        # 但是为了方便，我们可以在循环中将length从大到小循环，这样找出的所有答案子序列就是按照长度从大到小排列了，又因为前面的从大到小排序已经保证了字典序从大到小排列，因此在循环中只要找到一个合法的答案子序列，我们就直接将它返回即可
        # 注意，在python3中，我们可以利用iter函数的遍历，直接将s字符串转换成一个迭代器ss，这样，每对ss操作一次，ss就会自动往后移动，这样，我们就可以利用它进行判断n个连续的答案子序列是否为s的一个子序列了
        # 同时，我们可以直接利用python3中maths库里面的permutations函数来生成：在base中寻找所有长度为length的排列方式，这样，在循环中直接用它生成，并在其中循环计算即可
        cnt = Counter(s)
        base = ""
        for key in sorted(cnt.keys(), reverse = True):
            base += key*(cnt[key]//k)
        for length in range(len(base), 0, -1):
            for newS in permutations(base, length): # 生成所有长度为length的排列
                tmp = "".join(newS)
                ss = iter(s) # 利用迭代器判断子序列
                if all(c in ss for c in tmp*k):
                    return tmp
        return ""

if __name__ == "__main__":
    sl = Solution()
    s = "letsleetcode"
    k = 2
    print(sl.longestSubsequenceRepeatedK(s, k))
