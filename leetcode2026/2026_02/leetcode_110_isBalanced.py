from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        res = True
        def dfs(node):
            if node is None:
                return 0
            l = dfs(node.left)
            r = dfs(node.right)
            if abs(l-r) > 1:
                nonlocal res
                res = False
            return max(l, r)+1
        dfs(root)
        return res

if __name__ == "__main__":
    tot = [3,5,1,6,2,0,8,None,None,7,4]
    def build(indx):
        cur = TreeNode(tot[indx])
        if indx*2+1 < len(tot) and tot[indx*2+1]:
            cur.left = build(indx*2+1)
        if indx*2+2 < len(tot) and tot[indx*2+2]:
            cur.right = build(indx*2+2)
        return cur
    root = build(0)
    s = Solution()
    print(s.isBalanced(root))
