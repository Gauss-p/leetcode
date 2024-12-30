from typing import *

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def createTree(self, root, ls, i):
        if i<len(ls):
            if ls[i] == None:
                return None
            else:
                root = TreeNode(ls[i])
                root.left = self.createTree(root.left, ls, 2*i+1)
                root.right= self.createTree(root.right, ls, 2*i+2)
                return root
        return root       

    def dfs(self, x, h):
        if not h:
            return True
        if not x:
            return False
        if x.val != h.val:
            return False
        l = self.dfs(x.left, h.next)
        r = self.dfs(x.right, h.next)
        return (l or r)

    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        if not root:
            return False
        # 因为每一个点都有可能成为树中链表的起点，所以在主函数中还需要一个递归
        return self.dfs(root, head) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)

if __name__ == "__main__":
    s = Solution()
    ls = ListNode(4)
    head = ls
    lst = [2,8]
    for i in lst:
        tmp = ListNode(i)
        ls.next = tmp
        ls = ls.next
    lst2 = [1,4,4,None,2,2,None,1,None,6,8,None,None,None,None,1,3]
    root = s.createTree(None, lst2, 0)
    print(s.isSubPath(head, root))
