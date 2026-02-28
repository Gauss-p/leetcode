class Solution:
    def answerString(self, word: str, nF: int) -> str:
        # 我们可以先不考虑朋友数量的限制，只求出word中字典序最大子字符串，那么如果我们从一个位置开始计算字典序最大的子字符串，这个子字符串肯定越长越好，所以问题也就转换成了求word中字典序最大的后缀。在找到这个后缀之后从它的起点开始往后截取我们需要的字符串长度即可。
        # 从最简单的问题开始考虑，如果word中字典序最大的字符只出现了一次，那么最大后缀一定是以它为起始的后缀；接下来，如果word中字典序最大的字符出现了多次，我们就需要考虑每一个最大字符之后的元素是否相同，如果相同，就继续往后推移比较，以此类推，在最大字符中两两比较，找出后缀字典序最大的那个即可
        # 但这样太慢了，我们可以这样考虑，如果定义三个数字i,j,k，其中i指向的是当前找到字典序最大的字符，j指向的是当前要进行比较的字符，而k表示当前从i开始和从j开始已经有多少个字符相同，那么我们主要移动的是索引j和已比较长度k。
        # 接下来有三种情况：1.word[i+k]=word[j+k]，此时无法判断以i开始的后缀和以j开始的后缀哪个更大，所以只能继续往后比较，即将k加1；2.word[i+k]<word[j+k]，此时说明无论再往后计算多少位都无法改变以i开始的后缀小于以j开始的后缀的现状了，只能将[i,i+k]这个区间放弃考虑，才需要改变索引i，因为放弃考虑[i,i+k]这个区间，所以需要将i转移到i+k+1的位置，但是需要注意的是，这里有可能将i转移到j之后，这样会重复计算，所以当出现这种情况的时候，我们还需要将j移动至i+1处再次开始判断；3.word[i+k]>word[j+k]，此时说明无论再往后计算多少位都无法改变以j开始的后缀小于以i开始的后缀的现状，所以我们直接放弃考虑区间[j,j+k]，直接将j移动到j+k+1的位置，继续和i开始的后缀进行比较
        # 注意，上面的第2,3种情况都需要将k置为0，因为这两种情况我们都需要重新开始判断，同时在循环的时候始终要保证j+k小于word长度，否则会超出索引限制
        # i,j,k的初始值就是0,1,0，因为最开始不能让j=i，否则会出现无意义的重复计算
        # 那么在进行完上述计算后，i指向的位置就是最大后缀的起始位置，答案就直接从它开始往后数len(word)-(nF-1)个字符即可
        if nF == 1:
            return word
        n = len(word)
        i, j, k = 0, 1, 0 # 初始值
        while j+k<n:
            if word[i+k] == word[j+k]:
                # 无法判断以i开始和以j开始的后缀哪个大
                k += 1
            elif word[i+k] < word[j+k]:
                # 以i开始的后缀更小，就将i向后移动
                i = i+k+1
                k = 0
                if i >= j:
                    # 防止重复计算
                    j = i+1
            else:
                # 以j开始的后缀更小，将j向后移动
                j = j+k+1
                k = 0
        return word[i:i+(n-(nF-1))]

        # ===================================================================
        # 下面是滑动窗口的方法
        # ===================================================================

        # if nF == 1:
        #     return word
        # n = len(word)
        # subLength = n-(nF-1)
        # res = ""
        # cur = ""
        # for i in range(n):
        #     res = max(res, word[i:i+subLength])
        # # for i in range(n+subLength):
        # #     if i<n:
        # #         cur += word[i]
        # #     if i<subLength-1:
        # #         continue
        # #     res = max(res, cur)
        # #     cur = cur[1:]
        # return res

        # if nF == 1:
        #     return word
        # n = len(word)
        # l = n-nF+1
        # res = ""
        # cur = ""
        # for i in range(n):
        #     cur += word[i]
        #     if i<l-1:
        #         continue
        #     if res < cur:
        #         res = cur
        #     cur = cur[1:]
        # for i in range(len(cur)):
        #     if res < cur[i:]:
        #         res = cur[i:]
        # return res

if __name__ == "__main__":
    s = Solution()
    word = "dbca"
    nF = 2
    print(s.answerString(word, nF))
