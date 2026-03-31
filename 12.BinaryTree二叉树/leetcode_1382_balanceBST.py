from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # 先用中序遍历求出给出的树中的所有节点，注意，中序遍历可以使我们求出来的所有元素是有序的，接下来，根据题目要求，生成的树仍应是一个二叉搜索树，因此我们可以采取以下方式根据有序列表tot生成一个平衡二叉搜索树(假定给出的需要生成的索引区间为[l,r]，两边都包含)：
        #       1.取出[l,r]的中点索引mid，即mid=(l+r)//2，那么我们就可以将这一点作为整个树的根节点，因为此时左侧的所有数都小于tot[mid]，右侧的所有数都大于tot[mid]，我们只需对左右两个区间分别建树，即可得到一个二叉搜索树，这里不需要再特殊处理是否平衡，因为当我们每次都平均分割整个区间后，最终得到的树一定是平衡的
        #       2.若l<mid，即在mid之前还有数字，那么我们就继续传入[l,mid-1]，建左子树
        #       3.若mid<r，即在mid之后还有数字，那么我们就继续传入[mid+1,r]，建右子树
        # 根据上述逻辑，即可构建build递归建树函数
        tot = []
        def dfs(node):
            if node is None:
                return
            dfs(node.left)
            tot.append(node.val)
            dfs(node.right)
        dfs(root)

        def build(l, r):
            mid = (l+r)//2
            cur = TreeNode(tot[mid])
            if mid > l:
                cur.left = build(l, mid-1)
            if mid < r:
                cur.right = build(mid+1, r)
            return cur

        res = build(0, len(tot)-1)
        return res

if __name__ == "__main__":
    tot = [1,None,2,None,3,None,4]
    def build(indx):
        cur = TreeNode(tot[indx])
        if indx*2+1 < len(tot) and tot[indx*2+1]:
            cur.left = build(indx*2+1)
        if indx*2+2 < len(tot) and tot[indx*2+2]:
            cur.right = build(indx*2+2)
        return cur
    root = build(0)
    s = Solution()
    res = s.balanceBST(root)
    print(res.val)
