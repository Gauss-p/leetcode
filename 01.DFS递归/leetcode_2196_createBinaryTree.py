from typing import *
from collections import defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        def init():
            return [-10**18, -10**18]
        root = 0
        cnt = defaultdict(int)
        children = defaultdict(init)
        for p, c, l in descriptions:
            if cnt[p] == 0:
                root ^= p
                cnt[p] = 1
            if cnt[c] == 0:
                root ^= c
                cnt[c] = 1
            if l:
                children[p][0] = c
            else:
                children[p][1] = c
            root ^= c
        
        def dfs(node):
            cur = TreeNode(node)
            if node not in children:
                return cur
            if children[node][0] > -10**18:
                cur.left = dfs(children[node][0])
            if children[node][1] > -10**18:
                cur.right = dfs(children[node][1])
            return cur
        
        return dfs(root)

if __name__ == "__main__":
    s = Solution()
    descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
    res = s.createBinaryTree(descriptions)
    print(res.val)
