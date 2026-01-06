from typing import Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        depth = 1
        res = 0
        maxSum = -float("inf")
        while q:
            cur = 0
            n = len(q)
            for i in range(n):
                curNode = q.popleft()
                cur += curNode.val
                if curNode.left:
                    q.append(curNode.left)
                if curNode.right:
                    q.append(curNode.right)
            if cur > maxSum:
                maxSum = cur
                res = depth
            depth += 1
        return res

if __name__ == "__main__":
    tot = [1,7,0,7,-8,None,None]
    def build(indx):
        cur = TreeNode(tot[indx])
        if indx*2+1 < len(tot) and tot[indx*2+1]:
            cur.left = build(indx*2+1)
        if indx*2+2 < len(tot) and tot[indx*2+2]:
            cur.right = build(indx*2+2)
        return cur
    root = build(0)
    
    s = Solution()
    print(s.maxLevelSum(root))
