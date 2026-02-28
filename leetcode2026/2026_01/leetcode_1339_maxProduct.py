from typing import Optional
from sortedcontainers import SortedList

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        modNum = 1_000_000_007
        tot = set()
        def dfs(node):
            cur = node.val
            if node.left:
                cur = cur+dfs(node.left)
            if node.right:
                cur = cur+dfs(node.right)
            tot.add(cur)
            return cur
        dfs(root)
        tot = SortedList(list(tot))
        indx = tot.bisect_left(tot[-1]//2)
        return max((tot[-1]-tot[indx])*tot[indx], (tot[-1]-tot[indx-1])*tot[indx-1])%modNum

if __name__ == "__main__":
    tot = [1,2,3,4,5,6]
    def build(indx):
        cur = TreeNode(tot[indx])
        if indx*2+1 < len(tot) and tot[indx*2+1]:
            cur.left = build(indx*2+1)
        if indx*2+2 < len(tot) and tot[indx*2+2]:
            cur.right = build(indx*2+2)
        return cur
    root = build(0)
    s = Solution()
    print(s.maxProduct(root))
