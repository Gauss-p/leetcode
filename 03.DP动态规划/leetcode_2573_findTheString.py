from typing import List

class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        # 分析lcp数组的性质：
        # 1.lcp[i][i+1]>0，令length = lcp[i][i+1]，那么就有s[i:i+length] = s[i+1:i+1+length]，由这个式子即可得到：s[i]=s[i+1], s[i+1]=s[i+2], ..., s[i+length-1]=s[i+length]，因此说明，此时一定满足位置i之后的连续length个字符都和s[i]相同，也就意味着在模拟构造的时候可以直接将length*s[i]加在s[i]之后即可
        # 2.如果lcp[i][i+1]=0，就说明在构造出的字符串s中一定满足s[i] != s[i+1]，但为了判断s[i+1]究竟能填哪个数字，不能单纯保证它不等于s[i]就行，而需要用索引i0循环在i之前的所有位置，判断lcp[i0][i+1]是否为0，如果是，就说明s[i+1]不能和s[i0]相同，而如果不是，即lcp[i0][i+1]>0，那么就说明s[i+1]必须得和s[i0]相同，于是直接将是s[i+1]置为s[i0]即可；而如果所有的i0都无法满足lcp[i0][i+1]>0，那么就说明s[i+1]不能与前面出现过的任何一个字符相同，又因为要保证字典序最小，故需要选取没有在前面出现过的最小的那个字符，放在s[i+1]的位置，而这时如果26个字符在前面全部出现过，就说明不可能构造出一个符合lcp的字符串，直接返回""即可
        # 由于lcp矩阵可能出现自相矛盾的情况，导致其无法构成一个长度为n的字符串，因此在构造出字符串s之后，需要先判断s的长度是否为n，如果是n才能继续下去，否则需返回""
        # 而后，就算s的长度恰好为n，依然不能保证它一定能满足lcp的所有要求，因此需要用动态规划计算出当前s对应的新lcp矩阵，判断两个矩阵是否相同，只有完全相同，才表明这个字符串是符合要求的

        n = len(lcp)
        s = "a"
        indx = 0
        while indx < n-1:
            if lcp[indx][indx+1] == 0:
                flag = False
                canWrite = [True]*26
                for i in range(indx+1):
                    if lcp[i][indx+1] > 0:
                        # 有需要令indx+1位置和前面相同的
                        s += s[i]
                        flag = True
                        break
                    else:
                        # 
                        canWrite[ord(s[i])-ord('a')] = False
                
                if flag:
                    # 如果已经确定indx+1位置的字符，就不需要对当前位置再操作
                    indx += 1
                else:
                    # 未确定indx+1位置字符，需要找到前面没出现过的最小字符
                    for i in range(26):
                        if canWrite[i]:
                            s += chr(ord('a')+i)
                            flag = True
                            break
                    if flag:
                        # 还有字符没出现过
                        indx += 1
                    else:
                        # 所有字符都出现过
                        return ""
                
            else:
                # lcp[indx][indx+1] > 0
                # 根据情况1的分析，直接处理
                length = lcp[indx][indx+1]
                s += s[indx]*length
                indx += length
        
        if len(s) != n:
            return ""

        # 根据s计算新的lcp数组
        newLcp = [[0]*(n+1) for _ in range(n+1)] # 计算新lcp矩阵
        for i in range(n-1, -1, -1):
            for j in range(n-1, -1, -1):
                if s[i] == s[j]:
                    newLcp[i][j] = max(newLcp[i][j], newLcp[i+1][j+1]+1)
        
        for i in range(n):
            for j in range(n):
                if newLcp[i][j] != lcp[i][j]:
                    return ""
        return s

if __name__ == "__main__":
    s = Solution()
    lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
    print(s.findTheString(lcp))
