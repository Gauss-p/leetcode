from typing import List

class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        # 预处理后缀数组suf，其中suf[i]=j表示：word2[j:]是word1[i:]的一个子序列，即不用任何修改，在word1[i:]中就可以按顺序找到word2[j:]中的所有字符
        # 之后用下标i从左往右遍历word1，同时维护一个word2中已经匹配到的位置j，贪心的想，为了让得到的下标数组字典序最小，总共可分以下两种情况讨论：
        #   1.word1[i]=word2[j]，为了最小化下标数组的字典序，这里既然已经匹配成功，就直接计入答案；
        #   2.word1[i]!=word2[j]，那么假如现在能使用修改机会并且保证可以将word2中后续所有字符都匹配完成，那么就直接用掉修改机会，直接将i计入答案中。如何判断这两个条件？对于修改机会的判断，可以用一个changed变量进行标识，而如果要保证可以将word2后续所有字符匹配完成，即要保证word1[i+1:]中能够匹配word2[j+1:]，那么直接判断suf[i+1]是否小于等于j+1即可，如果是，就说明word1[i+1:]至少可以匹配word2[j+1:]中所有字符，可以放心大胆进行修改。
        n, m = len(word1), len(word2)
        suf = [0]*(n+1)
        suf[n] = m
        j = m-1
        for i in range(n-1, -1, -1):
            if j >= 0 and word1[i] == word2[j]:
                j -= 1
            suf[i] = j+1
        
        res = []
        j = 0 
        changed = False
        for i in range(n):
            if word1[i] == word2[j]:
                res.append(i)
                j += 1
            else:
                if not changed and suf[i+1] <= j+1:
                    changed = True
                    res.append(i)
                    j += 1
            if j == m:
                return res
        return []

if __name__ == "__main__":
    s = Solution()
    word1 = "abc"
    word2 = "ab"
    print(s.validSequence(word1, word2))
