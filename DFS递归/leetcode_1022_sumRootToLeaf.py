from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def dfs(node, cur):
            if not node.left and not node.right:
                return cur
            res = 0
            if node.left:
                res += dfs(node.left, cur<<1 | node.left.val)
            if node.right:
                res += dfs(node.right, cur<<1 | node.right.val)
            return res
        return dfs(root, root.val)

if __name__ == "__main__":
    s = Solution()
    tot = [1,0,1,0,1,0,1]
    def build(indx):
        cur = TreeNode(tot[indx])
        if indx*2+1 < len(tot) and tot[indx*2+1] != None:
            cur.left = build(indx*2+1)
        if indx*2+2 < len(tot) and tot[indx*2+2] != None:
            cur.right = build(indx*2+2)
        return cur
    root = build(0)
    print(s.sumRootToLeaf(root))
