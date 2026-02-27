class Solution:
    def almostPalindromic(self, s: str) -> int:
        # 如果要寻找一个回文串，可以从某一个位置x开始，用两个指针分别记录回文串当前的左右端点l和r，只要这两个位置对应的字符相同，就可以向两侧继续扩张，一直到无法满足「做右端点对应字符相同」的条件时，退出循环，则此时的左右端点就代表了以x为中心位置的最长回文子字符串的两端位置。不过用这个方法计算的时候有一点需要注意，即如果要最终的回文串长度为偶数，那么l和r就需要从x和x+1开始向左右扩展，但如果要最终的长度为奇数，那么l和r就可以简单地都从x开始向左右扩展
        # 但是题目并不是简单地求最长的回文字符串，而是要求“准”回文字符串，即“删除一个字符后可以变成回文字符串”的字符串，因此，对于一个回文串中心点，在单纯地向外扩展到极限后，仍然可以选择向左或向右跳过一个字符继续按照相同的方式扩展，即将l减掉1，或者将r加上1，之后再在s[l]==s[r]的情况下扩展，这样，最终找到的字符串一定满足“删除一个字符后可以变成回文字符串”
        # 在具体实现的时候，为了在一个循环内能够实现回文串长度分别为奇数和偶数的计算，可以用一个center变量在0~2*n-2中循环，这样，center//2对应的值就可以在0~n-1中循环，即可映射到每一个位置，不过同时，每一个映射对象都有两个初始center值，一奇一偶，因此可以用center的奇偶性决定当前寻找的回文字符串的长度是要奇数还是要偶数
        # 注意：无论何时，l和r都表示当前回文串的索引为(l,r)，即两边都不包含
        n = len(s)
        res = 0
        for center in range(n*2-1):
            left = center//2
            right = center//2+(center%2) # center是奇数，代表回文串长度是偶数，r需初始化为l+1，否则不需加1
            # 情况1：直接扩展，不跳过
            while left>=0 and right<n and s[left] == s[right]:
                left -= 1
                right += 1
            curLength = right-left-1
            res = max(res, curLength)

            # 情况2：向左跳过一个字符
            if left >= 0: # 左侧还有空间，向左跳过
                newLeft = left-1
                newRight = right
                while newLeft>=0 and newRight<n and s[newLeft] == s[newRight]:
                    newLeft -= 1
                    newRight += 1
                curLength = newRight-newLeft-1
                res = max(res, curLength)

            # 情况3：向右跳过一个字符
            if right <= n-1: # 右侧还有空间，向右跳过
                newLeft = left
                newRight = right+1
                while newLeft>=0 and newRight<n and s[newLeft] == s[newRight]:
                    newLeft -= 1
                    newRight += 1
                curLength = newRight-newLeft-1
                res = max(res, curLength)

        return res

if __name__ == "__main__":
    sl = Solution()
    s = "abca"
    print(sl.almostPalindromic(s))
