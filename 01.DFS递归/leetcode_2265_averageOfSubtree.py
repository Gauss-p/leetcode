class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        def dfs(node):
            curSum = node.val
            cnt = 1
            res = 0
            if node.left:
                nxt = dfs(node.left)
                curSum += nxt[0]
                cnt += nxt[1]
                res += nxt[2]
            if node.right:
                nxt = dfs(node.right)
                curSum += nxt[0]
                cnt += nxt[1]
                res += nxt[2]
            res += (node.val == curSum//cnt)
            return (curSum, cnt, res)
        return dfs(root)[2]

if __name__ == "__main__":
    tot = [4,8,5,0,1,None,6]
    def build(indx):
        cur = TreeNode(tot[indx])
        if indx*2+1 < len(tot) and tot[indx*2+1]:
            cur.left = build(indx*2+1)
        if indx*2+2 < len(tot) and tot[indx*2+2]:
            cur.right = build(indx*2+2)
        return cur
    s = Solution()
    root = build(0)
    print(s.averageOfSubtree(root))
