from collections import Counter

class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        # 为了构建回文排列，我们可以采用构建一半字符串，然后反转拼接的方式。
        # 那么这就导致一个问题，如果在给出的字符串s中，有两个不同的字符都出现了奇数次，那么我们就不可能用所有的字符构建出一个回文串，因为如果一个字符出现奇数次，就需要将它放在回文串的最中间，但两个字符都出现奇数次时，就不可能都放中间了
        # 因此，在最开始的时候，我们就可以对字符串s进行预处理，即将s中所有字符的出现次数统计出来。然后看所有字符中出现奇数次的字符数量是多少，如果是0，那么就意味着最后生成回文串时中间不需要加任何东西；如果是1，那么我们就保存下那个出现奇数次的字符，将它作为最后的中间字符；如果大于1，就直接返回空字符串，表示无法构成回文串，即可
        # 记回文串中间字符为middle，则当出现奇数次的字符数量为0时，middle=""，当它为1时，middle即为出现奇数次的字符
        
        # 根据我们最初的思路，我们需要构建回文字符串的一半，也就意味着我们使用的每一种字母的个数都是这种字母在s中出现总次数的一半，因此可以用一个列表统计出s中所有字符出现次数的一半，这样在这个列表对字符个数的限制下选择字符即可
        # 接下来我们就可以开始构建回文串的左边一半了。在构建回文串的过程中，对当前位置字符的选择需要依赖于前面所有已选字符是否有大于target。如果前面选择的字符已经大于target对应的字符了，那么就意味着在当前位置我们无论放任何字符都不会改变最终创建的回文串大于target的结果，因此可以从'a'开始选择；而如果前面选择的字符完全等于target中对应字符，那么当前位置的字符最小也必须是target中对应位置的字符。所以，如果当前选择的是位置indx，且前面已经构建的一半回文串是leftHalf，那么如果leftHalf>target[:indx]，当前位置的字符最小可以是'a'；否则当前位置的字符最小必须是target[indx]
        # 最后确定构造函数的递归基，如果当前构建的位置已经是len(s)//2了，就说明一半回文串已经构造完成，然后我们可以利用前面确定的回文串中间字符middle补全整个回文串palindrom，接着如果palindrom>target，即可返回答案
        n = len(s)
        cnt = Counter(s) # s中各个字符出现次数
        middle = ""
        oddNum = 0
        halfCnt = [0]*26 # 我们在构建一半回文串时各个字符最大可选个数
        for c,v in cnt.items():
            if v&1: # 遇到一个出现次数为奇数的字符
                middle = c # 将其作为回文串中间点
                oddNum += 1
            halfCnt[ord(c)-ord('a')] = v//2
        
        if oddNum > 1: # 不可能构成回文串
            return ""
        
        m = n//2
        leftHalf = ""
        def dfs(indx, isLarger):
            nonlocal leftHalf
            if indx == m:
                palindrom = leftHalf+middle+leftHalf[::-1] # 补全回文串
                return palindrom if palindrom > target else ""
            
            begin = "a" if isLarger else target[indx] # 确定当前位置字符的最小值
            for i in range(ord(begin), ord('z')+1):
                char = chr(i)
                charIndx = i-ord('a')
                if halfCnt[charIndx] <= 0: # 必须在可选的情况下才能继续
                    continue

                leftHalf += char # 维护已构造的一半回文串
                halfCnt[charIndx] -= 1
                curLarger = isLarger or char > target[indx]
                res = dfs(indx+1, curLarger)

                if res:
                    # 如果已经计算出答案，直接返回
                    return res

                leftHalf = leftHalf[:-1] # 恢复现场
                halfCnt[charIndx] += 1
            return ""

        return dfs(0, False)

if __name__ == "__main__":
    sl = Solution()
    s = "baba"
    target = "abba"
    print(sl.lexPalindromicPermutation(s, target))
