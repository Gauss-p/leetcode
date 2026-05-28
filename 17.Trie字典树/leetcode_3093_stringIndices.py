from typing import List

class Node:
    def __init__(self):
        self.son = [None]*26
        self.sId = -1
        self.minLength = 10**18

class Solution:
    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        # 本题目要求最长公共后缀，如果将所有单词倒过来处理，即可看作求最长公共前缀，用Trie树解决
        # 首先对于wordsContainer中的每一个单词，都将其加入Trie树中，对于每一个位置，都记录对应的字符串最小长度和它的索引，这样，最后对wordsQuery中的每一个单词查找的时候即可直接找到对应的答案
        # 需要注意的是，整棵树的根节点root虽然理论上不需要保存任何值，但当一个字符串和wordsContainer中的所有字符串都没有公共后缀时，这个字符串就会找到root对应的值。因此，root节点应当保存全局的最小长度和其对应的索引
        root = Node()

        def plug_in(indx):
            word = wordsContainer[indx][::-1]
            curLength = len(word)
            if curLength < root.minLength: # 保证root节点保存全局最小长度
                root.minLength = curLength
                root.sId = indx

            tmp = root
            for c in word:
                cur = ord(c)-ord('a')
                if tmp.son[cur] == None:
                    tmp.son[cur] = Node()
                tmp = tmp.son[cur]
                
                if curLength < tmp.minLength:
                    tmp.minLength = curLength
                    tmp.sId = indx
        
        for i in range(len(wordsContainer)):
            plug_in(i)
        
        def findIndx(indx):
            word = wordsQuery[indx][::-1]
            tmp = root
            for c in word:
                cur = ord(c)-ord('a')
                if tmp.son[cur] == None:
                    break
                tmp = tmp.son[cur]
            return tmp.sId
        
        res = []
        for i in range(len(wordsQuery)):
            res.append(findIndx(i))
        return res

if __name__ == "__main__":
    s = Solution()
    wordsContainer = ["abcd","bcd","xbcd"]
    wordsQuery = ["cd","bcd","xyz"]
    print(s.stringIndices(wordsContainer, wordsQuery))
