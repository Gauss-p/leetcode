from typing import Optional
from collections import defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # 求出以每一个节点为根节点的子树的最大深度，这样就可以得到全局最大深度，然后，对于子树最大深度等于全局最大深度的所有节点，我们对于每一个深度统计位于该深度的节点，当且仅当深度最大且在这个深度中只有一个符合要求的节点被记录时，这个节点就是我们要返回的答案
        dic = defaultdict(list)
        def dfs(node, depth):
            curDepth = depth
            if node.right:
                curDepth = max(curDepth, dfs(node.right, depth+1))
            if node.left:
                curDepth = max(curDepth, dfs(node.left, depth+1))
            dic[curDepth].append((node, depth))
            return curDepth
            
        dfs(root, 0)
        mx = max(dic.keys())
        cnt = defaultdict(list)
        for n, d in dic[mx]:
            cnt[d].append(n)

        maxDepth = -1
        res = None
        for d in cnt.keys():
            if len(cnt[d]) == 1:
                if d > maxDepth:
                    res = cnt[d][0]
                    maxDepth = d
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
    print(s.subtreeWithAllDeepest(root).val)
