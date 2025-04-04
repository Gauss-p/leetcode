class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        # 定义dfs函数，dfs(node,depth)用来求出以节点node为根节点的子树中最深叶节点的深度，其中depth为节点node在树中的深度，为了方便计算，我们用子树中最深空节点的深度表示子树的最大深度，同时为了保存答案，我们需要记录一个全局最大深度，只要当前子树的最大深度等于全局最大深度，就说明全树的最深叶子节点就在当前子树上
        # 接下来，分情况讨论，如果node为空节点，那么更新全局最大深度，同时返回当前深度。如果不是空节点，那么首先求出左子树的最大深度和右子树的最大深度，如果两者相同，说明以node为根节点的子树中的最深叶子节点既在左子树又在右子树，所以此时的最近公共祖先就是node节点，而是否更新答案取决于当前最大深度是否等于全局最大深度
        # 根据定义，调用dfs(root,0)即可，之后返回res即为答案
        res = TreeNode()
        maxDepth = 0
        def dfs(x, depth):
            nonlocal maxDepth, res
            if x is None:
                # 空节点
                maxDepth = max(maxDepth, depth)
                return depth
            # 左右子树的最大深度
            leftMaxDepth = dfs(x.left, depth+1)
            rightMaxDepth = dfs(x.right, depth+1)
            if leftMaxDepth == rightMaxDepth == maxDepth:
                # 更新答案
                res = x
            return max(leftMaxDepth, rightMaxDepth)
        dfs(root, 0)
        return res

if __name__ == "__main__":
    s = Solution()
    root = TreeNode(0, TreeNode(1, None, TreeNode(2, None, None)), TreeNode(3, None, None))
    print(s.lcaDeepestLeaves(root).val)
