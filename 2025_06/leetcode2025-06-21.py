from collections import Counter

class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        # 统计出每一个字符出现的次数，遍历这些次数，将当前遍历到的次数i置为最小值，根据题目给出的差值限定k可以确定出出现次数的最大值i+k，然后再次循环所有字符的出现次数j，如果j小于最小值，就要将所有的该字符删除，毕竟当前i已经是最小值了，而如果j大于最大值，就要将多出的部分删除
        # 即如果j<i，就要删除j，如果j>i+k，就要删除j-(i+k)
        # 最后对于每一个最小值都统计一次答案，取最小即可
        cnt = Counter(word)
        lst = list(cnt.values())
        res = float("inf")
        for i in lst:
            mn = i
            mx = i+k
            cur_res = 0
            for j in lst:
                if j>mx:
                    cur_res += j-mx
                elif j<mn:
                    cur_res += j
            res = min(res, cur_res)
        return res

if __name__ == "__main__":
    s = Solution()
    word = "aabcaba"
    k = 0
    print(s.minimumDeletions(word, k))
